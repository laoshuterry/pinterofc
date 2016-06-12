#ifndef  _PERSON_H
#define  _PERSON_H
#endif

typedef struct _person {
	char *firstName;
	char *lastName;
	char *title;
	unsigned int age;
}Person;

void 	initStructPool();
void 	clearStructPool();

Person 	*getStructPool();
Person 	*setStructPool(Person *);

void 	initializePerson(Person * , const char * , const char * , const char * , unsigned int );
void 	deallocatePerson(Person *);

void 	checkStructPool();
