/*
 * =====================================================================================
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
 * =====================================================================================
 */
#include "TYheader.h"
#include "Person.h"
int main ( int argc, char *argv[] )
{
	Person *ptrPerson = (Person *)malloc(sizeof(Person));

	return EXIT_SUCCESS;
}
