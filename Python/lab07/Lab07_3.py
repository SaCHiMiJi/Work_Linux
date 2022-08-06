

def uniform(line,i = 0, x ='first'):
        if (x == "first"):
            num = uniform(line,i = 0, x ='sec')
            if num == 0:
                if line[0].isupper():
                    return line.upper()
                else:
                    return line.lower()
            elif num > 0:
                return line.upper()
            else :
                return line.lower()
        elif (x == "sec"):
            if i == len(line)-1:
                if line[i].isupper():
                    return 1
                else:
                    return -1
            elif line[i].isupper():
                return uniform(line,i+1, x ='sec')+1
            elif line[i].islower() :
                return uniform(line,i+1, x ='sec')-1
            else:
                return uniform(line,i+1, x ='sec')

def main():
    line = str(input())
    print(uniform(line))
    main()
    
if __name__ == '__main__':
    main()