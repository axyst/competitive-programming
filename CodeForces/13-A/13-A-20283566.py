def gcd(a,b):
    if b==0:
        return a
    return gcd(b,a%b)
n=int(input())
sum=0
for i in range(2,n):
    tem=n
    while tem:
        sum+=tem%i
        tem//=i
g=gcd(sum,n-2)
print("%d/%d"%(sum//g,(n-2)//g))