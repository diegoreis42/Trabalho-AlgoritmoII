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



if __name__ == "__main__":
    
    args = parser.parse_args()
    
    rfg.writeRandFile(args.fileName, args.nrandNum)
    


                            
