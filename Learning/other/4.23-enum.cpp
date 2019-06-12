#include <iostream>

using namespace std;

enum Day{
	Saturday,
	Sunday = 0,
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday
};

void print_day(Day day){
	if (day == 0)
		cout << day << " is Weekends" << endl;
	else
		cout << day << " is Weekdays" << endl;
}

int main(){
	typedef enum Day Date;
	enum Day sat = Saturday;
	print_day(sat);
	Date sun = (Date) 0;
	print_day(sun);
	Date wed = Wednesday;
	print_day(wed);
	Day fri = Friday;
	print_day(fri);

	return 0;
}
