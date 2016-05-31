/*
 * =====================================================================================
 *
 *       Filename:  funcpointer.c
 *
 *    Description:  Example to use function pointer.
 *
 *        Version:  1.0
 *        Created:  2016年05月31日 11时01分14秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Y.Tian 
 *         
 * =====================================================================================
 */
#include "TYheader.h"
typedef int (*fptrOperation)(int, int);
int sum(int a, int b) { return a+b; }
int sub(int a, int b) { return a-b; }
int compute(fptrOperation operator, int a, int b) { return operator(a,b); };

int main(int argc, char const *argv[])
{
	int a=5, b=3;
	printf("%d\n", compute(sum, a, b));
	printf("%d\n", compute(sub, a, b));
	return 0;
}
