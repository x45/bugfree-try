###############################
## zsh config file ~/.zshrc ##
##       arpinux@2013       ##
##############################
#─ │ ┌ ┐ └ ┘ ├ ┤ ┬ ┴ ┼

## variables -----------------------------------------------------------
export BROWSER="conkeror"
export EDITOR="vim"
export PAGER="most"

# text normal colors
red='\e[0;31m'
blue='\e[0;34m'
cyan='\e[0;36m'
green='\e[0;32m'
yellow='\e[0;33m'

# text bright colors
bred='\e[0;91m'
bblue='\e[0;94m'
bcyan='\e[0;96m'
bgreen='\e[0;92m'
byellow='\e[0;93m'
bwhite='\e[0;97m'

# reset color
NC='\e[0m'

########################################################################
## options #############################################################
########################################################################

# misc -----------------------------------------------------------------
# use vi keybinds
bindkey -v
# no beep
unsetopt beep
unsetopt hist_beep
unsetopt list_beep
# display errors
#setopt print_exit_value
# confirm 'rm *'
unsetopt rm_star_silent
# no error on search 
setopt nullglob
# complétion menu
setopt auto_menu
# confirm 'rm *' etc
setopt rm_star_wait
# don't &proc kill on exit
setopt auto_continue
# don’t nice &proc
setopt no_bg_nice

# keys -----------------------------------------------------------------
typeset -A key
key[Home]=${terminfo[khome]}
key[End]=${terminfo[kend]}
key[Insert]=${terminfo[kich1]}
key[Delete]=${terminfo[kdch1]}
key[Up]=${terminfo[kcuu1]}
key[Down]=${terminfo[kcud1]}
key[Left]=${terminfo[kcub1]}
key[Right]=${terminfo[kcuf1]}
key[PageUp]=${terminfo[kpp]}
key[PageDown]=${terminfo[knp]}
# setup key accordingly
[[ -n "${key[Home]}"    ]]  && bindkey  "${key[Home]}"    beginning-of-line
[[ -n "${key[End]}"     ]]  && bindkey  "${key[End]}"     end-of-line
[[ -n "${key[Insert]}"  ]]  && bindkey  "${key[Insert]}"  overwrite-mode
[[ -n "${key[Delete]}"  ]]  && bindkey  "${key[Delete]}"  delete-char
[[ -n "${key[Up]}"      ]]  && bindkey  "${key[Up]}"      up-line-or-history
[[ -n "${key[Down]}"    ]]  && bindkey  "${key[Down]}"    down-line-or-history
[[ -n "${key[Left]}"    ]]  && bindkey  "${key[Left]}"    backward-char
[[ -n "${key[Right]}"   ]]  && bindkey  "${key[Right]}"   forward-char

# history --------------------------------------------------------------
# history size
HISTSIZE=5000
SAVEHIST=5000
# history file
HISTFILE=~/.zsh_history
# history without double entry
setopt hist_ignore_all_dups
# all zsh instance share same file
setopt share_history
# update history
setopt inc_append_history

########################################################################
## aliases #############################################################
########################################################################

# ls & grep ------------------------------------------------------------
alias ls='ls --color=auto'
alias dir='dir --color=auto'
alias vdir='vdir --color=auto'
alias grep='grep --color=auto'
alias fgrep='fgrep --color=auto'
alias egrep='egrep --color=auto'
alias man='LANG=C man'
alias ll='ls -l'
alias la='ls -A'
alias l='ls -CF'

# cd & goto ------------------------------------------------------------
alias cd..='cd ..'
alias ...='cd ..'
alias ....='cd ../..'
alias gm='cd /media'
alias gc='cd ~/.config'
alias gb='cd ~/bin'
alias gp='cd ~/pkgs'

# empty trash folder
alias emptytrash='rm -vRI .local/share/Trash/files .local/share/Trash/info; echo -e "\n >> ${red}trash is gone$NC <<\n"'
# get top 10 shell commands:
alias top10='print -l ${(o)history%% *} | uniq -c | sort -nr | head -n 10'
# process using web
alias ports='lsof -i -n -P'
# last modified files and folders
alias mod60="find /home/$USER/ -path /home/$USER/.thumbnails -prune -o -path /home/$USER/.mozilla -prune -o -mmin -60"
alias modd="find /home/$USER/ -path /home/$USER/.thumbnails -prune -o -path /home/$USER/.mozilla -prune -o -mtime -1"
# make parent directory if needed
alias mkdir='mkdir -p'
#alias gcc
alias gww="gcc -Werror -Wextra -Wall"
alias moulinette="gcc -Werror -Wextra -Wall"
#
# packages -------------------------------------------------------------

