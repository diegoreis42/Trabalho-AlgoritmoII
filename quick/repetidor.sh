#!/bin/bash

for i in {1..30}
do
  gcc -o programa$i quick_sort.c  # compila o código em C, gerando um executável diferente a cada iteração
  ./programa$i  # executa o programa recém-compilado
done