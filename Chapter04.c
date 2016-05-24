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
	char titleArray[][30]={
		"A Tale of Two Cities",
		"Wuthering Heights",
		"Don Quixote",
		"Odyssey",
		"Moby-Dick",
		"Hamlet",
		"Gulliver's Travels"
	};
	//对多维数组仅可省略最左侧一维的的大小。
	char **title_ptr  = titles;
	// char **title_pti  = *(titleArray+0);

	printf("%s and %c\n", titles[0], **title_ptr);
	// printf("%s and %c\n", titleArray[0], **title_pti);
	return 0;
}