

def dest_rotate_list(list_a:list, n:int):
    n = n % len(list_a)
    
    x = list_a[len(list_a)-n:]+list_a[:len(list_a)-n]
    # print(x)
    list_a.clear()
    list_a.extend(x)


def main():
    list_a = [1,2,3,4, 5]
    n = -3
    dest_rotate_list(list_a, n)
    print(list_a)
    # main()


if __name__ == '__main__':
    main()