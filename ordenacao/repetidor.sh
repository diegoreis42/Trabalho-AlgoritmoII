#!/bin/bash

for i in {1..10}
do
    g++ main.c ordenacao.c -o programa
    time ./programa
done