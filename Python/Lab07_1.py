

def is_anagram(s1,s2,i=0):
    punctuation = "!#$%&'()*+,-./:;<=>?@[\]^_`{|}~ "
    s1,s2 = s1.lower(),s2.lower()
    s1,s2 = s1.translate(str.maketrans('', '', punctuation)),s2.translate(str.maketrans('', '', punctuation))
    s1,s2 = s1.replace(" ",""),s2.replace(" ","")
    if len(s1) == 0 :
        if len(s2) == 0:
            return True
        else:
            return False
    else:
        
        # print("\ni :",i)
        # print("s2 :",s2[i],"\ns1 :",s1[0])
        if s1[0] == s2[i]:
            if i == len(s2):
                return is_anagram(s1[1:],s2[0:i-1],i=0)
            else:
                return is_anagram(s1[1:],s2[0:i]+s2[i+1:len(s2)],i=0)
        else : 
            if i == len(s2)-1:
                return False
            else:
                return is_anagram(s1,s2,i+1)

def main():
    s1 = "ab cd"
    s2 = "BA DC"
    print(is_anagram(s1,s2))

if __name__ == '__main__':
    main()