#!/bin/bash

for i in {1..30}
do
  gcc -o programa quick_sort.c  # compila o código em C, gerando um executável diferente a cada iteração
  ./programa  # executa o programa recém-compilado
  time ./programa
done