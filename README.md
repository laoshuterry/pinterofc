
#《深入理解C指针》笔记
这里是我在学习《深入理解C指针》时所写的代码。由于书中给出的代码都是单独的片段，而原书并没有提供完整的源代码，因此本人按照书中的理解自己编写了样例代码。

这些代码无论从内容还是组织方式都显得比较粗糙，由于写这些代码主要是为了理解概念，所以对于程序的严谨和组织都没有过多的在意，加之本人目前对Makefile还不是很熟悉，所以也没有很好的整理代码。在以后我会慢慢完善的。

本人在学习时还做了详细的笔记。之前是把笔记放在READEME文档里，但是后来发现内容过多，所以单独整理了出来放到了[`Gitbook`](https://laoshuterry.gitbooks.io/noteofcpointer/content/)上，有需要的朋友可以去看看。

> 因为是个人的笔记，所以有些内容别人去看可能不是很清楚，如果有什么疑问，欢迎交流。

## 代码列表

*　`structBasic.c` - 结构体与指针的基本概念
*　`ploy.c` - 利用C指针模拟面向对象中多态技术
*　`strFuncPtr.c` - 利用返回指针的函数处理字符串
*　`strMem.c` - 字符串内存分布形式
*　`strStdOper.c` - 字符串标准库操作
*　`allocateArray.c` - 利用返回指针的函数动态创建数组
*　`dimension_array_pointer.c` - 多维数组与多维指针的关系
*　`strPassing.c` - 字符串作为参数进行传递的演示
*　`var_length_array.c` - 利用`realloc`模拟变长数组
*　`strReturn.c` - 利用字符串理解返回指针的函数
*　`array_interpretation.c` - 各种数组表达方式的含义与地址的联系
*　`diffStrlenSizeof.c` - `sizeof`和`strlen`的区别
*　`funcpointer.c` - 函数指针的使用
*　`endian.c` - 利用类型转换判断机器大小端模式
*　`intro_ptr.c` - 指针基本概念

