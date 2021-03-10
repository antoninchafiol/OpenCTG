import matplotlib.pyplot as plt
import os, sys, math
from argparse import ArgumentParser
import numpy as npy

def isprime(x):
    for i in range(2, x-1):
        if x % i == 0:
            return False
    else:
        return True

def numberOfPrime(x):
    res = 0
    for i in range(2,x):
        if isprime(i) == True:
            res += 1
    return res

def options(params):
    if len(params.option) != 3:
        print("Not enough parameters")
        return -1
    s = params.option[0]
    val = int(params.option[1])
    maxrange = int(params.option[2])
    if s == "prime":
        if val == 0:
            # Prime repartition !
            x = []
            y = []
            for i in range (2, maxrange):
                x.append(i)
                y.append(numberOfPrime(i))

            fig = plt.figure()
            ax = fig.add_subplot(1, 1, 1)
            ax.plot(x, y, "b", label="PrimeFreq(x)")
            ax.plot(x, x/npy.log(x), "c", label="x/Log(x)")
            ax.plot(x, npy.log(x), "r", label="Log(x)")
            plt.legend(loc="upper left")
            plt.show()
        elif val == 1:
            # Delta between two prime numbers
            primeAnchor = 2 # 
            y = [] #gap
            x = []
            for i in range (2, maxrange):
                y.append(i-primeAnchor)
                x.append(i)
                if isprime(i) == True:
                    primeAnchor = i

            # print(y)
            fig = plt.figure()
            ax = fig.add_subplot(1, 1, 1)
            ax.plot(x, y, "b")
            plt.legend(loc="upper left")
            plt.show()
            return 0
        elif val == 2:
            # Count number of 
            return 0
        else:
            print("Not the right options")

if __name__ == "__main__":

    parser = ArgumentParser(prog="Plot ")
    parser.add_argument('option', type=str, nargs="+")
    params, other = parser.parse_known_args(sys.argv[1:])
    print(params.option)
    options(params)