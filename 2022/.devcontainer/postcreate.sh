#! /usr/bin/env bash

cd "${HOME}" || exit

wget \
  --progress=dot:mega \
  https://raw.githubusercontent.com/git/git/master/contrib/completion/git-completion.bash

wget \
  --progress=dot:mega \
  https://raw.githubusercontent.com/git/git/master/contrib/completion/git-prompt.sh
chmod 744 git-completion.bash git-prompt.sh

{
  echo ". ~/git-completion.bash"
  echo ". ~/git-prompt.sh"
  echo "bind 'set completion-ignore-case on'"
} >> "${HOME}"/.bashrc

git clone --depth 1 https://github.com/junegunn/fzf.git ~/.fzf
~/.fzf/install --all

LATEST_VERSION=$(curl -s "https://api.github.com/repos/jesseduffield/lazygit/releases/latest" | grep '"tag_name":' |  sed -E 's/.*"v*([^"]+)".*/\1/')
curl -Lo lazygit.tar.gz "https://github.com/jesseduffield/lazygit/releases/latest/download/lazygit_${LATEST_VERSION}_Linux_x86_64.tar.gz"
sudo tar xf lazygit.tar.gz -C /usr/local/bin lazygit
sudo ln -s /usr/local/bin/lazygit /usr/local/bin/lg
rm -rf lazygit*
echo "Lazygit installed!"

cat << 'EOF' >> ~/.bashrc
tidy() {
  div="======================================================================"
  _tidy() {
    file=$1
    output=$(clang-tidy -p ../build/ --extra-arg=-Wno-unknown-warning-option --quiet --use-color "$file" 2>&1)
    if [[ $(echo "$output" | wc -l) -ne 1 ]]; then
      printf "❌ %s\n%s\n%s\n" "$file" "$output" "$div"
    else
      printf "✔️  %s\n%s\n" "$file" "$div"
    fi
  }
  cd /workspaces/track-fusion || exit
  case $1 in
  "all")
    echo "tidying all..."
    files=$(find . -name '*.[ch]pp$' -type f)
  ;;
  "branch") ;& *)
    echo "tidying branch..."
    files=$(
      git diff --name-only main \
      | cut -f2 \
      | grep '.*[ch]pp$'
    )
  ;;
  esac 
  echo $div
  for file in $files; do
    [[ -f $file ]] && { _tidy "$file" & } 2>/dev/null
  done
  wait 2>/dev/null
}

h() {
  $1 --help | less
}

# unified bash history
shopt -s histappend
PROMPT_COMMAND="${PROMPT_COMMAND:+$PROMPT_COMMAND$'\n'}history -a; history -c; history -r"

alias ll='ls -l'
alias path='sed "s/:/\n/g" <<< $PATH'
PS1='\n\[\e[01;39m\]\u \[\e[01;35m\]\w\[\e[01;36m\]$(__git_ps1)$([[ -z $(git status --porcelain 2>/dev/null) ]] || echo "*")\[\e[0m\]\n$ '
# export DISPLAY=host.docker.internal:0.0
EOF

{
  echo "python"
  echo "import sys"
  echo "sys.path.insert(0, '/usr/share/gcc/python')"
  echo "from libstdcxx.v6.printers import register_libstdcxx_printers"
  echo "register_libstdcxx_printers (None)"
  echo "end"
} >> "${HOME}/.gdbinit"