# quit, exit & reboot --------------------------------------------------
alias :q='exit'
alias oust='echo "bye arpi..."; sleep 2s && sudo shutdown -h now'
alias comeback='echo "be back right now..."; sleep 2s && sudo shutdown -r now'

# zsh cfg --------------------------------------------------------------
alias zcfg='vim ~/.zshrc'
alias rzsh='source ~/.zshrc'

########################################################################
## file type ###########################################################
########################################################################
alias -s html=$BROWSER
alias -s pdf=epdfview
alias -s svg=inkscape
alias -s png=eyez
alias -s jpg=eyez
alias -s gif=eyez
alias -s txt=$EDITOR
alias -s conf=$EDITOR
alias -s py=$EDITOR
alias -s php=$EDITOR
alias -s mp3=mplayer
alias -s ogg=mplayer
alias -s ogv=mplayer
alias -s flv=mplayer
alias -s avi=mplayer
alias -s mp4=mplayer
alias -s mkv=mplayer
alias -s m3u=mocp
alias -s zip=dtrx
alias -s tar=dtrx
alias -s tar.gz=dtrx
alias -s tar.bz2=dtrx
alias -s xz=dtrx
alias -s rar=dtrx


# extract
function extract()      
{
     if [ -f $1 ] ; then
         case $1 in
             *.tar.bz2)   tar xvjf $1     ;;
             *.tar.gz)    tar xvzf $1     ;;
             *.bz2)       bunzip2 $1      ;;
             *.rar)       unrar x $1      ;;
             *.gz)        gunzip $1       ;;
             *.tar)       tar xvf $1      ;;
             *.tbz2)      tar xvjf $1     ;;
             *.tgz)       tar xvzf $1     ;;
             *.zip)       unzip $1        ;;
             *.Z)         uncompress $1   ;;
             *.7z)        7z x $1         ;;
             *.xz)        unxz $1         ;;
             *)           echo "'$1' cannot be extracted via >extract<" ;;
         esac
     else
         echo "'$1' is not a valid file"
     fi
}
# compress
mktar() { tar cvf  "${1%%/}.tar"     "${1%%/}/"; }
mktgz() { tar cvzf "${1%%/}.tar.gz"  "${1%%/}/"; }
mktbz() { tar cvjf "${1%%/}.tar.bz2" "${1%%/}/"; }
mktxz() { tar cvJf "${1%%/}.tar.xz" "${1%%/}/"; }

########################################################################
## completion ##########################################################
########################################################################
autoload -Uz compinit
compinit
zstyle ':completion:*' auto-description 'specify: %d'
zstyle ':completion:*' completer _expand _complete _correct _approximate
zstyle ':completion:*' format 'Completing %d'
zstyle ':completion:*' group-name ''
zstyle ':completion:*' menu select=1
eval "$(dircolors -b)"
zstyle ':completion:*:default' list-colors ${(s.:.)LS_COLORS}
zstyle ':completion:*' list-colors ''
zstyle ':completion:*' list-prompt %SAt %p: Hit TAB for more, or the character to insert%s
zstyle ':completion:*' matcher-list '' 'm:{a-z}={A-Z}' 'm:{a-zA-Z}={A-Za-z}' 'r:|[._-]=* r:|=* l:|=*'
zstyle ':completion:*' menu select=1
zstyle ':completion:*' select-prompt %SScrolling active: current selection at %p%s
zstyle ':completion:*' use-compctl false
zstyle ':completion:*' verbose true
zstyle ':completion:*:*:kill:*:processes' list-colors '=(#b) #([0-9]#)*=0=01;31'
zstyle ':completion:*:kill:*' command 'ps -u $USER -o pid,%cpu,tty,cputime,cmd'

########################################################################
## prompt ##############################################################
########################################################################
autoload -Uz promptinit
autoload -U colors && colors
promptinit
RPROMPT="%{$reset_color%}< %{$fg[blue]%}%M%{$reset_color%}:%{$fg[yellow]%}%~%{$reset_color%}"
PROMPT="%{$reset_color%}%{$fg[yellow]%} %T%{$reset_color%} %{$fg[green]%}%n%{$reset_color%} > "
## EOF #################################################################
