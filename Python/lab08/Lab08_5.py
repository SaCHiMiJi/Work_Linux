

def medal_allocation(list_a: list, result: list = []) -> list:
    print(list_a)
    list_b = list_a.sort(reverse=True)
    print(list_b)
    num1 = list_b.count(list_b[0])
    # print(num1)
    result.append(list_b[0:num1])
    if list_b[0] == 0:
        result = [[], [], []]
    elif num1 >= 3:
        result.append([])
        result.append([])
    else:
        # print(list_b[num1])
        num2 = list_b.count(list_b[num1])
        if list_b[num2+num1-1] == 0:
            
            result.append([])
            result.append([])
        elif num1 == 2:
            
            result.append([])
            result.append([list_b[num1]])
        elif num2 >= 2:
            # print("in")
            result.append(list_b[num1:num2+num1])
            result.append([])
        else:
            
            if list_b[num2+num1] == 0:
                
                result.append([])
            else:
                
                result.append(list_b[num1:num2+num1])
                num3 = list_b.count(list_b[num2+num1])
                result.append(list_b[num1+num2:num3+num2+num1])
    return tuple(result)


def main():
    list_a = [9, 8, 7, 7, 7, 6, 5, 4, 3, 2]
    print(medal_allocation(list_a))


if __name__ == '__main__':
    main()
