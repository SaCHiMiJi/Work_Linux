
def median_of_median(list_a:list, i:int=0, list_b:list = [])->float:
    
    if len(list_a) == 1:
        return list_a[0]
    
    elif i//3 == len(list_a)//3:
        
        list_a = list_b
        return median_of_median(list_a, 0, [])
    else:
        
        if len(list_a)%3 != 0 and i == len(list_a)//3*3-3:
            over_list = sum(list_a[i+2:])/(len(list_a)%3+1)
            list_c = list_a[i:i+2] + [over_list]
            sum_list = sum(list_c) 
            sum_list -= max(list_c)+ min(list_c)
            
        else:
            sum_list = sum(list_a[i:i+3])
            sum_list -= max(list_a[i:i+3])+ min(list_a[i:i+3])
            
        list_b.append(sum_list)
        return median_of_median(list_a, i+3, list_b)

def main():
    list_a = [28, 14,  13,  21,  19,  27,  23,  30,  16,  31, 1]
    print(median_of_median(list_a))


if __name__ == '__main__':
    main()