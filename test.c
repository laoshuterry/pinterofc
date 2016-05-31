//全局变量，位于全局内存
char	*globalHeader  = "Hello World!";
char 	globalArray[] = "Hello World!";
void displayString()
{
	//静态变量，位于全局内存
	static char 	*staticHeader  = "Hello World!";
	static char 	staticArray[] = "Hello World!";
	//局部变量，位于自动内存
	char 	*localHeader  = "Hello World!";
	char 	localArray[] = "Hello World!";
	//动态变量，位于动态内存（堆）
	char *heapHeader = (char *)malloc(strlen("Hello World!")+1);
	strcpy(heapHeader,""Hello World!"")
}