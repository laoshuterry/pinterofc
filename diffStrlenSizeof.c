/*
 * =====================================================================================
 *
 *       Filename:  diffStrlenSizeof.c
 *
 *    Description:  Discribe the differece between strlen and sizeof
 *
 *        Version:  1.0
 *        Created:  2016年06月02日 23时13分50秒
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
	char str1[20]="0123456789";
	char str2[15]="";
	/*
	这里记得要对str2进行初始化，因为有可能编译器为str2分配了空间，但是空间里存在垃圾值，直接使用会出现错误
	 */
	char *str3="0123456789";

	printf("The strlen of str1 is %lu\n", strlen(str1));
	printf("The sizeof of str1 is %lu\n", sizeof(str1));

	printf("The strlen of str2 is %lu\n", strlen(str2));
	printf("The sizeof of str2 is %lu\n", sizeof(str2));

	printf("The strlen of str3 is %lu\n", strlen(str3));
	printf("The sizeof of str3 is %lu\n", sizeof(str3));

	return 0;
}
