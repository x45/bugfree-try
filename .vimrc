" All system-wide defaults are set in $VIMRUNTIME/debian.vim (usually just
" /usr/share/vim/vimcurrent/debian.vim) and sourced by the call to :runtime
" you can find below.  If you wish to change any of those settings, you should
" do it in this file (/etc/vim/vimrc), since debian.vim will be overwritten
" everytime an upgrade of the vim packages is performed.  It is recommended to
" make changes after sourcing debian.vim since it alters the value of the
" 'compatible' option.

" This line should not be removed as it ensures that various options are
" properly set to work with the Vim-related packages available in Debian.
runtime! debian.vim

" Uncomment the next line to make Vim more Vi-compatible
" NOTE: debian.vim sets 'nocompatible'.  Setting 'compatible' changes numerous
" options, so any other options should be set AFTER setting 'compatible'.
"set compatible
filetype plugin on
filetype indent on
let Tlist_Use_Right_Window   = 1 " Show Ttag on the right

" With a map leader it's possible to do extra key combinations
" like <leader>w saves the current file

let mapleader = ","
let g:mapleader = ","

" Fast saving
nmap <leader>w :w!<cr>

" Vim5 and later versions support syntax highlighting. Uncommenting the next
" line enables syntax highlighting by default.
syntax on

" If using a dark background within the editing area and syntax highlighting
" turn on this option as well
set background=dark

" Uncomment the following to have Vim jump to the last position when
" reopening a file
if has("autocmd")
  au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif
endif

" Uncomment the following to have Vim load indentation rules and plugins
" according to the detected filetype.
if has("autocmd")
  au FileType helpfile set nonumber  	
  filetype plugin indent on
endif


autocmd bufnewfile *.sh so /home/nnm/Bureau/programmation/c/learn/sh_header.txt
autocmd bufwritepost,filewritepost *.sh execute "normal `a"
autocmd bufnewfile *.sh exe "1," . 10 . "g/ft.c\+*/s//" .expand("%").""
autocmd bufnewfile *.sh exe "1," . 10 . "g/Created: +*/s//Created: " .strftime('%Y\/%m\/%d %H:%M:%S').""
autocmd bufnewfile *.sh exe "1," . 10 . "g/Updated: /s/Updated: /Updated: " .strftime('%Y\/%m\/%d %H:%M:%S'). ""
autocmd Bufwritepre,filewritepre *.sh exe "1," . 10 . "g/Updated: /s/Updated: .+*.+*.+*.+*.+*.+*.+*.+*.+*.+*.+*.+*.+*.+*.+*.+*.+*.+*.+*/Updated: " .strftime('%Y\/%m\/%d %H:%M:%S'). ""

autocmd bufnewfile *.c so /home/nnm/Bureau/programmation/c/learn/c_header.txt
autocmd bufwritepost,filewritepost *.c execute "normal `a"
autocmd bufnewfile *.c exe "1," . 10 . "g/ft.c\+*/s//" .expand("%").""
autocmd bufnewfile *.c exe "1," . 10 . "g/Created: +*/s//Created: " .strftime('%Y\/%m\/%d %H:%M:%S').""
autocmd bufnewfile *.c exe "1," . 10 . "g/Updated: /s/Updated: /Updated: " .strftime('%Y\/%m\/%d %H:%M:%S'). ""
autocmd Bufwritepre,filewritepre *.c exe "1," . 10 . "g/Updated: /s/Updated: .+*.+*.+*.+*.+*.+*.+*.+*.+*.+*.+*.+*.+*.+*.+*.+*.+*.+*.+*/Updated: " .strftime('%Y\/%m\/%d %H:%M:%S'). ""


" The following are commented out as they cause vim to behave a lot
" differently from regular Vi. They are highly recommended though.
set showcmd			" Show (partial) command in status line.
set number          " Show lines numbers
set ttyfast         " smoother changes
set ai              " auto indent
"set expandtab       " use space instead of tabs
set si              " smart indent 
set smarttab	    " Be smart when using tabs 
set tabstop=4       " numbers of spaces of tab character
set ls=2            " always show status line  
" Show when a line exceeds 80 chars
:au BufWinEnter * let w:m1=matchadd('ErrorMsg', '\%>80v.\+', -1)
set shiftwidth=4    " numbers of spaces to (auto)indent
set showmatch		" Show matching brackets.
"set ignorecase		" Do case insensitive matching
"set case		" Do smart case matching
"set incsearch		" Incremental search
"set autowrite		" Automatically save before commands like :next and :make
"set hidden             " Hide buffers when they are abandoned
set list
set mouse=a		" Enable mouse usage (all modes)
set listchars=nbsp:¤,tab:>-,trail:¤,extends:>,precedes:<,eol:¶,trail:·

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => VIM user interface
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Set 7 lines to the cursor - when moving vertically using j/k
set so=7

" Turn on the WiLd menu
set wildmenu

" Ignore compiled files
set wildignore=*.o,*~,*.pyc

"Always show current position
set ruler

" Height of the command bar
set cmdheight=2

" A buffer becomes hidden when it is abandoned
set hid

" Configure backspace so it acts as it should act
set backspace=eol,start,indent
set whichwrap+=<,>,h,l

" Ignore case when searching
set ignorecase

" When searching try to be smart about cases 
set smartcase

" Highlight search results
set hlsearch

" Makes search act like search in modern browsers
set incsearch

" Don't redraw while executing macros (good performance config)
set lazyredraw

" For regular expressions turn magic on
set magic

" Show matching brackets when text indicator is over them
set showmatch
" How many tenths of a second to blink when matching brackets
set mat=2

" No annoying sound on errors
set noerrorbells
set novisualbell
set t_vb=
set tm=500


"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => Colors and Fonts
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Enable syntax highlighting
syntax enable

colorscheme desert
set background=dark

" Set extra options when running in GUI mode
if has("gui_running")
    set guioptions-=T
    set guioptions+=e
    set t_Co=256
    set guitablabel=%M\ %t
endif

" Set utf8 as standard encoding and en_US as the standard language
set encoding=utf8

" Use Unix as the standard file type
set ffs=unix,dos,mac

