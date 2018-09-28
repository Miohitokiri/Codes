#!/bin/bash
echo "by. MiohitoKiri5474"
sudo apt install git vim python2 python3  g++ LLVM
echo "zsh install"
sudo apt install zsh
sudo sudo sh -c "echo $(which zsh) >> /etc/shells"
chsh -s $(which zsh)
sh -c "$(curl -fsSL https://raw.githubusercontent.com/robbyrussell/oh-my-zsh/master/tools/install.sh)"
rm -rf .oh-my-zsh
git clone https://github.com/Miohitokiri/.oh-my-zsh.git
git clone https://github.com/bhilburn/powerlevel9k.git ~/.oh-my-zsh/custom/themes/powerlevel9k
sudo rm -rf ~/.zshrc
sudo cp ~/.oh-my-zsh/.zshrc ~/
git clone https://github.com/Miohitokiri/nerd-fonts-backup.git
cd nerd-fonts-backup
sudo mv * /usr/share/fonts
cd
echo "tmux install"
sudo apt install tmux
git clone https://github.com/Miohitokiri/.tmux.git
mv ~/.tmux/.tmux.conf.local ~/
echo "vim install"
git clone https://github.com/Miohitokiri/.vim.git
cp ~/.vim/vimrc ~/
cd
mv vimrc .vimrc
cd ~/.vim/bundle/YouCompleteMe
./install.py
cd
echo "please relogin"
exec $SHELL
