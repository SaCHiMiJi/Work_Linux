def moving_average(list_a:list, w:int, i:int=0)->list:
    # print((list_a[i:w+i]))
    num = float(sum(list_a[i:w+i])/w)
    if len(list_a) < w:
        return 
    if len(list_a) == w:
        return  [sum(list_a)/w]
    if i+w == len(list_a):
        return [num]
    else:
        return [num] + moving_average(list_a,w,i+1) 


    
def main():
    list_a = [1, 2, 3, 4, 5, 6, 7, 8, 9]
    w = 4
    
    print(moving_average(list_a, w))


if __name__ == '__main__':
    main()
