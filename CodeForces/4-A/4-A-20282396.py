n=int(input())
flag=0
for i in range(2,n):
    if i%2==0 and (n-2)%2==0:
        flag=1
        break
if flag:
    print("YES")
else:
    print("NO")