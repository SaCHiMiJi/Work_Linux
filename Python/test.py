

import math


def main():
    # print("in 1")
    a = int(input())
    b = int(input())
    print(base_b(a, b))


def base_b(x, b,i=0):
    a = int((x%b)*10**i)
    if x//b == 0:
        return a
    return base_b(x//b,b,i+1)+a

if __name__ == '__main__':
    main()
