#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
    int l,r;cin>>l>>r;
    int ans;
    if(l==r) {printf("%d\n",l);return 0;}
    else if(l==r-3)
        if(l%3==0&&r%3==0) ans=3;
        else ans=2;
    else ans=2;
    printf("%d\n",ans);
    return 0;
}