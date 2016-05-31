
#《深入理解C指针》笔记

第一章 认识指针
----------------------------------
### C程序的内存使用形式

| 内存方式 | 作用域 | 生命周期|
| ------------- |:-------------:| -----:|
| 全局内存 | 整个文件 | 应用程序生命周期 |
| 静态内存 | 声明函数内部 | 应用程序生命周期 |
| 自动内存 | 声明函数内部 | 函数执行生命周期 |
| 动态内存 | 由引用该内存的指针决定 | 内存释放（人工） |

> **全局内存**：常见的全局变量
> **静态内存**：静态变量，例如`const int var`
> **自动内存**：常见的就是生命在函数体内的变量了，这是最常见的
> **动态内存**：通过指针创建的堆区域

### 常量与指针

| 指针类型 | 指针是否可修改 | 指针指向数据是否可修改|
| ------------- |:-------------:| -----:|
| 指向非常量的    指针( int * ptr ) | 是 | 是 |
| 指向  常量的    指针( const int * ptr ) | 是 | 否 |
| 指向非常量的常量指针( int * const ptr ) | 否 | 是 |
| 指向  常量的常量指针( const int * const ptr ) | 否 | 否 |

> 阅读指针声明的时候，采取从右往左读的方式。
> 
> `* pci` - pci是个指针
> 
> `int * pci` - pci是个指向整数的指针
> 
> `const int * pci` - pci是个指向整数常量的指针，（指针可变，指针指向区域的整型数据不可变）

* `int const * p`与`const int * p`是等价的。可以按上面那种方式来读取。`const * p`是指向常量的指针,`int const * p`是指向整型常量的指针。
* `int * const p`是与上面不同的，`const p`意味着是常量，`* const p`则是常量指针，`int * const p`是指向整型的常量指针（指针不可变，指针指向区域的整型数据可变）
* 结合上面两种的形式是`const int * const * p`就是指针不可变，指针指向区域的数据也不可变

### 指针多层引用
* 多层指针通常与**多维数组**，**指针数组**等有关联，详细的放到**第四章 数组与指针**中进行详细记录

