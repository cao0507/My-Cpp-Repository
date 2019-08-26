#include<iostream>
#include<vector>
#include<set>

using namespace std;

int find_p(vector<int> &parent, int i)
{
    int r = i;
    while(parent[r] != r)
    {
        r = parent[r];
    }
    int x = i, j;
    while(x != r)
    {
        j = parent[x];
        parent[j] = r;
        x = j; 
    }
    return r;
}

void my_union(vector<int> &parent, int p, int q)
{
    p = find_p(parent, p);
    q = find_p(parent, q);
    if(p != q)
    {
        parent[q] = p;
    }
}

int main()
{
    int N;
    cin >> N; 
    vector<int> parent(N);
    for(int i = 0;i < N;i++)
    {
        parent[i] = i;
    }
    int x;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin>>x;
            if(x >= 3)
            {
                my_union(parent, i, j);             
            }
        }
    }
    set<int> my_set;
    for(int i = 0;i < N; i++)
    {
       	my_set.insert(parent[i]);
    }
    cout << my_set.size() << endl;
}

