def moving_average(list_a:list, w:int, i:int=0,result:list=[])->list:
    # print((list_a[i:w+i]))
    result.append(float(int(sum(list_a[i:w+i])/w*10)/10))
    if len(list_a) < w:
        return 
    if len(list_a) == w:
        result = [sum(list_a)/w]
        return  result
    if i+1 == len(list_a)-w:
        return result
    else:
        return moving_average(list_a,w,i+1,result)


    
def main():
    list_a = [1, 2, 3, 4, 5, 6, 7, 9]
    w = 5
    
    print(moving_average(list_a, w))


if __name__ == '__main__':
    main()
