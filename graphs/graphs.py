from argparse import ArgumentParser
from scipy.integrate import quad
import scipy.special as sc
import matplotlib.pyplot as plt
import os,sys, math
import numpy as npy

def isPrime(x):
    for i in range(2,x-1):
        if(x % i ==0):
            return False
    else:
        return True

def numberOfPrime(x):
    res = 0
    for i in range(2, x):
        if isPrime(i) == True:
            res += 1
    return res

def integrand(x,a):
    return 1/math.log(a)

def options(params):
    if len(params.option) != 3:
        print("Not enough parameters")
        return -1
    s = params.option[0]
    val = int(params.option[1])
    maxrange = int(params.option[2])
    if s == "prime":
        if val == 0:
            x=[]
            y=[]
            y_li=[]
            for i in range(2,maxrange):
                x.append(i)
                nop = numberOfPrime(i)
                y.append(nop)
                y_li.append(sc.expi(math.log(i)))
                
            fig = plt.figure()
            ax = fig.add_subplot(1,1,1)
            ax.plot(x,y,"b",label="PrimeFreq(x)")
            #ax.plot(x, x/npy.log(x), "c",label="x/log(x)")
            #ax.plot(x, npy.log(x),"r",label="Log(x)")
            #ax.plot(x, y_li, color="orange" ,label="Li(x)")
            plt.legend(loc="upper left")
            plt.show()
        elif val == 1:
            return 0
        elif val == 2:
            return 0
    elif s == "test":
        print("test")

if __name__ == "__main__":
    parser = ArgumentParser(prog="Plot...")
    parser.add_argument('option', type=str, nargs="+")
    params, other = parser.parse_known_args(sys.argv[1:])
    print(params.option)
    options(params)