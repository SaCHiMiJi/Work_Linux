

# case  : 1_normal
# case  : 1_sp
# case  : nothing


def main():
    
    skill_map_lv = int(input())
    has_cloak = str(input())
    speed = int(input())
    has_zoomer = str(input())
    
    catch_normal = normal_tun(skill_map_lv,has_cloak,speed,has_zoomer)

    if catch_normal == True :
        print("Normal Moly!!!")
    if catch_normal == False :
        print("try again")

def normal_tun(skill_map_lv,has_cloak,speed,has_zoomer):
    if has_cloak == "Y":
        return True
    else : #has_cloak == "N"
        if has_zoomer == "N":
            if speed <= 2:
                return True
            if skill_map_lv < 4 or speed >2:
                return False

        if has_zoomer == "Y":
            if skill_map_lv < 2 :
                return False
        else :
            return True


                
main()
            
# if __name__ == '__main__':
#     main()