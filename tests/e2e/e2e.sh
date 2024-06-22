#!/bin/bash

# https://developers.redhat.com/blog/2021/04/23/valgrind-memcheck-different-ways-to-lose-your-memory#generating_a_leak_summary
# https://stackoverflow.com/questions/76698927/why-is-valgrind-ignoring-my-error-exitcode-option

make re -C ../../ 

#error cases

args=$(shuf -i 1-10 | tr '\n' ' ')
valgrind --error-exitcode=42 --leak-check=full --errors-for-leak-kinds=all ../../bin/push_swap $args &> /dev/null
echo $?
../../bin/push_swap $args | wc -l 
../../bin/push_swap $args | ./checker_linux $args
#small arrays

#subject requirements

#1 to 500 test

#bigger nummer test