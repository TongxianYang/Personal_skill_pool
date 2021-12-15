"=========================================
" VIM configuration
"
" Author : 杨通显
"
" Date : 2021-12-11
"=========================================
"

set enc=utf-8
set nocompatible
source $VIMRUNTIME/vimrc_example.vim

set nobackup

if has('persistent_undo')
  set undofile
  set undodir=~/.vim/undodir
  if !isdirectory(&undodir)
    call mkdir(&undodir, 'p', 0700)
  endif
endif


" 鼠标支持
if has('mouse')
  set mouse-=a
  "if (&term =~ 'xterm' && !has('mac'))
    "set mouse=a
  "else
    "set mouse=nvi
  "endif
endif

set ts=4
set expandtab

" 中文支持
set fileencodings=ucs-bom,utf-8,gb18030,latin1

" 解决Vim旧版本在粘贴时，智能缩进、制表符转换等功能
" 就不会修改粘贴的内容
if !has('patch-8.0.210')
  " 进入插入模式时启用括号粘贴模式
  let &t_SI .= "\<Esc>[?2004h"
  " 退出插入模式时停用括号粘贴模式
  let &t_EI .= "\<Esc>[?2004l"
  " 见到 <Esc>[200~ 就调用 XTermPasteBegin
  inoremap <special> <expr> <Esc>[200~ XTermPasteBegin()

  function! XTermPasteBegin()
    " 设置使用 <Esc>[201~ 关闭粘贴模式
    set pastetoggle=<Esc>[201~
    " 开启粘贴模式
    set paste
    return ""
  endfunction
endif

