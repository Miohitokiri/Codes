#!/bin/bash
echo "by. MiohitoKiri5474"
echo ""
echo ""

sudo apt install git vim python2 python3  g++ LLVM
echo ""
echo "zsh install"
echo ""
sudo apt install zsh
sudo sh -c "echo $(which zsh) >> /etc/shells"
chsh -s $(which zsh)
sh -c "$(curl -fsSL https://raw.githubusercontent.com/robbyrussell/oh-my-zsh/master/tools/install.sh)"
rm -rf .oh-my-zsh
git clone https://github.com/Miohitokiri5474/.oh-my-zsh.git
git clone https://github.com/bhilburn/powerlevel9k.git ~/.oh-my-zsh/custom/themes/powerlevel9k
sudo rm -rf ~/.zshrc
sudo cp ~/.oh-my-zsh/.zshrc ~/
git clone https://github.com/Miohitokiri5474/nerd-fonts-backup.git
cd nerd-fonts-backup
sudo mv * /usr/share/fonts
cd ~
echo ""
echo "tmux install"
echo ""
sudo apt install tmux
git clone https://github.com/Miohitokiri5474/.tmux.git
mv ~/.tmux/.tmux.conf.local ~/
echo ""
echo "vim install"
echo ""
git clone https://github.com/Miohitokiri5474/.vim.git
cp ~/.vim/vimrc ~/
cd ~
mv vimrc .vimrc
cd ~/.vim/bundle/YouCompleteMe
./install.py
cd ~
echo ""
echo "please relogin your account"
echo ""
exec $SHELL
sudo reboot
