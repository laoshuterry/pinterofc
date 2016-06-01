/*
 * =====================================================================================
 *
 *       Filename:  stringMem.c
 *
 *    Description:  Example code to show how the string variables located.
 *
 *        Version:  1.0
 *        Created:  2016年05月31日 17时49分28秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Y.Tian 
 *
 * =====================================================================================
 */
#include "TYheader.h"
 /*全局变量，位于全局内存*/
char	*globalHeader = "Hello World!";
char 	globalArray[] = "Hello World!";

void displayString()
{
	/*静态变量，位于全局内存*/
	static char *staticHeader = "Hello World!";
	static char staticArray[] = "Hello World!";
	/*局部变量，位于自动内存*/
	char *localHeader         = "Hello World!";
	char localArray[]         = "Hello World!";
	/*动态变量，位于动态内存（堆）*/
	char *heapHeader              = (char *)malloc(strlen("Hello World!")+1);
	strcpy(heapHeader,"Hello World!");

	printf("staticHeader string is: %s and the address is:%p\n", staticHeader , staticHeader);
	printf("staticArray string is: %s and the address is:%p\n", staticArray , staticArray);
	printf("localHeader string is: %s and the address is:%p\n", localHeader, localHeader );
	printf("localArray string is: %s and the address is:%p\n", localArray, localArray );
	printf("heapHeader string is: %s and the address is:%p\n", heapHeader, heapHeader );
}

int main(int argc, char const *argv[])
{
	displayString();
	printf("globalHeader string is: %s and the address is:%p\n", globalHeader , globalHeader);
	printf("globalArray string is: %s and the address is:%p\n", globalArray , globalArray);

	return 0;
}