def parser():
    while 1:
        data = list(input().split(' '))
        for number in data:
            if len(number) > 0:
                yield(number)   

input_parser = parser()

def get_word():
    global input_parser
    return next(input_parser)

def get_number():
    data = get_word()
    try:
        return int(data)
    except ValueError:
        return float(data)
    

def print_human(l_list):
    
    for i in range(len(l_list)):
        for j in range(len(l_list)):
            print(l_list[i][j],end="")
            if j == len(l_list)-1:
                print()
                
def dance(l_text,list_h):
    print()
    if 'right' in l_text :
        if ('leg' in l_text):
            if ('in' in l_text):
                list_h[2][0] = '<'
            else:
                list_h[2][0] = '/'
        else:
            if ('head' in l_text):
                list_h[0][0] = "("
                list_h[1][0] = " "
            elif ('start' in l_text):
                list_h[1][0] = "/"
                list_h[0][0] = ' '
            else:
                list_h[1][0] = "<"
                list_h[0][0] = ' '

    elif 'left' in l_text :
        if ('leg' in l_text):
            if ('in' in l_text ):
                list_h[2][2] = '>'
            else:
                list_h[2][2] = '\\'
        else:
            if ('head' in l_text):
                list_h[0][2] = ")"
                list_h[1][2] = " "
            elif ('start' in l_text):
                list_h[1][2] = "\\"
                list_h[0][2] = ' '
            else:
                list_h[1][2] = ">"
                list_h[0][2] = ' '
    else:
        list_h[0][0],list_h[0][2] = list_h[0][2],list_h[0][0]
        list_h[1][0],list_h[1][2] = list_h[1][2],list_h[1][0]
        list_h[2][0],list_h[2][2] = list_h[2][2],list_h[2][0]
                
        hand_l_up = False
        hand_r_up = False
        
        if list_h[0][0] == ")":
            list_h[0][0] = '('
            hand_r_up = True
        if list_h[0][2] == '(':
            list_h[0][2] = ')'
            hand_l_up = True
        if list_h[1][0] == '\\':
            list_h[1][0] = '/'
            hand_r_up == False
        if list_h[1][2] == '/':
            list_h[1][2] = '\\'
            hand_l_up == False

        if list_h[1][0] == '>' and hand_r_up == False:        
            list_h[1][0] = '<'
        if list_h[1][2] == '<' and hand_l_up == False:
            list_h[1][2] = '>'

        if list_h[2][0] == '\\':
            list_h[2][0] = '/'
        if list_h[2][2] == '/':   
            list_h[2][2] = '\\'
        
        if list_h[2][0] == '>':
            list_h[2][0] = '<'
        elif list_h[2][2] == '<':
            list_h[2][2] = '>'

    act = ""
    for i in range(len(list_h)):
        for j in range(len(list_h)):
           act += list_h[i][j]
        act += "\n"
    
    return act

    
T = get_number()
# print_human(list_h)
for j in range(T):
    d = get_number()
    list_h = [" ","o"," "],["/","|","\\"],["/"," ","\\"]
    
    # aws_text = []
    for k in range(d):

        text = str(input());
        l_text = []
        try:
            l_text = text.split(" ")
            l_text = list(set(l_text))
        except:
            l_text = [text]
        
        if "say" in l_text:
            print(text[4:])
        else:
            # print(l_text)
            textout = dance(l_text,list_h)
            textout = textout.strip("\n")
            print(textout)
              

                    

            


