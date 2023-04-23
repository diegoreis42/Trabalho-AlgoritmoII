#!/bin/bash
cd ordenacao
for i in {1..10}
do
  g++ main.c ordenacao.c -o programa
  time ./programa
done