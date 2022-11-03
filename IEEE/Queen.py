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
    T = get_number()
    dict_r  = {}
    for i in range(T):
        k = get_number()
        a = get_number()
        b = get_number()
        c = 0
        d = 0
        
        dumy = set()
        while c != a:
            dumy.add(tuple(c,b))
            c+=1;
        while d != b:
            dumy.add(tuple(a,d))
            d+=1
        dumy.add(tuple(a,b)) 
        try:
            temp:set = dict_r[k]
            temp.add(dumy)
            dict_r[k] = set(temp)
        except:
            dict_r.update({k:dumy})
    print(dict_r)
    
main()