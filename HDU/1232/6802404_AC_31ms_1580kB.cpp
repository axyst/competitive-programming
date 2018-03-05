#include<bits/stdc++.h>
using namespace std;
int aset[1005];
int Find(int a)
{
    if(aset[a]) return Find(aset[a]);
    return a;
}
void Merge(int a,int b)
{
    int a1=Find(a),b1=Find(b);
    if(a1!=b1) aset[a1]=b1;
}
int main()
{
    int n,m,a,b;
    while(scanf("%d",&n)&&n)
    {
        scanf("%d",&m);
        memset(aset,0,sizeof(aset));
        while(m--)
        {
            scanf("%d%d",&a,&b);
            Merge(a,b);
        }
        int ans=-1;
        for(int i=1;i<=n;i++) if(!aset[i]) ans++;
        printf("%d\n",ans);
    }
    return 0;
}
