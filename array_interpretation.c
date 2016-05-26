/*
 * =====================================================================================
 *
 *       Filename:  array_pointer.c
 *
 *    Description:  This is the Chapter 04 learning code
 *
 *        Version:  1.0
 *        Created:  2016年05月26日 16时31分29秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Y.Tian
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
int main ( int argc, const char *argv[] )
{

	printf("Size of Int: %ld\n",sizeof(int));

	printf("================ One Dimension Array ================\n");
	int vector[]={1,2,3,4,5};

	printf("Address of vector array is %p.\nAddress of first element of array is %p.\n", 
		vector, &vector[0]);
	printf("Size of vector is %ld\n", 
		sizeof(vector));

	printf("================ Two Dimension Array ================\n");
	int matrix[2][5]={
		{1,2,3,4,5},
		{6,7,8,9,10}
	};

	printf("Size of matrix: %ld\tAddress of matrix: %p\n",sizeof(matrix),matrix);
	printf("Size of matrix[0]: %ld\tAddress of matrix[0]: %p\n",sizeof(matrix[0]),matrix[0]);
	printf("Size of matrix[0][0]: %ld\tAddress of &matrix[0]: %p\n",sizeof(matrix[0][0]),&matrix[0]);
	
	return EXIT_SUCCESS;
}
