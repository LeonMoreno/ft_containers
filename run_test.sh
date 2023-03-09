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
P_GREEN="\e[0;38;5;23m"
BIYellow="\033[1;93m"     # Yellow

if [ "$(eval uname)" == "Darwin" ]; then # For MacOS
    DIFF=diff
    V_GREEN="\033[32m"
else
    DIFF="diff --color" # for Linux
fi

usage()
{
	echo "usage:"
	echo -e "bash tester.sh vector"
	echo -e "bash tester.sh map"
	echo -e "bash tester.sh stack"
	echo -e "bash tester.sh set"
	echo -e "bash tester.sh intra"
	exit
}

# echo $1

if (( $# != 1 )); then
    usage
fi

# ARG=$1
if [ $1 == "map" ]; then
    DIR=./tests/map/
# elif [ ${ARG} == "map" ]; then
#     DIR=./tests/map/
# elif [ ${ARG} == "stack" ]; then
#     DIR=./tests/stack/
# elif [ ${ARG} == "set" ]; then
#     DIR=./tests/set/
# elif [ ${ARG} == "intra" ]; then
#     DIR=./tests/intra/
# else
# 	echo -e "\""$1"\" is not a valid argument."
#     usage
fi



echo -e "\n${CYAN} ********************** $1 ******************\n${RESET}"

echo -e "\n${BIYellow} ########## MAKING AND RUNNING STL:: VERSION ########## \n${RESET}"

$MK -C ${DIR} stl.out
${DIR}stl.out

echo -e "\n${BIYellow} ########## MAKING AND RUNNING FT:: VERSION ########## \n${RESET}"

$MK -C ${DIR}
${DIR}ft.out


mkdir -p ${LOGSDIR}

echo -e "\n${V_GREEN} ---------- comparing----------\n${RESET}"
# Haciendo el log
${DIR}stl.out > ${LOGSDIR}std.txt 2> ${LOGSDIR}errors.txt
${DIR}ft.out > ${LOGSDIR}ft.txt 2>> ${LOGSDIR}errors.txt

${DIFF} ${LOGSDIR}std.txt ${LOGSDIR}ft.txt

#Limpiando
$MKF -C ${DIR}
rm -fr ${LOGSDIR}

exit 0
