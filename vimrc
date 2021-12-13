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

