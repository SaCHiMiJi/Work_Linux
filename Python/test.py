
def main():
    p_num = str(input())
    type_p = str(input())
    l_pnum = len(p_num)
    result = ""
    if l_pnum == 10:
        result = "0{0} {1} {2}".format(p_num[1], p_num[l_pnum-8: l_pnum-4], p_num[l_pnum-4: l_pnum])
    else:# case l_pnum
        result = "0 {0} {1}".format(p_num[l_pnum-8: l_pnum-4], p_num[l_pnum-4: l_pnum])
    if type_p == "International":
        result = result.replace("0", "+66",1)
    print(result)


if __name__ == '__main__':
    main()
