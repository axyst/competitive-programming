stick=input().split()
def check(x,y,z):
    if x+y>z and x+z>y and y+z>x:
        return 1
    return 0
def judge(x,y,z):
    if x+y==z or x+z==y or y+z==x:
        return 1
    return 0
ans="IMPOSSIBLE"
for i in range(4):
    for j in range(i+1,4):
        for k in range(j+1,4):
            if check(int(stick[i]),int(stick[j]),int(stick[k])):
                ans="TRIANGLE"
            if ans=="IMPOSSIBLE" and judge(int(stick[i]),int(stick[j]),int(stick[k])):
                ans="SEGMENT"
print(ans)