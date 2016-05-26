/*
 * =====================================================================================
 *
 *       Filename:  dimension_array_pointer.c
 *
 *    Description:  This is the Chapter 04 learning code
 *    				This file shows how the difference between two dimension
 *    				pointers and array
 *
 *        Version:  1.0
 *        Created:  2016年05月26日 17时44分53秒
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
	printf("================ Two Dimension Pointer and Pointer's Array================\n");
	
	/*Pointer's Array*/
	char *titlesPointerArray[]={
		"A Tale of Two Cities",
		"Wuthering Heights",
		"Don Quixote",
		"Odyssey",
		"Moby-Dick",
		"Hamlet",
		"Gulliver's Travels"
	};
	/*2D Pointer*/
	char **dimensionPointer; 
	dimensionPointer = titlesPointerArray;
	printf("%s and %c\n", titlesPointerArray[0], **dimensionPointer);


	printf("================ Two Dimension Array and Array's Pointer================\n");
	/*2D Array*/
	char titlesDimensionArray[][40]={
		"The Art of Computer Programming ",
		"Python Programming Guide",
		"Programming Pearl",
		"Computer Network",
		"Modern Perl"
	};
	/*Array's Pointer*/
	char (*arrayPointer)[40];
  	arrayPointer = titlesDimensionArray;
	printf("%s and %c\n", titlesDimensionArray[0], **arrayPointer);
	
	return EXIT_SUCCESS;
}
