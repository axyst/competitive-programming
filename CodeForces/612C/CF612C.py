s=raw_input()
dic={'}': '{',')': '(','>': '<',']':'['}
st=[]
ans=0
for item in s:
    if item in dic.values():
        st.append(item)
    else:
        if len(st)>0:
            if dic[item]!=st.pop():
                ans+=1
        else:
            ans-=1
if len(st)>0 or ans<0:
    print 'Impossible'
else:
    print ans