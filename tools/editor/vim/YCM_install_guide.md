Python3.7安装：

```
./configure --enable-shared --enable-optimizations
make 
make install
```



CMAKE安装：

```
tar xzvf cmake-3.15.3-Linux-x86_64.tar.gz
sudo mv cmake-3.15.3-Linux-x86_64 /usr/share/cmake-3.15
which cmake
sudo ln -sf /usr/share/cmake-3.15/bin/cmake /usr/bin/cmake
cmake --version
```



YouCompleteMe安装：

```
cd ~/.vim/bundle
git clone https://github.com/Valloric/YouCompleteMe.git
cd YouCompleteMe
git submodule update --init --recursive
./install.py --clang-completer
```