# Created by Diego Reis 21/04

import random as r



def writeRandFile(nome, n: int):
    path = "../rand_files/"
    nome = path + nome
    with open(nome, 'x') as file:
        for x in range(n):
            file.write("%d\n" % r.randrange(n))
        file.close()


