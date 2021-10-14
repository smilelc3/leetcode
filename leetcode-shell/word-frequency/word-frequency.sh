#!/bin/bash

declare -A word_count	# 定义一个map

for word in $(sed 's/\\n/ /g' < words.txt); do			# sed 's/\\n/ /g' 中，s/原表达式/替换/g 	/g表示全局替换，不加仅替换每行第一个
    ((word_count[$word]++))
done

for k in ${!word_count[@]}; do
    echo $k ${word_count[$k]}
done | sort -nr -k 2	# -n 依照数值大小排序（升序） -r 以相反顺序排序 -k 2 以第二元素作为排序