
# GIT

常用操作速查

## 克隆仓库代码
git clone / git clone --bare

## 工作区添加暂存区
git add

## 暂存区提交commit
git commit -m

## 同步远程仓库
git pull

## 提交到远程仓库
git push

## 删除文件
git rm

## 重命名文件
git rename

## 查看日志
git log

## 分离头指针
git checkout commit_id

## 暂存区与HEAD比较差异
git diff --cached

## 工作区与暂存区比较差异
git diff

## 暂存区恢复为HEAD
git reset HEAD (所有)
git reset file (指定)

## 工作区恢复为暂存区
git checkout .		(所有)
git checkout file	(指定)

## 分支切换
git checkout branch_name

## 分支增/删
git branch branch_name
git branch rm branch_name

## 版本回退到指定的commit
git reset --hard commit_id

## 分支比较差异
git diff branch1 branch2

## 工作区临时修改保存
git stash 		(保存stash)
git stash list 	(查看stash)
git stash apply (恢复不删除stash)
git stash pop 	(恢复删除stash)

