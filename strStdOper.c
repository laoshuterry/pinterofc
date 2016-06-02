/*
 * =====================================================================================
 *
 *       Filename:  stdStringOper.c
 *
 *    Description:  Example code to show how the standard string library worked
 *
 *        Version:  1.0
 *        Created:  2016年05月31日 17时50分17秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Y.Tian
 *
 * =====================================================================================
 */
#include "TYheader.h"
int main(int argc, char const *argv[])
{
	/*字符串比较函数*/
	printf("============Function of strcmp()============\n");
	char cmd[20];
	printf("Please enter the quit command: ");
	scanf("%s", cmd);
	if (!strcmp(cmd, "Quit"))
		printf("Command is Right!\n");
	else
		printf("Command is Wrong!\n");

	/*字符串复制函数*/
	printf("============Function of strcpy()============\n");
	int count=0;
	char singleWord[10];
	char *wordList[5];

	while( count < 4 )
	{	
		memset(singleWord,0,10);
		printf("Please enter a word: ");
		scanf("%s", singleWord);
		wordList[count] = (char *)malloc(strlen(singleWord)+1);
		strcpy(wordList[count], singleWord);
		++count;
	}

	wordList[4]=wordList[3];

	for ( count = 0; count < 5; ++count )
		printf("The word in the list is: %s\n", wordList[count]);

	/*字符串拼接函数*/
	printf("============Function of strcat()============\n");
	char *error = "Error: ";
	char *errorMessage = "Not enough memory";
	char *buff = (char *)malloc(strlen(error)+strlen(errorMessage)+1);
	strcpy(buff, error);
	strcat(buff, errorMessage);
	
	printf("%s\n", buff);
	printf("%s\n", error);
	printf("%s\n", errorMessage);
	
	return 0;
}
