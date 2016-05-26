#include <stdio.h>
int main(int argc, char const *argv[])
{
	char *titles[]={
		"A Tale of Two Cities",
		"Wuthering Heights",
		"Don Quixote",
		"Odyssey",
		"Moby-Dick",
		"Hamlet",
		"Gulliver's Travels"
	};
	char titleArray[7][30]={
		"A Tale of Two Cities",
		"Wuthering Heights",
		"Don Quixote",
		"Odyssey",
		"Moby-Dick",
		"Hamlet",
		"Gulliver's Travels"
	};
	//对多维数组仅可省略最左侧一维的的大小。
	//指针类型与接引操作是不同的
	//二维指针对应的是指针数组，二维数组对应的是数组指针

	//二维数组中
	//int matrix[5][5],matrix代表首元素matrix[0]地址，而首元素matrix[0]是个数组，
	//意味着matrix[0]代表内层数组首元素matrix[0][0]的地址，所以则有
	//matrix=&matrix[0],matrix[0]=&matrix[0][0],进行解引则有
	//*matrix=matrix[0]=&matrix[0][0]
	//**matrix=*matrix[0]=matrix[0][0]
	
	//matrix的本质是一个5个元素数组的**数组**指针，但其代表的是整个二维数组，也就是其大小为25*int
	//matrix[0]的本质是一个5个元素数组**char**指针，但其代表的是内层一维数组，也就是起大小为5*int
	
	
	char **title_ptr; 
	char (*title_pti)[30];
	title_ptr = titles;
  	title_pti = titleArray;

	printf("%s and %c\n", titles[0], **title_ptr);
	printf("%s and %c\n", titleArray[0], **title_pti);
	return 0;
}
