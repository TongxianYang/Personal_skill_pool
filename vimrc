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
  " set mouse-=a
  if (&term =~ 'xterm' && !has('mac'))
    set mouse=a
  else
    set mouse=nvi
  endif
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

" 打开已被另个会话打开的文件时，图形界面会自动切换那个会话
if v:version >= 800
  packadd! editexisting
endif

" 多窗口切换键映射设置(正常模式和插入模式一样)
nnoremap <C-Tab>   <C-W>w
inoremap <C-Tab>   <C-O><C-W>w
nnoremap <C-S-Tab> <C-W>W
inoremap <C-S-Tab> <C-O><C-W>W

" Home键切换光标位置(行首与行中第1个非空白字符位置)
function! GoToFirstNonBlankOrFirstColumn()
  let cur_col = col('.')
  normal! ^
  if cur_col != 1 && cur_col == col('.')
    normal! 0
  endif
  return ''
endfunction
nnoremap <silent> <Home> :call GoToFirstNonBlankOrFirstColumn()<CR>
inoremap <silent> <Home> <C-R>=GoToFirstNonBlankOrFirstColumn()<CR>

" 自动关闭最后一个quickfix窗口
aug QFClose
  au!
  au WinEnter * if winnr('$') == 1 && &buftype == "quickfix"|q|endif
aug END
