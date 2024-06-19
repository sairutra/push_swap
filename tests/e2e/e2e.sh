#!/bin/bash

make re -C ../../ 

shuf -i 1-10 | tr '\n' ' ' | xargs ../../bin/push_swap
