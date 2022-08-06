

def nondest_rotate_list(list_a:list, n:int, i:int=0, x:list=[],state:str ="set"):
    if state == "set":
        n = n % len(list_a)
        x = list_a[len(list_a)-n:]+list_a[:len(list_a)-n]
        list_a.clear()
        return nondest_rotate_list(list_a, n, i, x, state="do")
    elif state == "do":

        if i == len(x):
            return 0;
        else:
            list_a.append(x[i])
            # print(list_a)
            return nondest_rotate_list(list_a, n, i+1, x, state="do")

def main():
    list_a = [1,2,3,4]
    n = -1
    nondest_rotate_list(list_a, n)
    print(list_a)
    # main()


if __name__ == '__main__':
    main()