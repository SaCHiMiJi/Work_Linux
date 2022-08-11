

def medal_allocation(list_a: list, result: list = []) -> list:
    list_a = list_a.sort()
    num1 = list_a.count(list_a[0])
    # print(num1)
    result.append(list_a[0:num1])
    if list_a[0] == 0:
        result = [[], [], []]
    elif num1 >= 3:
        result.append([])
        result.append([])
    else:
        # print(list_a[num1])
        num2 = list_a.count(list_a[num1])
        if list_a[num2+num1-1] == 0:
            
            result.append([])
            result.append([])
        elif num1 == 2:
            
            result.append([])
            result.append([list_a[num1]])
        elif num2+num1 >= 2:
            
            result.append(list_a[num1:num2+num1])
            result.append([])
        else:
            if list_a[num2+num1-1] == 0:
                result.append([])
            else:
                result.append(list_a[num1:num2+num1])
                num3 = list_a.count(list_a[num2+num1])
                result.append(list_a[num1+num2:num3+num2+num1])
    return result


def main():
    list_a = [9, 8, 8,  7, 7, 7, 6, 5, 4, 3, 2]
    print(medal_allocation(list_a))


if __name__ == '__main__':
    main()
