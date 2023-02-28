# 指定cmake版本安装

## 1.下载cmake
```
wget https://cmake.org/files/v3.15/cmake-3.15.3-Linux-x86_64.tar.gz
```

## 2.解压安装
```
tar -zxvf cmake-3.15.3-Linux-x86_64.tar.gz
vim ~/.bashrc
```
在最后一行添加
```
export PATH=/home/xxx/cmake-3.15.3/bin:$PATH
```

## 3.验证
```
cmake --version
```
查看cmake版本信息

