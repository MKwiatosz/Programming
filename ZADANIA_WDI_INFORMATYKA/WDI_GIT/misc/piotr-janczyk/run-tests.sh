#!/usr/bin/env bash
# 2017 Piotr Janczyk

correct=0
wrong=0

while read file; do
    echo -e "\e[93m$file\e[0m"
    if g++ "$file" -std=c++11 -o compiled-test; then
        if ./compiled-test; then
            ((correct++))
        else
            ((wrong++))
        fi
    else
        ((wrong++))
    fi
    rm compiled-test &>/dev/null
done < <(find ../../ -iwholename "*/piotr-janczyk/tests.cpp")

echo "-------------------------"
echo -e "\e[92m $correct passed\e[0m"
echo -e "\e[91m $wrong failed\e[0m"
echo "-------------------------"
