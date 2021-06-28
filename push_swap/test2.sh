#!/bin/bash
make
make bonus

./push_swap 0 1 2 3 | ./checker 0 1 2 3
./push_swap 0 1 3 2 | ./checker 0 1 3 2
./push_swap 0 2 1 3 | ./checker 0 2 1 3
./push_swap 0 2 3 1 | ./checker 0 2 3 1
./push_swap 0 3 1 2 | ./checker 0 3 1 2
./push_swap 0 3 2 1 | ./checker 0 3 2 1
./push_swap 1 0 2 3 | ./checker 1 0 2 3
./push_swap 1 0 3 2 | ./checker 1 0 3 2
./push_swap 1 2 0 3 | ./checker 1 2 0 3
./push_swap 1 2 3 0 | ./checker 1 2 3 0
./push_swap 1 3 0 2 | ./checker 1 3 0 2
./push_swap 1 3 2 0 | ./checker 1 3 2 0
./push_swap 2 0 1 3 | ./checker 2 0 1 3
./push_swap 2 0 3 1 | ./checker 2 0 3 1
./push_swap 2 1 0 3 | ./checker 2 1 0 3
./push_swap 2 1 3 0 | ./checker 2 1 3 0
./push_swap 2 3 1 0 | ./checker 2 3 1 0
./push_swap 2 3 0 1 | ./checker 2 3 0 1
./push_swap 3 0 1 2 | ./checker 3 0 1 2
./push_swap 3 0 2 1 | ./checker 3 0 2 1
./push_swap 3 1 0 2 | ./checker 3 1 0 2
./push_swap 3 1 2 0 | ./checker 3 1 2 0
./push_swap 3 2 0 1 | ./checker 3 2 0 1
./push_swap 3 2 1 0 | ./checker 3 2 1 0