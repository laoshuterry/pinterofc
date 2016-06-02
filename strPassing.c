/*
 * =====================================================================================
 *
 *       Filename:  passingStr.c
 *
 *    Description:  Example code to show how passing the string to function.
 *
 *        Version:  1.0
 *        Created:  2016年05月31日 17时51分03秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Y.Tian
 *
 * =====================================================================================
 */
#include "TYheader.h"
int charLength(const char *s)
{
	int length=0;
	while(*(s++)) length++;
	return length;
}
char *format(char *buff, size_t size, char *name, int qunt, int weight )
{
	char *formatString = "Name: %s\tQuantity: %d\tWeight: %d\n";
	snprintf(buff, size, formatString, name, qunt, weight);
	return buff;
}
int main(int argc, char const *argv[])
{
	if(argc<2) 
	{
		printf("Less arguments!\n");
		return 1;
	}
	printf("============Application arguments============\n");
	int i;
	for(i=0; i<argc; ++i)
		printf("%s\t",*(argv+i));
	printf("\n");

	printf("============Passing simple string to function============\n");
	const char *firstString=argv[1];
	const char *secondString=argv[2];

	printf("The length of first is %d\n", charLength(firstString) );
	printf("The length of second is %d\n", charLength(secondString) );
	printf("============Passing string to a format function============\n");
	char strBuff[100];
	printf("%s\n", 
			format(strBuff, sizeof(strBuff), "Alice", 25, 34));
	return 0;
}