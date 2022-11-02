# 协程



**为什么要有协程 ？**

1、轻量级线程，用户态线程

2、同步编译实现异步性能



**协程到底解决了什么 ？**

以同步的方式享受异步的效果

第一部分执行完 --->  让出CPU --->  第二部分执行



让出CPU的方法：

1、setjmp  /  longjmp

2、ucontext

3、汇编来实现，__asm__ volatile(" ");



异步不同场景

异步IO            AIO,  iocp

io异步操作     检测io与读写io不在一个流程

异步                读写io与处理数据不在一个流程，一般采用reactor + 线程池



**King式四元组**

1、async_init

2、async_deinit

3、async_callback

4、async_commit

这种异步形式实现代码可读性差，难理解