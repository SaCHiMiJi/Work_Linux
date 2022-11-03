# a simple parser for python. use get_number() and get_word() to read
def parser():
    while 1:
        data = list(input().split(' '))
        for number in data:
            if len(number) > 0:
                yield(number)   

input_parser = parser()

def get_word():
    global input_parser
    return next(input_parser)

def get_number():
    data = get_word()
    try:
        return int(data)
    except ValueError:
        return float(data)



# numpy and scipy are available for use

# import numpy
# import scipy
def main():
    # print(2**10000%(10**9 + 7))
    N = get_number()
    M = get_number()
    x_list = []
    mod_num = 10**9 + 7
    sum_n = 0
    for i in range(N):
        X = get_number()
        x_list.append(2**X)
    if M == 1:
        
        sum_n = sum(x_list)
        print(sum_n%mod_num)
    elif M == N :
        
        result = max(x_list)
        print(result%mod_num)
    elif M>N:
        while(len(N)>M-1):
            sum_n += x_list[i]
        # result = sum_n / N
        print(result%mod_num)
    elif M<N:
        result_list = []
        for i in x_list:
            result_list.append(i)
        result = result / M
        result = sum(result_list) % mod_num
        print(result)
    else:
        print(0)

main()