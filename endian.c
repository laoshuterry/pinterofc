/*
 * =====================================================================================
 *
 *       Filename:  endian.c
 *
 *    Description:  Example to show whether the machine is
 *    				big-endian or little-endian 
 *
 *        Version:  1.0
 *        Created:  2016年06月13日 17时56分43秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Y.Tian
 * =====================================================================================
 */
#include "TYheader.h"
int main(int argc, char const *argv[])
{
	int num = 0x12345678;
	char *adr = (char *)&num;
	int i;
	for (i = 0; i < 4; ++i)
		printf("%p: %02x\n",adr+i,(unsigned char )*(adr+i));
	return 0;
}