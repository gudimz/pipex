#!/bin/zsh

echo "\e[1;37m====================================================================================="

echo "\n\n\e[1;31m  ########  #### ########  ######## ##     ##    ######## ########  ######  ######## \e[0m"
echo "\e[1;32m  ##     ##  ##  ##     ## ##        ##   ##        ##    ##       ##    ##    ##        \e[0m"
echo "\e[1;34m  ##     ##  ##  ##     ## ##         ## ##         ##    ##       ##          ##        \e[0m"
echo "\e[1;33m  ########   ##  ########  ######      ###          ##    ######    ######     ##        \e[0m"
echo "\e[1;35m  ##         ##  ##        ##         ## ##         ##    ##             ##    ##        \e[0m"
echo "\e[1;36m  ##         ##  ##        ##        ##   ##        ##    ##       ##    ##    ##        \e[0m"
echo "\e[1;37m  ##        #### ##        ######## ##     ##       ##    ########  ######     ##        \e[0m"

cd ./test

##############################################          TEST 1         ####################################################

./pipex my_infile.txt "grep ?" my_outfile.txt 2> my_error.txt

echo "\n\n====================================================================================="
echo "\e[1;37m*************************************\e[1;32m TEST №1 \e[0m\e[1;37m***************************************\n"

echo "\e[1;34m              ./pipex \e[1;32m my_infile.txt.txt \e[0m \e[1;31m [grep ?] \e[0m \e[1;32m my_outfile.txt \e[0m\n"
echo "                      \e[1;32mRESULT: \e[1;37m$(<my_error.txt)\e[0m"

rm -rf my_error.txt

##############################################          TEST 2         ####################################################

./pipex filenotfound.txt "grep ?" "wc -w" my_outfile.txt 2> my_error.txt

echo "\n====================================================================================="
echo "\e[1;37m*************************************\e[1;32m TEST №2 \e[0m\e[1;37m***************************************\n"

echo "\e[1;34m           ./pipex \e[1;31m filenotfound.txt \e[0m \e[1;32m [grep ?] [wc -w] \e[0m \e[1;32m my_outfile.txt \e[0m\n"
echo "                        \e[1;32mRESULT: \e[1;37m$(<my_error.txt)\e[0m"

rm -rf my_error.txt

##############################################          TEST 3         ####################################################

./pipex my_infile.txt "cmdnotfound ?" "wc -w" my_outfile.txt 2> my_error.txt

echo "\n====================================================================================="
echo "\e[1;37m*************************************\e[1;32m TEST №3 \e[0m\e[1;37m***************************************\n"

echo "\n\e[1;34m            ./pipex \e[1;32m my_infile.txt \e[0m \e[1;31m [cmdnotfound] \e[1;32m[wc -w] my_outfile.txt \e[0m\n"
echo "                    \e[1;32mRESULT: \e[1;37m$(<my_error.txt)\e[0m"

rm -rf my_error.txt

##############################################          TEST 4         ####################################################

./pipex my_infile.txt "grep ?" "wc -w" my_outfile.txt

< or_infile.txt grep "?" | wc -l > or_outfile.txt

echo "\n====================================================================================="
echo "\e[1;37m*************************************\e[1;32m TEST №4 \e[0m\e[1;37m***************************************\n"

echo "\e[1;34m           ./pipex \e[1;32m my_infile.txt \e[0m \e[1;31m [grep ?] [wc -w] \e[0m \e[1;32m my_outfile.txt \e[0m\n"
echo "\e[1;32m             < or_infile.txt \e[1;31m [grep ?] \e[1;32m | \e[1;31m [wc -w] \e[1;32m > or_outfile.txt\e[0m\n"

diff or_outfile.txt my_outfile.txt

if [ $? = 0 ]
then
	echo "\n                         \e[1;37m my_outfile    ==    or_outfile \e[0m"
	echo "                 \e[1;32mRESULT:\e[1;37m$(<my_outfile.txt)           $(<or_outfile.txt)\e[0m"
	echo "                                       \e[1;32m OK:) \e[0m"
