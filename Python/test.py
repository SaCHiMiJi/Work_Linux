

import math


def main():
    list_a = [1,2,3,4]
    list_b = [1,2,3]
    list_a.remove(list_b)
    print(list_a)


def base_b(x, b,i=0):
    a = int((x%b)*10**i)
    if x//b == 0:
        return a
    return base_b(x//b,b,i+1)+a

if __name__ == '__main__':
    main()
