# 软件卸载四步法





## 卸载软件包

```
$ sudo apt-get remove
```



## 卸载不需要的依赖关系

```
$ sudo apt-get autoremove
```



## 彻底卸载删除软件相关配置文件

```
$ sudo apt-get purge
```



## 清理安装留下的缓存程序软件包

```
$ sudo apt-get autoclean
$ sudo apt-get clean
```

