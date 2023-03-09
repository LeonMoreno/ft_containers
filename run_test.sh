#!/bin/bash

# Variables
LOGSDIR=./logs/
MK='make -j8'
MKF='make fclean'

# Colors
RESET="\033[0m"
BOLD="\033[1m"
RED="\033[0;31m"
CYAN="\033[0;36m"
V_GREEN="\e[0;38;5;82m"
BIYellow="\033[1;93m"     # Yellow

if [ "$(eval uname)" == "Darwin" ]; then # For MacOS
    DIFF=diff
    V_GREEN="\033[32m"
else
    DIFF="diff --color" # for Linux
fi

ft_run() {
	echo -e "\n${CYAN} ********************** $ARG ******************\n${RESET}"

	echo -e "\n${BIYellow} ########## MAKING AND RUNNING STL:: VERSION ########## \n${RESET}"

	$MK -C ${DIR} stl.out
	${DIR}stl.out 42

	echo -e "\n${BIYellow} ########## MAKING AND RUNNING FT:: VERSION ########## \n${RESET}"

	$MK -C ${DIR}
	${DIR}ft.out 42
}

ft_diff() {
	mkdir -p ${LOGSDIR}

	echo -e "\n${RED} ------ comparing FT & STL ----------\n${RESET}"
	${DIR}stl.out 42 > ${LOGSDIR}std.txt 2> ${LOGSDIR}errors.txt
	${DIR}ft.out 42 > ${LOGSDIR}ft.txt 2>> ${LOGSDIR}errors.txt
	${DIFF} ${LOGSDIR}std.txt ${LOGSDIR}ft.txt
}

cleanup() {
	rm -rf ${LOGSDIR}
	 $MKF -C ${DIR}
}

if [[ ($1 == -m || $1 == --m) ]]
then
	cat ./tests/header
	DIR=./tests/map/
	ARG="MAP TESTER"
	ft_run
	ft_diff
	cleanup
elif [[ ($1 == -v || $1 == --v )]]
then
	cat ./tests/header
	DIR=./tests/vector/
	ARG="VECTOR TESTER"
	ft_run
	ft_diff
	cleanup
elif [[ ($1 == -i || $1 == --i )]]
then
	cat ./tests/header
	DIR=./tests/intra/
	ARG="INTRA TESTER"
	ft_run
	ft_diff
	cleanup
elif [[ ($1 == -s || $1 == --s )]]
then
	cat ./tests/header
	DIR=./tests/stack/
	ARG="STACK TESTER"
	ft_run
	ft_diff
	cleanup
elif [[ ($1 == -ut || $1 == --ut )]]
then
	cd ./ft_containers-unit-test/
	./start.sh
elif [[ ($1 == -h || $1 == --h)]]
then
	echo -e	" \n -ut, --ut \t\t Run Unit Test by @elaronda & @cshells \n" \
			 "-v, --v \t\t Run Vector tests \n" \
			"-m, --m \t\t Run Map tests   \n" \
			"-s, --s \t\t Run Stack tests  \n" \
			"-i, --i \t\t Run Intra tests  \n" \
			"-h, --h \t\t This promp Help \n"
else
	echo Uknown command. Use --help or -h
fi



