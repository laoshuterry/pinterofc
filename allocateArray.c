/*
 * =====================================================================================
 *
 *       Filename:  allocateArray.c
 *
 *    Description:  Learn how to use function returning pointer through
 *    				allocate Arrays
 *
 *        Version:  1.0
 *        Created:  2016年05月31日 10时23分58秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Y.Tian
 * =====================================================================================
 */
#include "TYheader.h"
int *allocateArray_1(int size, int value)
{
	int *arr = (int *)malloc(size * sizeof(int));
	int i;
	for (i = 0; i < size; ++i)
		*(arr+i) = value;

	return arr;
}
int *allocateArray_2(int *arr, int size, int value)
{
	int i;
	if(arr != NULL)
	{
		for (i = 0; i < size; ++i)
			*(arr+i) = value;
	}
	return arr;
}
void allocateArray_3(int **arr, int size, int value)
{
	*arr= (int *)malloc(size * sizeof(int));
	int i;
	for (i = 0; i < size; ++i)
		*(*arr+i) = value;
}
int main(int argc, char **argv)
{
	int i;
	/* vector01要负责释放内存*/
	int *vector01=allocateArray_1(10,1);
	/* vector02负责内存的分配与释放*/
	int *vector02 = (int *)malloc(10 * sizeof(int));
	allocateArray_2(vector02,10,2);
	/* vector03由函数内部分配，由调用者负责释放*/
	int *vector03=NULL;
	allocateArray_3(&vector03,10,3);

	printf("Vector01\tVector02\tVector03\n");
	for(i=0; i<10; ++i){
		printf("%d",*(vector01+i));
		printf("\t\t");
		printf("%d",*(vector02+i));
		printf("\t\t");
		printf("%d",*(vector03+i));
		printf("\n");
	}

	free(vector01);
	free(vector02);
	free(vector03);
	return 0;
}
