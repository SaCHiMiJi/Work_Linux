
def nondest_rotate_list(list_a, n):
    n = n % len(list_a)
    return list_a[len(list_a)-n:]+list_a[:len(list_a)-n]

def main():
    list_a = [1,2,3,4]
    n = -1
    print(nondest_rotate_list(list_a, n))
    # main()


if __name__ == '__main__':
    main()