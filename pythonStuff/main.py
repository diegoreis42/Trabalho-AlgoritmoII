#!/usr/bin/python3

# Created by Diego Reis - 21/04

import argparse as ap
import rand_files_gen as rfg

parser = ap.ArgumentParser(
            prog="RandFilesGen",
            description="Cria arquivos de numeros aleatorios em diversos formatos",
            epilog="Ever tried, ever failed"
            )

parser.add_argument("-f", "--file", dest="fileName", help="Nome do arquivo a ser criado")
parser.add_argument("-n", "--numbers", dest="nrandNum", type=int, help="Quantidade de numeros aleatorios a ser criado, 'n' tambem define o range dos numeros")
parser.add_argument("-O", "--ordered", action="store_true", help="Indica se a sequencia de numeros deve ser ordenada")
parser.add_argument("-A", "--automatic", action="store_true", help="Automatiza a criaçao de arquivos aleatorios, de tamanhos 100, 1000, 10000, 100000, 1000000")

if __name__ == "__main__":
    
    args = parser.parse_args()
    if args.automatic:
        rfg.autoGen(args.ordered)
    else:
        rfg.writeRandFile(args.fileName, args.nrandNum, args.ordered)
    


                            
