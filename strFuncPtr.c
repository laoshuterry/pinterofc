/*
 * =====================================================================================
 *
 *       Filename:  strFuncPtr.c
 *
 *    Description:  A little complex code to show how the function pointer work
 *    				with strings.

 *        Version:  1.0
 *        Created:  2016年05月31日 17时52分38秒 
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Y.Tian
 *
 * =====================================================================================
 */
#include "TYheader.h"
char *stringToLower(const char * string)
{
	char *tmp   = (char *)malloc(strlen(string)+1);
	char *start =tmp;
	int i=0;
	while(string[i] != '\0')
	{
		tmp[i] = tolower(string[i]);
		++i;
	}
	tmp[i]='\0'; 
	
	return start;
}
int CompareUnsensitive(const char *s1, const char *s2)
{
	int result = strcmp(s1,s2);
	return result;
}
int CompareSensitive(const char *s1, const char *s2)
{
	char *t1   = stringToLower(s1);
	char *t2   = stringToLower(s2);
	
	int result = strcmp(t1,t2);
	free(t1);free(t2);

	return result;
}
typedef int (*fptrCompare)(const char*, const char*);

void sort(char **argv, int size, fptrCompare operation)
{
	int flag=1;
	int i;
	while(flag)
	{
		flag=0;
		for(i=0; i<size-1; ++i)
			if(operation(argv[i],argv[i+1])>0)
			{
				flag=1;
				char *temp = argv[i];
				argv[i]= argv[i+1];
				argv[i+1]=temp;
			}
	}
}

void display(char **argv, int size)
{
	int i=0;
	for(i=0; i<size; ++i)
		printf("%s\n", *(argv+i));
}
int main(int argc, char const *argv[])
{
	char *titlesPointerArray[]={
		"A Tale of Two Cities",
		"Wuthering Heights",
		"Don Quixote",
		"Odyssey",
		"Moby-Dick",
		"Hamlet",
		"Gulliver's Travels"
	};

	int index=sizeof(titlesPointerArray)/sizeof(char *);

	sort(titlesPointerArray, index, CompareSensitive );
	display(titlesPointerArray, index);

	return 0;
}