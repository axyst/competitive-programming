n,t=map(int,input().split())
list=[]
for i in range (n):
    x,a=map(int,input().split())
    list.append((x-a/2,x+a/2))
list.sort()
ans=2
for i in range(n-1):
    dis=list[i+1][0]-list[i][1]
    if dis>t:
        ans+=2
    elif dis==t:
        ans+=1
print(ans)