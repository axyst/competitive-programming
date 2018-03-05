#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=50000+5;
struct st
{
    int a;int b;
}s1[maxn],s2[maxn];
bool cmp1(st x,st y)
{
    return x.a<y.a;
}
bool cmp2(st x,st y)
{
    return x.b>y.b;
}
int main()
{
    //std::ios::sync_with_stdio(false);
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
   int n,a,b;
   while(scanf("%d",&n)==1)
    {
        int cs1=0,cs2=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            if(a<b){s1[cs1].a=a;s1[cs1].b=b;cs1++;}
            else{s2[cs2].a=a;s2[cs2].b=b;cs2++;}
        }
        sort(s1,s1+cs1,cmp1);
        sort(s2,s2+cs2,cmp2);
        int ans=0,tmp=0;
        for(int i=0;i<cs1;i++)
        {
            tmp+=s1[i].a;
            ans=max(ans,tmp);
            ans+=s1[i].b;
            //cout<<ans<<endl;
        }
        for(int i=0;i<cs2;i++)
        {
            tmp+=s2[i].a;
            ans=max(ans,tmp);
            ans+=s2[i].b;
            //cout<<ans<<endl;
        }
        printf("%d\n",ans);
    }
    return 0;
}