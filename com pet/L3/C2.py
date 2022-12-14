
def gcd(x, y):
    while(y):
       x, y = y, x % y
    return abs(x)

x = str(input())
l = list(map(int,x.split()))
# print(l)
max_n = 0
for i in range(len(l)):
    for j in range(i):
        max_n = max(max_n,gcd(l[i],l[j]))
print(max_n)