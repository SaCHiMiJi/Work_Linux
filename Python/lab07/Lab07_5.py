

def longest_digit_run(n,i=1, max=0, curr=1) :
    n = str(n)
    if len(n) == 1:
        return 1
    if len(n) == i:
        if curr > max:
            max = curr
        return max
    if i>0:
        if n[i] == n[i-1]:
            curr += 1
            # print(curr)
            return longest_digit_run(n, i+1, max, curr)
        else :
            # print(max)
            if curr > max:
                max = curr
            return longest_digit_run(n, i+1, max, 1)
    
    
def main():
    n = 11111444445555566666000000
    print(longest_digit_run(n))
    
if __name__ == '__main__':
    main()