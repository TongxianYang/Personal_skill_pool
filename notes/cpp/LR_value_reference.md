# 左值与右值引用



## 一、引用

别名，声明时必须初始化，通过引用修改变量值



## 二、区别



#### 定义

左值引用：对左值的引用

右值引用：对右值的引用



const 左值引用能指向右：局限不能修改这个值；

右值引用通过std::move(v)可以指向左值；

声明出来的左值引用或右值引用都是左值；



#### 功能

左值引用：避免对象拷贝（函数传参、函数返回值）；

右值引用：实现移动语义和完美转发。



###### 实现移动语义

对象赋值时，避免资源的重新分配；

移动构造与移动拷贝构造；

stl应用；

std::unique_ptr；

...



###### 实现完美转发

函数模板可以将自己的参数完美地转发给内部调用的其他函数；

完美是指不仅能准确地转发参数的值，还能保证被转发的参数的左右值属性不变；

借用万能引用，通过引用的方式接收左右属性的值；

引用折叠规则，参数为左值或左值引用，T&&将转化为int &，参数为右值或右值引用，T&&将转化为int &&；

std::forward<T>(v)， T为左值引用，v将转化为T类型的左值， T为右值引用，v将转化为T类型的右值。 



## 三、区分左/右值



#### 左值

可以在 “=” 左边，能够取地址，具名。

举例：变量名、返回左值引用的函数调用、前置自增/自减、赋值运算或符合赋值运算、解引用等。



#### 右值

只能在 “=” 右边， 不能取地址，不具名。

举例：纯右值、将亡值



###### 纯右值

字面值

返回非引用类型的函数调用

后置自增/自减

算术表达式

逻辑表达式

比较表达式

...



###### 将亡值

C++11新引入的与右值引用（移动语义）相关的值类型

将亡值用来触发移动构造或移动赋值构造，并进行资源转移，之后将调用析构函数。
