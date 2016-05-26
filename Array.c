/*
 * =====================================================================================
 *
 *       Filename:  Array.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016/05/26 10时47分35秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
	int vector[]={1,2,3,4,5};
	int matrix[2][5]={
		{1,2,3,4,5},
		{6,7,8,9,10}
	};
	printf("Size of Int: %ld\n",sizeof(int));
	printf("Size of matrix: %ld\tAddress of matrix: %p\n",sizeof(matrix),matrix);
	printf("Size of matrix[0]: %ld\tAddress of matrix[0]: %p\n",sizeof(matrix[0]),matrix[0]);
	printf("Size of matrix[0]: %ld\tAddress of &matrix[0]: %p\n",sizeof(matrix[0]),&matrix[0]);

	return 0;
}
