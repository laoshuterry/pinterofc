/*
 * =============================================================================
 *
 *       Filename:  structBasic.c
 *
 *    Description:  Example code to show 
 *    				how the pointer and structure work together
 *
 *        Version:  1.0
 *        Created:  2016年06月06日 17时25分24秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Y.Tian
 * =============================================================================
 */
#include "TYheader.h"
#include "Person.h"

#define SIZE 10
Person *structPool[SIZE];

void initStructPool()
{
	int i;
	for (i = 0; i < SIZE; ++i)
		structPool[i]=NULL;
}

Person *getStructPool()
{
	int i;
	for (i = 0; i < SIZE; ++i)
	{
		if (structPool[i] != NULL)
		{
			Person *ptr = structPool[i];
			structPool[i] = NULL;
			return ptr;
		}
	}

	Person *newPerson = (Person *)malloc(sizeof(Person));
	return newPerson;
}

Person *setStructPool(Person *person)
{
	int i;
	for (i = 0; i < SIZE; ++i)
	{
		if (structPool[i] == NULL)
		{
			structPool[i] = person;
			return person;
		}
	}

	deallocatePerson(person);
	free(person);
	return NULL;
}

void clearStructPool()
{
	int i;
	for (i = 0; i < SIZE; ++i)
		if(structPool[i]!=NULL)
		{
			deallocatePerson(structPool[i]);
			free(structPool[i]);
			structPool[i] = NULL;
		}
}

void initializePerson(	Person * person, 
			 		const char * fn, 
			 		const char * ln, 
			 		const char * title, 
			 		unsigned int age)
{
	person->firstName =(char *)malloc(strlen(fn)+1);
	person->lastName  =(char *)malloc(strlen(ln)+1);
	person->title     =(char *)malloc(strlen(title)+1);

	strcpy(person->firstName ,fn);	
	strcpy(person->lastName  ,ln);
	strcpy(person->title     ,title);

	person->age       = age;

}

void deallocatePerson(Person *person)
{
	free(person->firstName);	
	free(person->lastName);
	free(person->title);	
}

void checkStructPool()
{
	int i;
	for (i = 0; i < SIZE; ++i)
	{
		if(structPool[i] != NULL)
			printf("Struct Pool's %d Position is not empty\n", i);
		else
			printf("Struct Pool's %d Position is Empty now\n", i );
	}

}

int main ( int argc, char *argv[] )
{
	initStructPool();
	Person *ptrPerson01 = getStructPool();
	Person *ptrPerson02 = getStructPool();
	initializePerson(ptrPerson01, "Tian", "Yu", "Mr", 27);
	initializePerson(ptrPerson02, "Christina", "Lily", "Mrs", 24);

	printf("%s, %s %s's age is %d\n", 
			ptrPerson01->title,
			ptrPerson01->firstName,
			ptrPerson01->lastName,
			ptrPerson01->age );
	printf("%s, %s %s's age is %d\n", 
			ptrPerson02->title,
			ptrPerson02->firstName,
			ptrPerson02->lastName,
			ptrPerson02->age );

	setStructPool(ptrPerson01);
	setStructPool(ptrPerson02);

	ptrPerson01= NULL;
	ptrPerson02= NULL;

	printf("==============Before Clear==============\n");
	checkStructPool();
	clearStructPool();
	printf("==============After Clear==============\n");
	checkStructPool();

	return EXIT_SUCCESS;
}
