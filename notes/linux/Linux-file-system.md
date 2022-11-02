# 文件系统

​	Linux上一切兼文件

## 一、文件系统种类

### 1、对磁盘数据做索引

​	fat32、nfs、ext3/ext4、...

### 2、tfs,  gfs,  fastdfs

基于网络的一些远程文件索引

### 3、fuse（内核的一部分）

内核中附加的文件访问时间戳等属性

### 4、vfs （虚拟文件系统）



## 二、系统调用

### 1、触发80中断

int 0x80

__NR_mount

### 2、sys_call_table(, __NR_mount, 4)

file_system_type.mount



## 三、相关结构体

### file_system_type

### super_block

### file / file_operations

### inode / inode_operations

### dentry



## 四、加载文件系统

register_filesystem