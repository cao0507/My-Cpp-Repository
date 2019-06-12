# Attack and Speed

> Time limit: *1000 ms*
> Memory limit: *128 MB*

[Attack and Speed](https://csacademy.com/contest/archive/task/attack-and-speed/)

You are playing a game where your character has two main characteristics : attack and speed. Your current attack level is AA and the current speed level is SS.  

You also have KK dollars. Each dollar can be used to either increase the attack by XX, or the speed by YY. Your goal is to spend all the dollars and bring the attack and speed at the same level. 

## Standard input 

The first line contains 55 integers AA, SS, KK, XX, YY. 

## Standard output 

If you can achieve the goal, print a single integer representing the number of dollars you spend to increase the **attack** level. 

If there is no solution, output -1−1. 

## Constraints and notes 

- 1 \leq A, S, K, X, Y \leq 10^91≤A,S,K,X,Y≤109  
- You are required to spend all the money 

| Input            | Output | Explanation                                                  |
| ---------------- | ------ | ------------------------------------------------------------ |
| `14 12 6 3 2 `   | `2 `   | For Attack, using 22 dollars 14 + 2 * 3 = 2014+2∗3=20 For Speed, using the remaining 44 dollars 12 + 4 * 2 = 2012+4∗2=20 |
| `12 46 17 11 6 ` | `8 `   | For Attack, using 88 dollars 12 + 8 * 11 = 10012+8∗11=100 For Speed, using the remaining 99 dollars 46 + 9 * 6 = 10046+9∗6=100 |
| `46 12 17 9 8 `  | `6 `   | For Attack, using 66 dollars 46 + 6 * 9 = 10046+6∗9=100 For Speed, using the remaining 1111 dollars 12 + 11 * 8 = 10012+11∗8=100 |
| `53 31 17 9 8 `  | `-1 `  | You **need** to spend all KK dollars. It's possible to make Attack and Speed equal using 77 dollars, but you **can't** do that with 1717 dollars. |

---

## Solution

```c++
#include <iostream>

using namespace std;

int main() {
    long A, S, K, X, Y;
    cin >> A >> S >> K >> X >> Y;
    long lo = 0, hi = K, mid;
    while (lo < hi){
        mid = lo + (hi-lo)/2;
        if (A + mid*X < S + (K-mid)*Y)
            lo = mid+1;
        else if (A + mid*X > S + (K-mid)*Y)
            hi = mid;
        else{
            cout << mid <<endl;
            return 0;
        }
    }
    if (A + lo*X == S + (K-lo)*Y){
        cout<< lo <<endl;
        return 0;
    }
    cout << -1 <<endl;
    return 0;
    
}
```

