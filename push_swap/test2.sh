#!/bin/bash
make
make bonus

for i in `seq 1 1000`
do
	ARG=`ruby -e "puts (0..$i).to_a.shuffle.join(' ')"`
	NB=`./push_swap $ARG | wc -l | tr -d ' '`
	TEST=`./push_swap $ARG | ./checker_mac $ARG`
	if [ "$TEST" = "OK" ]
	then
		COLOR="\033[38;2;0;255;0m"
	else
		COLOR="\033[38;2;255;0;0m"
	fi
	echo -e "$i : $COLOR$TEST\033[0;00m nb operation : $NB"
done