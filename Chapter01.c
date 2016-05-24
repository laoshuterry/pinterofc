#include <stdio.h>
int main(int argc, char const *argv[])
{
	int num      = 5;
	int *pi      = &num;

	printf("Address of num: %p Value %d\n",&num, num );
	printf("Address of pi : %p Value %p\n",&pi, pi);
	printf("The pointer length is %ld, and void pointer length is %ld\n",sizeof(char *), sizeof(void *));

	return 0;
}