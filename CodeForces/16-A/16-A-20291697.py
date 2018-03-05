n,m=list(map(int,input().split()))
ans="YES"
for i in range(n):
    str=input()
    for j in range(1,len(str)):
        if str[0]!=str[j]:
            ans="NO"
    if i>0 and pre==str:
            ans="NO"
    pre=str
print(ans)