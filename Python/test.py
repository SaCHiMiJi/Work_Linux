
def main():
    n = 1000
    nth_term(n)


def nth_term(n):
    i = cal_n(n)
    if i == 2:
        start_str = i *"3"
    else:
        start_str = (i-1)*("3")
    # print(start_str)
    i = 2**(i-1)
    # print(i)
    if i+1 != n:
        while(i <= n):
            start_str = plus_one(start_str)
            # print(i," : ",start_str)
            i+=1
        
    print(start_str)

def plus_one(text:str)->str:
    i = len(text)-1
    result = ""
    carry = 1
    while(i >= 0):
        # print(i)            
        if carry == 1 :
            if text[i] == "3":
                result += "4"    
                carry = 0
            else:
                result += "3"   
                carry = 1
        else:
            result += text[i]
        
        i-=1
    # print(result)
    if "3" not in result:
        # print("in")
        result = (len(result)+1)*"3"
    
    return result[::-1]


    
def cal_n(n):
    i = 1
    while(n>=2**i):
        i+=1
        # print("i :",i)
    return i


if __name__ == '__main__':
    main()
