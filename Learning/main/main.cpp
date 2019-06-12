#include <iostream>
#include "../heads/string.h"

struct {
	char name[40];
	int age;
}person, person_copy;

int main(){
	char fname[] = "Pierre de ";
	char lname[] = "Fermat";

	/* using memcpy to copy string: */
	//memcpy( person.name, myname, strlen(myname)+1 );
	std::cout << strcmp(lname, fname) << std::endl;
	strcpy(person.name, fname);
	//strcat(person.name, lname);
	strncat(person.name, lname, 4);
	person.age = 46;

	/* using memcpy to copy structure: */
	memcpy( &person_copy, &person, sizeof(person) );

	std::cout << person_copy.name << " " << person_copy.age << std::endl;
	return 0;
}
