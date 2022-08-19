
def nondest_rotate_list(list_a, n):
    n = n % len(list_a)
    print(n)
    return list_a[len(list_a)-n:]+list_a[:len(list_a)-n]

def main():
    list_a = [1,2,3,4,5,6,7,8,9,10]
    n = -23
    print(nondest_rotate_list(list_a, n))
    # main()


if __name__ == '__main__':
    main()