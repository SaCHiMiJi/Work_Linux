

def medal_allocation(list_a: list, result: list = []) -> list:
    list_a.sort(reverse=True)
    remove_zero(list_a)
    # print(list_a)
    num1 = list_a.count(list_a[0])
    # print(num1)
    result.append(list_a[0:num1])
    if len(list_a) == 0:
        gold = []
        silver = []
        bronze = []
    elif len(list_a) == 1:
        gold = [list_a[0]]
        silver = []
        bronze = []
    elif num1 >= 3:
        gold = list_a[num1]
        silver = []
        bronze = []
    else:
        # print(list_a[num1])
        num2 = list_a.count(list_a[num1])
        if list_a[num2+num1-1] == 0:
            
            silver = []
            bronze = []
        elif num1 == 2:
            
            silver = []
            bronze = [list_a[num1]]
        elif num2+num1 >= 2:
            
            silver = list_a[num1:num2+num1]
            bronze = []
        else:
            if list_a[num2+num1-1] == 0:
                bronze = []
            else:
                bronze = list_a[num1:num2+num1]
                num3 = list_a.count(list_a[num2+num1])
                bronze = list_a[num1+num2:num3+num2+num1]
    return tuple([gold] + [silver] + [bronze])

def remove_zero(list_x):
    if 0 not in list_x:
        return list_x
    else:
        list_x.remove(0)
        return remove_zero(list_x)

def main():
    list_a = [ 0, 0, 3, 0]
    
    print(medal_allocation(list_a))


if __name__ == '__main__':
    main()
