

def is_anagram(s1:str,s2:str,i:int =0,state:str = "set")->bool:
    if state == "set":
        s1,s2 = check_punctuation(s1),check_punctuation(s2)
        return is_anagram(s1,s2,i,state = "cal")
    elif state == "cal":
        # print("i : ",i)
        # print(s1 , s2)
        
        if len(s1) == 0 :
            if len(s2) == 0:
                return True
            else:
                return False
        if s1[0] == s2[i]:
            # print("s1[0]",s1[0])
            
            if i == 0:
                return is_anagram(s1[1:],s2[1:],0,"cal")
            else:
                s2 = s2.replace(s1[0],"",i+1)
                return is_anagram(s1[1:],s2,0,"cal")
        else:
            return is_anagram(s1,s2,i+1,"cal")
            
            
def check_punctuation(str_s,i=0):
    punctuation = "!#$%&'()*+,-./:;<=>?@[\]^_`{|}~ "
    # print("i : ",i)
    # print("len(str_s) : ",len(str_s))
    if i == len(str_s):
        str_s = str_s.lower()
        return str_s
    
    if str_s[i] in punctuation:
        str_s = str_s.replace(str_s[i],"")
        # print("str_s",str_s)
        return check_punctuation(str_s,i-1)
    else:
        return check_punctuation(str_s,i+1)
    

def main():
    s1 = "ab cdqweqwe"
    s2 = "BA DCewqewq"
    print(check_punctuation(s1))
    print(check_punctuation(s2))
    print(is_anagram(s1,s2))

if __name__ == '__main__':
    main()