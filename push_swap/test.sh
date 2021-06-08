#!/bin/bash
make
make checker

echo "Invalid arg"

TEST=`./push_swap 5 3 f 8`
if [ "$TEST" = "Error" ]
then
	echo -e "\033[38;2;0;255;0mOK\033[0;00m"
else
	echo -e "\033[38;2;255;0;0mKO\033[0;00m"
fi

TEST=`./push_swap 5 3 5 6`
if [ "$TEST" = "Error" ]
then
	echo -e "\033[38;2;0;255;0mOK\033[0;00m"
else
	echo -e "\033[38;2;255;0;0mKO\033[0;00m"
fi

TEST=`./push_swap 1 6 7 11111111111111111`
if [ "$TEST" = "Error" ]
then
	echo -e "\033[38;2;0;255;0mOK\033[0;00m"
else
	echo -e "\033[38;2;255;0;0mKO\033[0;00m"
fi
echo

echo "Invalid op"

TEST=`echo "da" | ./checker "1"`
if [ "$TEST" = "Error" ]
then
	echo -e "\033[38;2;0;255;0mOK\033[0;00m"
else
	echo -e "\033[38;2;255;0;0mKO\033[0;00m"
fi
echo

for i in `seq 1 10`
do
	ARG=`ruby -e "puts (0..5).to_a.shuffle.join(' ')"`
	NB=`./push_swap $ARG | wc -l | tr -d ' '`
	TEST=`./push_swap $ARG | ./checker $ARG`
	if [ "$TEST" = "OK" ]
	then
		COLOR="\033[38;2;0;255;0m"
	else
		COLOR="\033[38;2;255;0;0m"
	fi
	echo -e "$COLOR$TEST\033[0;00m nb operation : $NB"
done
echo
for i in `seq 1 10`
do
	ARG=`ruby -e "puts (0..100).to_a.shuffle.join(' ')"`
	NB=`./push_swap $ARG | wc -l | tr -d ' '`
	TEST=`./push_swap $ARG | ./checker $ARG`
	if [ "$TEST" = "OK" ]
	then
		COLOR="\033[38;2;0;255;0m"
	else
		COLOR="\033[38;2;255;0;0m"
	fi
	echo -e "$COLOR$TEST\033[0;00m nb operation : $NB"
done
echo
for i in `seq 1 10`
do
	ARG=`ruby -e "puts (0..500).to_a.shuffle.join(' ')"`
	NB=`./push_swap $ARG | wc -l | tr -d ' '`
	TEST=`./push_swap $ARG | ./checker $ARG`
	if [ "$TEST" = "OK" ]
	then
		COLOR="\033[38;2;0;255;0m"
	else
		COLOR="\033[38;2;255;0;0m"
	fi
	echo -e "$COLOR$TEST\033[0;00m nb operation : $NB"
done