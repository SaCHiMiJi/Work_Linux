
from operator import le


def median_of_median(list_a: list) -> float:
    n = len(list_a) // 3
    if len(list_a) < 3:
        return mid_num(list_a)
    else:
        mid_n1 = median_of_median(list_a[0:n*(1)])
        mid_n2 = median_of_median(list_a[n:n*(2)])
        mid_n3 = median_of_median(list_a[n*2:])
        list_b = [mid_n1]+[mid_n2]+[mid_n3]
        return mid_num(list_b)


def mid_num(list_num: list):
    if len(list_num) == 2:
        num = sum(list_num)/2
        return num
    if len(list_num) == 1:
        return list_num[0]
    else:
        list_num.remove(max(list_num))
        list_num.remove(min(list_num))
        return mid_num(list_num)


def main():
    list_a = [28, 14, 13, 22, 20, 23, 17, 18, 19, 16, 15, 12, 13, 18, 20]
    print(len([1, 2, 3, 4, 5.5]))
    print(median_of_median(list_a))
    print(median_of_median([28, 14, 13, 21, 20, 23, 17, 18, 19, 16, 15, 12]))
    print(median_of_median([1, 2, 3]))
    print(median_of_median([28, 14, 13, 22, 10]))


if __name__ == '__main__':
    main()
