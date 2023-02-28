# ssh-copy-id -i id_rsa.pub yangtongxian@hostname
# 出现 The authenticity of host 'ubuntu (127.0.1.1)' can't be established

```
文件/etv/ssh/ssh_config最后添加:
StrictHostKeyChecking no
UserKnownHostsFile /dev/null
或执行ssh -o StrictHostKeyChecking=no 192.168.0.xxx
内网中非常信任的服务器之间的ssh连接
```


