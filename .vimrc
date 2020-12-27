so ~/.vim/plugins.vim
filetype on
filetype indent on
syntax enable
autocmd BufNewFile *.cpp execute "0r ~/.vim/template/".input("Template name: ").".cpp"
map <F9> :!g++ -std=c++17 -g % -o %:r && ./%:r <CR>
map <F5> :!g++ -std=c++17 -g % -o %:r <CR>
map <F12> :!gdb ./%:r <CR>
imap <F1> <Esc>
map <F1> <Esc>
inoremap <F1> <Esc>
map <F2> <Esc> :w <CR>
map <C-a> gg v G
map <C-c> "+y
map <C-h> :.,$s/min//g
" map <C-_> :s/^/\/\//<Enter>
" map <C-u> :s/^\/\///<Enter>
nmap <C-_>   <Plug>NERDCommenterToggle
vmap <C-_>   <Plug>NERDCommenterToggle<CR>gv
let &t_TI = ""
let &t_TE = ""
set whichwrap+=<,>,[,],l,h
set number
set sw=4
set showtabline=2
set tabstop=4
set shiftwidth=4
if (empty($TMUX))
  if (has("nvim"))
  let $NVIM_TUI_ENABLE_TRUE_COLOR=1
  endif
  if (has("termguicolors"))
    set termguicolors
  endif
endif

set autoindent
set mouse=a
set background=light " for the dark version
" set background=light " for the light version
colorscheme molokai

