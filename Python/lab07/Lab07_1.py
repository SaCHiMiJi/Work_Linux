

def is_anagram(s1:str,s2:str)->bool:
    s1 = s1.replace(" ","").lower()
    s2 = s2.replace(" ","").lower()
    if len(s1) == 0 and len(s2) == 0:
        return True
    if len(s1) != len(s2):
        return False
    else:
        s2 = s2.replace(s1[0],"")
        s1 = s1.replace(s1[0],"")
        return is_anagram(s1,s2)


    

def main():
    s1 = "ab cdqweqwe"
    s2 = "BA DCewqewq"
    print(is_anagram(s1,s2))

if __name__ == '__main__':
    main()