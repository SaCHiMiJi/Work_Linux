
def patterned_message(message, pattern,i=0,j=0):
    message = message.replace(" ","")
    
    if len(pattern)-1 == j :
        return 0
    if pattern[j] == "\n":
        print("\n",end = "")
        return patterned_message(message, pattern,i,j+1)
    elif pattern[j] == " ":
        print(" ",end = "")
        return patterned_message(message, pattern,i,j+1)
    elif pattern[j] == "*":
        print(message[i],end = "")
        if i == len(message)-1:
            return patterned_message(message, pattern,0,j+1)
        else:
            return patterned_message(message, pattern,i+1,j+1)
    

def main():
    message = "D and C"
    pattern = '''
    ***************
    ******   ******
    ***************
    '''
    patterned_message(message, pattern)


if __name__ == '__main__':
    main()
