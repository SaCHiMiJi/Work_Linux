def triangle(n,row = 0):
    if row == 0:
        str = "*\n"
        return str + triangle(n,row+1)
    elif row == n-1:
        str = "* "*(n-1)+"*\n"
        return str
    str= "*"+"."*(2*row-1)+"*\n"
    return str+triangle(n,row+1)

def main():
    # s = 100#int(input())
    # for s in range(1000):
    #     print("s : ",s)
    #     print(triangle(s))
    print(triangle(int(input())))
    main()

if __name__ == '__main__':
    main()