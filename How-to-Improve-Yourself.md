# 从几个维度提升自己



## 1、数据结构、算法、以及设计模式

用于排序：跳表、红黑树

定时器：红黑树、时间轮

设计模式：

(1)、责任链模式

(2)、过滤器

(3)、观察者

(4)、代理

(5)、单例

(6)、工厂模式



## 2、中间件

数据库 （mysql 、redis、mongodb）



## 3、网络IO

(1)、网络模型:  select, poll,  epoll

(2)、同步 与 异步

​          协程解决同步非阻塞  （发送命令并挂起协程，接收回应唤醒协程， 并返回内容）

(3)、阻塞 与 非阻塞

(4)、Reactor，proactor，epoll  管理网络IO以事件的方式处理，回调用来实现网络io



## 4、Linux系统下开发

(1)、系统：iostat，uptime

(2)、编辑：vim，grep ，awk，sed

(3)、网络：netstat，tcpdump

(4)、磁盘：umount，dd

(5)、日志：tail，multitail

(6)、shell脚本



## 5、开源框架

(1)、协议：protobuffer，messagepack， thrift，flatbuffer

(2)、压缩：zlib，snappy

(3)、加密：xxtea++，openssl tls

(4)、libevent，libuv

(5)、日志，追踪错误   log4cpp  boost.log

(6)、长连接框架skynet

(7)、协程：libco，ntyco



## 6、代码工程化

(1)、makefile  cmake   autoconf

(2)、版本管理  git



## 6、性能测试

(1)、发现：luatest    gtest

(2)、解决：boost.test

(3)、性能：webbench wrk