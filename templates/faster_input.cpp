#include<bits/stdc++.h>
//fread
char buf[100000],*p1=buf,*p2=buf;
inline char nc()
{
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline bool rea(int & x)
{
    bool isN=false;
    char c=nc();x=0;
    if(c==EOF) return false;
    if(c=='-') isN=true;
    for(;!isdigit(c);c=nc());
    for(;isdigit(c);x=x*10+c-'0',c=nc());
    if(isN) x=-x;
    return true;
}
inline bool rea(LL & x)
{
    bool isN=false;
    char c=nc();x=0;
    if(c==EOF) return false;
    if(c=='-') isN=true;
    for(;!isdigit(c);c=nc());
    for(;isdigit(c);x=x*10+c-'0',c=nc());
    if(isN) x=-x;
    return true;
}
//getchar
inline bool scand(int &num)
{
    char in;bool IsN=false;
    in=getchar();
    if(in==EOF) return false;
    while(in!='-'&&(in<'0'||in>'9')) in=getchar();
    if(in=='-'){ IsN=true;num=0;}
    else num=in-'0';
    while(in=getchar(),in>='0'&&in<='9')
        num*=10,num+=in-'0';
    if(IsN) num=-num;
    return true;
}
inline bool scanl(LL &num)
{
    char in;bool IsN=false;
    in=getchar();
    if(in==EOF) return false;
    while(in!='-'&&(in<'0'||in>'9')) in=getchar();
    if(in=='-'){ IsN=true;num=0;}
    else num=in-'0';
    while(in=getchar(),in>='0'&&in<='9')
        num*=10,num+=in-'0';
    if(IsN) num=-num;
    return true;
}
inline bool scandd(double &num)
{
    char in;double Dec=0.1;
    bool IsN=false,IsD=false;
    in=getchar();
    if(in==EOF) return false;
    while(in!='-'&&in!='.'&&(in<'0'||in>'9'))
        in=getchar();
    if(in=='-'){IsN=true;num=0;}
    else if(in=='.'){IsD=true;num=0;}
    else num=in-'0';
    if(!IsD)
        while(in=getchar(),in>='0'&&in<='9')
            num*=10;num+=in-'0';
    if(in!='.')
    {
        if(IsN) num=-num;
        return true;
    }
    else
        while(in=getchar(),in>='0'&&in<='9')
            num+=Dec*(in-'0');Dec*=0.1;
    if(IsN) num=-num;
    return true;
}
