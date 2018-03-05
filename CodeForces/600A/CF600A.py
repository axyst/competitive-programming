from __future__ import print_function
import re
myinput=raw_input()
mylist=re.split(',|;',myinput)
# print (mylist,end='\n')

first='-'
second='-'
for item in mylist:
    if item=='0':
        if first=='-':
            first=item
        else:
            first+=','+item
    elif not item.startswith('0') and item.isdigit():
        if first=='-':
            first=item
        else:
            first+=','+item
    elif item!='':
        if second=='-':
            second=item
        else:
            second+=','+item
    elif second=='-':
        second=''
    else:
        second+=','
        
if first=='-':
    print('-',end='\n')
else:
    print ('"',end='')
    print (first,end='')
    print ('"',end='\n')

if second=='-':
    print('-',end='\n')
else:
    print ('"',end='')
    print (second,end='')
    print ('"',end='\n')