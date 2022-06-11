**VIM安装（最新版源码编译安装）**

```text
git clone https://github.com/vim/vim.git
cd vim
./configure --enable-pythoninterp \
            --enable-python3interp \
            --enable-gui=auto
            
make -j
sudo make install
```



**ubuntu-server版本，需要安装以下依赖包**

安装终端ncurse库

```text
sudo apt-get install libncurses5-dev
```

安装终端ncurse库

```text
sudo apt-get install libsm-dev
```

