/*
 * =====================================================================================
 *
 *       Filename:  var_length_array.c
 *
 *    Description:  Dymanic allocate the Array length
 *
 *        Version:  1.0
 *        Created:  2016年05月26日 19时49分33秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Y.Tian
*/
#include <stdio.h>
#include <stdlib.h>

char* getLine(void) {
	/*每次步增值*/
	const size_t sizeIncrement = 10;
	/*每次工作的区域大小，初始时为sizeIncrement大小*/
	char* buffer               = malloc(sizeIncrement);
	/*指向缓冲区位置的指针，随输入字节进行移动*/
	char* currentPosition      = buffer;
	/*区域最大的值，初始时为初始时为sizeIncrement大小 */
	size_t maximumLength       = sizeIncrement;
	size_t length              = 0;
	int character;

	while(1) {
		character = fgetc(stdin);
		if(character == '\n')
			break;
		if(++length >= maximumLength) {
			char *newBuffer = realloc(buffer, maximumLength += sizeIncrement);
			if(newBuffer == NULL) {
				free(buffer);
				return NULL;
			}
			currentPosition = newBuffer + (currentPosition - buffer);
			buffer = newBuffer;
		}
		*currentPosition++ = character;
	}
	*currentPosition = '\0';
	return buffer;
}

int main(int argc , char *argv[])
{
	char *charactor =getLine();
	printf("%s\n", charactor);
	return 0;
}

