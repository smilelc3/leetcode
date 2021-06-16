#!/bin/bash

# pure solution
#num=0
#while read -r line; do
#  ((num++))
#  if [[ $num -eq 10 ]]; then
#    echo "$line"
#    exit
#  fi
#done < file.txt

# or using sed
sed -n 10p file.txt