n,p,q=(int (i) for i in raw_input().split(" "))
s=raw_input()
flag=0
for i in range(100):
    for j in range(100):
        if p*i+q*j==n:
            flag=1
            print i+j
            k=0
            while i>0:
                print s[k:k+p]
                k+=p
                i-=1
            while j>0:
                print s[k:k+q]
                k+=q
                j-=1
            exit(0)
if flag==0:
    print -1