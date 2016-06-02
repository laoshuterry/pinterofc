/*
 * =====================================================================================
 *
 *       Filename:  strReturn.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年05月31日 17时52分21秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Y.Tian
 *
 * =====================================================================================
 */
#include "TYheader.h"
char * strReturnStrLiter(int code)
{
	static char * wrongCode = "Wrong Code!";
	static char * bpCenter = "Boston Processing Center";
	static char * dpCenter = "Denver Processing Center";
	static char * apCenter = "Atlanta Processing Center";
	static char * cpCenter = "San Jose Processing Center";

	switch(code)
	{
		case 100: return apCenter;
		case 200: return bpCenter;
		case 300: return cpCenter;
		case 400: return dpCenter;
		default:  return wrongCode;
	}
}
char * strReturnDynamic(int size)
{
	char * str = (char *)malloc(size+1);
	int i;
	for(i=0; i<size; ++i)
		*(str+i)='a';
	*(str+size)='\0';

	return str;
}
int main(int argc, char const *argv[])
{
	printf("%s\n", strReturnStrLiter(200));

	char * str1=strReturnDynamic(5);
	char * str2=strReturnDynamic(10);

	printf("%s\n", str1);
	printf("%s\n", str2);

	free(str1);
	free(str2);
	return 0;
}
