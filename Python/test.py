def main():
    # print("in 1")
    num1,num2,num3 = int(input("1:")),int(input("2:")),int(input("3:"))
    str = "1"+"2"
    print("str = ",str)
    
    print("a = {0},b = {1},c = {2}\na+b+c = {3}, {4}".format(num1,num2,num3,float(num1+num2+num3),str))
    
    
def test():
    # print("in 2")
    a = 2
    b = 3
    c = 4
    return a,b,c

main()