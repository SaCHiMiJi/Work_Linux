

def dest_rotate_list(list_a:list, n:int,i:int=0 ):
    if i == 0:
        n = n % len(list_a)
        # x = list_a[len(list_a)-n:]+list_a[:len(list_a)-n]
        list_a.extend(list_a[:len(list_a)-n])
        dest_rotate_list(list_a, n,i +1)
    elif i != len(list_a)-1:
        list_a.pop(0)
        dest_rotate_list(list_a, n,i +1)


def main():
    list_a = [1,2,3,4, 5]
    n = -3
    dest_rotate_list(list_a, n)
    print(list_a)
    # main()


if __name__ == '__main__':
    main()