else
	echo "\n                         \e[1;37m my_outfile    !=    or_outfile \e[0m"
	echo "                 \e[1;31mRESULT:\e[1;37m$(<my_outfile.txt)           $(<or_outfile.txt)\e[0m"
	echo "                                      \e[1;31m FAIL:( \e[0m"
fi
rm -rf my_outfile.txt
rm -rf or_outfile.txt

##############################################          TEST 5         ####################################################

./pipex my_infile.txt "/usr/bin/grep ?" "/usr/bin/wc -w" my_outfile.txt

< or_infile.txt /usr/bin/grep "?" | /usr/bin/wc -l > or_outfile.txt

echo "\n====================================================================================="
echo "\e[1;37m*************************************\e[1;32m TEST №5 \e[0m\e[1;37m***************************************\n"

echo "\e[1;34m    ./pipex \e[1;32m my_infile.txt \e[0m \e[1;31m [/usr/bin/grep ?] [/usr/bin/wc -w] \e[0m \e[1;32m my_outfile.txt \e[0m\n"
echo "\e[1;32m      < or_infile.txt \e[1;31m [/usr/bin/grep ?] \e[1;32m | \e[1;31m [/usr/bin/wc -w] \e[1;32m > or_outfile.txt\e[0m\n"

diff or_outfile.txt my_outfile.txt

if [ $? = 0 ]
then
	echo "\n                          \e[1;37m my_outfile    ==    or_outfile \e[0m"
	echo "                  \e[1;32mRESULT:\e[1;37m$(<my_outfile.txt)           $(<or_outfile.txt)\e[0m"
	echo "                                        \e[1;32m OK:) \e[0m"
else
	echo "\n                          \e[1;37m my_outfile    !=    or_outfile \e[0m"
	echo "                  \e[1;31mRESULT:\e[1;37m$(<my_outfile.txt)           $(<or_outfile.txt)\e[0m"
	echo "                                      \e[1;31m FAIL:( \e[0m"
fi
rm -rf my_outfile.txt
rm -rf or_outfile.txt

##############################################          TEST 6         ####################################################

./pipex my_infile.txt "grep ?" "wc -w" "cat -e" "cat -e" my_outfile.txt

< or_infile.txt grep "?" | wc -l | cat -e | cat -e > or_outfile.txt

echo "\n====================================================================================="
echo "\e[1;37m*************************************\e[1;32m TEST №6 \e[0m\e[1;37m***************************************\n"

echo "\e[1;34m    ./pipex \e[1;32m my_infile.txt \e[0m \e[1;31m [grep ?] [wc -w] [cat -e] [cat -e] \e[0m \e[1;32m my_outfile.txt \e[0m\n"
echo "\e[1;32m < or_infile.txt \e[1;31m [grep ?] \e[1;32m | \e[1;31m [wc -w] \e[1;32m | \e[1;31m [cat -e] \e[1;32m | \e[1;31m [cat -e] \e[1;32m > or_outfile.txt\e[0m\n"

diff or_outfile.txt  my_outfile.txt

if [ $? = 0 ]
then
	echo "\n                         \e[1;37m my_outfile    ==    or_outfile \e[0m"
	echo "               \e[1;32mRESULT:\e[1;37m$(<my_outfile.txt)           $(<or_outfile.txt)\e[0m"
	echo "                                       \e[1;32m OK:) \e[0m"
else
	echo "\n                         \e[1;37m my_outfile    !=    or_outfile \e[0m"
	echo "               \e[1;31mRESULT:\e[1;37m$(<my_outfile.txt)           $(<or_outfile.txt)\e[0m"
	echo "                                      \e[1;31m FAIL:( \e[0m"
fi
rm -rf my_outfile.txt
rm -rf or_outfile.txt
echo "\n\e[1;37m=====================================================================================\e[0m"

rm -rf pipex