### 其他
* [指针的语法和语义规范](http://www.open-std.org/JTC1/SC22/WG14/)
* 指针的声明：声明指针时，例如`int * p`，`*`的位置是无所谓的，看个人习惯。
* `&`用来取值，`%p`来显示地址。
* 各平台显示地址方式不一定会一致。通过将要显示的指针转换为void指针来兼容各个平台，例如`print("p%",(void *) p)`
* 通过程序显示的地址均为在操作系统虚拟内存映射下的地址，并非真正的物理地址
* 在取地址和解地址的方面，`*`和`&`是互反的操作
* 在使用指针时，`NULL`和`0`都可以，但是`NULL`更好些，可以告诉开发者在使用指针。
* void指针是通用指针。void指针可以转换为除函数指针外的任何指针。
* `intprt_t`和`uintptr_t`是C99标准为了适应64位环境所新增的。暂时可以不用了解
* 指针相加的实质是按声明类型字节大小进行步增
* 指针相减的实质是两个指针地址相减后，按声明类型字节大小整除后得到的**单位**值，并通过符号老判断地址前后顺序

第三章 函数与指针
----------------------------
### 程序中的栈和堆
* 程序帧是支持函数执行的内存区域，与堆共享内存区域
* 栈在程序帧下部，由下往上增长；堆在上部，由上往下增长
* 栈存放函数参数和局部变量，堆管理动态内存
* 栈帧保存以下元素
    - 返回地址
    - 局部数据存储
    - 参数存储
    - 栈指针和基指针
    
### 函数参数指针传递
* 函数参数传递时，实参传递给形参的是值传递，这会复制实参，不够高效，尤其是传递结构体时，我们不希望再一次复制完全的结构体。而使用指针传递，不但可以改变实参，还能更高效的传递参数。如传递结构体时，传递结构体指针即可，无需其他消耗。
* 如果传递时，使用指向常量的指针，则可以更高效的获取实参内容，而且不会改变实参内容。
#### 传递指针的指针
对于以下代码

```c
void allocateArray(int *arr, int size, int value)
{
    arr=(int *)malloc(size * sizeof(int));
    for(i=0;i<size;++i)
        *(arr+i)=value;
}
int *vector = NULL;
allocateArray(&vector,10,1);
```

会产生问题

1. 首先函数内部虽然将地址传给了`arr`，但是紧接着`arr`的地址被重新通过`malloc`赋值，所以并没有使用`vector`的内容
2. 函数释放后，分配的空间地址丢失，导致内存泄漏

为了解决以上的问题，我们使用指向指针的指针。

| 想改变的实参类型 | 形参形参的形式 |
|:---- :|:---- :|
| int |  int * |
| int * | int ** |

> 1. 当函数改变的实参的值时，而不是形参创建的副本，那么函数传递就要传递实参的地址
> 2. 当函数要改变的是实参本身就是指针，那么函数就要传递指针的地址，也就是函数的形参要定义成指向指针的指针。

所以修改代码


```c
void allocateArray(int **arr, int size, int value)
{
    *arr=(int *)malloc(size * sizeof(int));
    for(i=0;i<size;++i)
        *(*arr+i)=value;
}
int *vector = NULL;
allocateArray(&vector,10,1);
```

这样调用，函数内部分配的内存地址会直接传递给实参`vector`，不会导致地址的丢失等问题

### 函数返回指针
* 声明`int * fcuntion()`即意味着此函数返回的是一个整型指针。`注意与int (*fcuntion)()的区别`
#### 常用的函数返回指针技术
常用的返回指针技术有两种：
* 函数内部使用`malloc`分配内存空间。调用者负责释放内存

```c
int * allocateArray(int size, int value)
{
    int *arr = malloc(size * sizeof(int));
    for(int i=0;i<size;++i)
        *(arr+i)=value;
    return arr;
}
```
然后使用以下方式调用

```c
int *vector = allocateArray(10,1);
for(i=0;i<10;++i)
    printf("%p",*(vector+i));
```

> 最后要注意一定要释放内存，因为函数内部只负责了分配内存，要由调用者负责释放

```c
free(vector);
```

* 函数内部只负责修改传递过来的指针并修改它，内存的分配和释放都有调用者负责。对于传递过来的指针，优先判断是否为空是个好习惯。如下例：

```c
int * allocateArray(int *arr, int size, int value)
{   if(arr != NULL)
    {
        for(int i=0;i<size;++i)
            *(arr+i)=value;
    }
    return arr;
}
```
然后使用以下方式调用

```c
int* vector=(int *)malloc(size * sizeof(int));
allocateArray(vector,10,1);
```
> 书中说此方法不推荐，目前不知道为什么

> **以上两种方式，函数内部使用的内存都是处于堆区域，所以即使函数结束，弹出栈，堆区域的内容仍然存在，只要保留地址即可。但是函数返回指针不要返回函数内部定义的变量，这样函数结束弹出栈帧以后，变量立即消失，这样就出现问题**

#### 函数返回指针注意的问题
函数返回指针要注意四个事项：

1. 返回未初始化的指针
2. 返回指向无效地址的指针
3. 返回局部变量指针
4. 返回指针但是外部调用没有释放

在处理函数返回指针时，一定要根据内存方式注意以上四项。

### 完善的free函数
内置`free()`函数存在以下问题：
1. 不会检查传入指针是否为空
2. 释放后不会将指针置为NULL
这时候可以创建自己的free函数

```c
void safeFree(void **p){
    if(p != NULL && *P != NULL){
        free(*p);
        *p =NULL;
    }
}
```
其中`void指针`意味着可以传入任何指针类型，定义`**p`是因为释放的本身是个指针，需要使用传递指针的指针来真正操作指针。

更快的方式可以定义一个宏
```#define safeFree(p) safeFree(void ** (&p))```
配合`safeFree`函数使用。

### 函数指针
* 函数指针定义的方式就是 `int (*function)()`，这时候`function`就作为一个指针指向了函数的地址。
* 函数指针对性能是有一定影响的，使用它处理器就无法配合流水分支预测
* 正常的函数声明中`int func()`，函数名`func`没有明确定义是指针，还是其他类型。但是对打印函数名`func`的地址，或者函数名取值后`&func`的地址都是同一个值。所以我们只要知道正常的函数声明中，函数名可以等效为该函数的地址。
* 对于函数指针，建议使用`fptr`作为前缀
* 使用了函数指针，使用该指针调用函数，程序将不检查参数传递的是否正确
* 为函数指针声明一个类型定义会比较方便`typedef int (*fptrfunc)(int,int)`
* 函数指针可以实现在函数调用中动态的调用其他函数，实现了函数作为参数的传递，这样可以使用C语言进行函数式编程。个人感觉函数指针是实现C++的某种基础。例如以下代码

```c
typedef int (* fptrOperation)(int ,int);
int sum(int a, int b){ return a+b}
int sub(int a, int b){ return a-b}
int computer(fptrOperation operaton, int num1, int num 2) { return operaton(num1, num2) }

printf("%d\n",computer(sum,1,2));
printf("%d\n",computer(sub,5,3)); 
```

* 返回函数指针即用函数指针去声明一个函数，例`fptrOperation switchcode(char opecode)`
* 当用函数指针去声明一个数组时，那么数组中的每个元素，都代表函数指针指向的一个函数操作，大大增加了函数调用的丰富性。例如

```c
fptrOperation operaton[10]={NULL};
```

第四章 数组与指针
----------------------------
### 数组名的含义
#### 一维数组
对于
```c
int vector[]={1,2,3,4,5}
```
数组名`vector`是**数组首元素**的地址，但是其代表的是整个数组，也就是说`sizeof(vector)`是`5*sizeof(int)`。

>首元素有很多种形式，可能是整型或字符型等基本类型，也可能是数组，也即多维数组

#### 二维数组
对于二维数组：
```c
int matrix[2][5]={
        {1,2,3,4,5},
        {6,7,8,9,10}
    }
```
`matrix`代表首元素`matrix[0]`的地址，而首元素`matrix[0]`是个数组，意味着`matrix[0]`代表内层数组首元素`matrix[0][0]`的地址，所以则有:
`matrix = &matrix[0] , matrix[0] = &matrix[0][0]`
进行解引则有:
`*matrix = matrix[0] = &matrix[0][0]`
`**matrix = *matrix[0] = matrix[0][0]`

* `matrix`的本质是一个5个元素数组的**数组**指针，但其代表的是整个二维数组，也就是其大小为`10*sizeof(int)`
* `matrix[0]`的本质是一个5个元素数组**char**指针，但其代表的是内层一维数组，也就是起大小为`5*sizeof(int)`

>**这里看到`**matrix`，刚开始本人也以为二维指针与二维数组是等价的，后来才发现这个想法是错误的。这里的`**matrix`是解引操作，跟二维指针没有任何关系。**

### 多维数组与多维指针

>* 二维指针对应的是指针数组，二维数组对应的是数组指针
>* `char *pointerArray[]`定义的是`指针数组`
>* `char (*arrayPointer)[]`定义的是`数组指针`
>* 下面两个知识点针对的是静态分配情况。动态分配时，一维指针可以对应一维数组，而二维指针可以对应二维数组。

#### 二维指针与指针数组
对于数组
```c
char *titlesPointerArray[]={
    "A Tale of Two Cities",
    "Wuthering Heights",
    "Don Quixote",
    "Odyssey",
    "Moby-Dick",
    "Hamlet",
    "Gulliver's Travels"
}
```
这里`titlesPointerArray`是一个**指针数组**，`titlesPointerArray`本身是一个指向数组首元素`titlesPointerArray[0]`的指针，即`titlesPointerArray = &titlesPointerArray[0]`。

而`titlesPointerArray[0]`又是一个指向`char`的指针，所以可以看到`titlesPointerArray`是一个**指向字符型指针的指针**，由此可以看到一个**二维指针与指针数组**是对应的。
```c
char *titlesPointerArray[]
char **titlesPointerArray
```
是等价的。这也是为什么在`main`函数中`char **argv`和`char *argv[]`都是可以的。
>二维指针对于处理字符串数组很有好处，动态性能好。可以不用去人为干涉元素数和各字符长度。

#### 二维数组与数组指针
对于数组
```c
char titlesDimensionArray[][40]={
    "The Art of Computer Programming ",
    "Python Programming Guide",
    "Programming Pearl",
    "Computer Network",
    "Modern Perl"
}
```
这里`titlesDimensionArray`是一个**二维数组**。`titlesDimensionArray`本身是一个指向数组首元素`titlesDimensionArray[0]`的指针，即`titlesDimensionArray = &titlesDimensionArray[0]`。

而与指针数组不同的是，`titlesDimensionArray[0]`不再是指向char的指针，而是一个指向`有40个元素数组`的指针。同样，`titlesDimensionArray[0]`代表这40个元素数组的首元素地址，即`titlesDimensionArray[0] = &titlesDimensionArray[0][0]`。所以可以看到`titlesDimensionArray`是一个`指向数组的指针`。由此可以看到一个**二维数组与数组指针**是对应的。
```c
char titlesDimensionArray[][]
char (*titlesDimensionArray)[]
```
是等价的。
>这里终于可以看懂二维数组的实质了。虽然最终引用时都使用解引`**`来获取首个元素内容，但这是不同的。还有就是这种形式跟上面相比要指定内层数组的维数。相对来说更浪费空间，动态性能不好。

### 动态创建数组
鉴于数组与指针相爱相杀，我们还可以使用指针来在**堆**动态的创建数组。最终使用的时候既可以使用指针，也可以使用数组下标方式。
>动态创建的数组由于是在堆上，所以**切记要在最后释放内存**
#### 一维数组
* `int *pv = (int *)malloc(size * sizeof(int))`即动态创建了一个数组pv[size]
* 使用时既可以用pv[0]方式获取内容，也可以使用*(pv+0)来获取内容

##### 使用`realloc`实现变长数组
如果不使用C99标准，那么就不能使用变长数组了，我们只能用`realloc函数`来实现变长数组。

`realloc函数`的核心功能就是用新区域替换旧的区域，这样如果新区域大于旧区域，便可实现空间的扩大，同时返回区域指针。我们可以根据这个思路来实现变长数组。

#### 二维数据
* 既然是二维，为了确定空间大小，我们使用`rows(外层)`和`columns(内层)`的概念来确定整体分配空间大小。总之总大小应该是`sizeof(rows * columns)`
* 使用二维数组定义时，空间是连续分配的，而使用动态分配时，内存可连续，也可能不连续，需要要人为来控制。
* 连续的空间存取速度快，但是空间利用率不高。而动态不连续的内存，空间利用率相对高些。这就是数据结构中静态链表和动态链表的优缺点的本质原因。
* 进行动态分配时，指针维数与数组维数是对应的。

##### 分配可能不连续的内存
[image1](./nostill.gif)
```c
//定义一个二维指针并分配外层(rows)空间
int **matrix = (int **)malloc(rows * sizeof(int *));
for(i=0; i<rows; ++i)
    *(matrix+i) = (int *)malloc(columns * sizeof(int));
```
两层均使用动态进行空间分配，内存区域可能连续，也可能不连续。
##### 分配可能连续的内存
[image2](./still.gif)
```c
//定义一个二维指针并分配外层(rows)空间
int **matrix = (int **)malloc(rows * sizeof(int *));
//在第二层分配时，先一次性规划处整个空间，然后再按行切分
*matrix = (int *)malloc(rows * columns * sizeof(int));
for(i=0; i<rows; ++i)
    *(matrix+i) = (*matrix)+(columns*i);
```
由于分配内层时使用了整体分配，所以空间是连续的，只需要按行切分即可
### 函数中数组的传递
#### 一维数组的传递
在函数参数传递一维数组时，形参可以使用两种方式，以整型为例
`void function(int array[], ...)`，或者
`void function(int *a, ...)`
这两种方式都是可以的，在函数体内部，既可以使用数组形式，也可以使用指针形式。
* 对于实参，必须是`指向整型的指针`,例：
```c
int vector=[]
function(vector, ...)
```
####二维数组的传递
* 对于二维数组的传递，要确定好形参的使用方式，是使用`数组指针（二维数组）`，还是`指针数组（二维指针）`
* 传递二维数组时，一定要对应好形参和实参。
    * 如果形参使用`数组指针（二维数组）`。那么实参必须是一个`指向数组的指针`。
    * 如果形参使用`指针数组（二维指针）`，那么实参必须是一个`指向指针的指针`。

### 其他
* 对多维数组仅可省略最左侧一维的的大小。
* 指针类型与解引操作是不同的
* 二维以上的数组或指针相对难理解，尽量少使用
* *变长数组*的支持和利用*复合字面量(composite literal)*实现*不规则数组和指针*是**C99**新增特性，目前不考虑使用
* 数组和指针还是有区别的。数据名是**右值（常量）**，而使用指针定义的数据，指针是**左值（变量）**
* 求一维数组的大小可以使用`index = sizeof(vector)/sizeof(int)`


第五章 字符串与指针
----------------------------
### 字符串基本
* 字符串有两种定义形式
    - 用字符数组来定义，如`char string[]="Hello Wordl!"`
    - 用指针指向字符串常量来定义`char *string="Hello Wordl!"`
* 不管是用上述那种方法，在字符串的最后都有`\0`以代表字符串结束。
* 计算字符串长度时是不包括`\0`字符的
* 注意`NUL`和`NULL`是不同的，`NUL`代表`\0`，`NULL`的定义是`((void*)0)`
* 不能使用`sizeof`对字符串求取长度
* 字符串字面量不是位于堆区域，也不是栈区域。对于字符串字面量来讲，是没有作用域概念的。
* 在`GCC`中，字符串字面量可以更改，除非将其限制为字符串常量

### 字符串的初始化
目前初始化字符串常用的方法有四种

* __第一种__，初学者最常用的，使用字符数组初始化字符串。
`char string[]="Hello World!"`
每个数组元素保存的就是字符串的每个字符

> 注意，这里字符数组的长度是13，而字符串长度是12.不要忘了最后的`\0`

* __第二种__，使用空数组配合`strcpy`函数将字符串字面量复制到数组

```c
#include <string.h>
char string[13];
strcpy(string,"Hello World!");
```

> 注意，这里定义数组时不能定义成`char string[]`,这样程序无法为数组分配内存

* __第三种__，使用字符指针，在堆中动态分配字符串

```c
#include <string.h>
char *header = (char *)malloc(strlen("Hello World!")+1);
// 或者char *header = (char *)malloc(13);
strcpy(string,"Hello World!");
```
这种是在堆中创建了字面量的副本

* __第四种__，使用字符指针，直接指向字符串字面量
`char *header="Hello World!"`
**这是最简单的方式，推荐**

* __第五种__，通过标准输入获取字符串

```c
char *command;
printf("Enter a Command: ");
scanf("%s",command);
```

### 字符串的内存分布
字符串很有意思的地方就是，它可以以很多种内存形式存在。以下的代码和图片能清晰的概括出**字符串的内存分布情况**

> 为了更好地理解书中的图片，本人自己重新绘制了图片

**代码**

```c
//全局变量，位于全局内存
#include<string.h>
char    *globalHeader = "HELLO WORLD!";
char    globalArray[] = "HELLO WORLD!";
void displayString()
{
    //静态变量，位于全局内存
    static char     *staticHeader = "HELLO WORLD!";
    static char     staticArray[] = "HELLO WORLD!";
    //局部变量，位于自动内存
    char    *localHeader          = "HELLO WORLD!";
    char    localArray[]          = "HELLO WORLD!";
    //动态变量，位于动态内存（堆）
    char *heapHeader              = (char *)malloc(strlen("HELLO WORLD!")+1);
    strcpy(heapHeader,""HELLO WORLD!"")
}
```

**说明图**
![字符串内存分布](CharMemory.jpg)

### 标准字符串操作函数
在C标准库中，定义了对字符串基本操作的函数，而且这些函数经常被使用。这里不再赘述每个函数的意义，函数原型很简单。有什么疑问可以查看标准手册。具体的内容将在代码中体现。

### 传递字符串作为函数的参数
* 传递字符串时，最好以常量的形式进行传递，以防止对实参的修改
* 传递需要初始化的字符串，即想通过一函数来初始化字符串内容，那么需要将字符串指针传递给函数，并返回处理后缓冲区的指针，这里要注意三点：
    - 必须传递缓冲区的地址和长度
    - 调用者负责释放缓冲区
    - 函数通常返回缓冲区的指针

### 返回字符串
返回字符串实际是返回字符串的地址，有三种方式可以返回字符串地址：
* 字面量
    - 字面量没有作用域的概念，所以在函数内将字符串分配于字符串字面量池内，字符串地址不会随着函数结束而变动。
    - 在函数内部定义还可以将字面量赋值给静态变量，这样不但内存区域没有影响，而且可以不用重复使用字符串变量。
* 动态分配的内存
    -  只要将动态分配在堆内的地址返回给调用者，那么字符串的地址也不会丢失。
* 本地字符串变量 - **不要使用！**

### 字符串与函数指针
字符串与函数指针相结合可以实现强大的功能，详细请查看代码。
                                                                       