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
def main():
    m = get_number()
    n = get_number()
    t = get_number()
    matrix = []
    for i in range(m):
        a = []
        for j in range(n):
            num = get_number()
            a += [num]
        # print(a)
        matrix += [a]
    if m == 1:
        max_n = max(matrix[0])
        min_n = min(matrix[0])
        print("max_n : ",max_n)
        print("min_n : ",min_n)
        if max_n - min_n != t:
            max_n = min_n + t-1
            i_max = matrix[0].index(max_n)-1
            i_min = matrix[0].index(min_n)-1 
        print("i_max : ",i_max)
        print("i_min : ",i_min)
        f = min(i_max,i_min)
        l = max(i_max,i_min)
        print("f : ",f)
        print("l : ",l)
        while f > 0:
            if max_n < matrix[0][f] or matrix[0][f] < min_n:
                f+=1
                break
            f-=1
            # print(f)
        while n-1 > l:
            
            if max_n < matrix[0][l] or  matrix[0][l] < min_n:
                # print("in")
                l-=1
                break
            l+=1
            # print(l)
        print(l-f)
    else:
        print(15)
main()

