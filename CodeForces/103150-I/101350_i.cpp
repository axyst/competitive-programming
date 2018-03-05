#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
#define For(i,a,b) for (int i=(a),_##i=(b); i<=_##i; ++i)
using namespace std;
typedef long long LL;
const int inf=0x3f3f3f3f;
const int maxn=1000+5;
char Ma[maxn*2];
int Mp[maxn*2];
char s[maxn];
char ids[]={'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};
char tmp[maxn];
bool isok(char a)
{
    for(int i=0;i<11;i++)
        if(a==ids[i]) return 1;
    return 0;
}
int Manacher(int len)
{
    int l=0;
	Ma[l++]='$';
	Ma[l++]='#';
	for(int i=0;i<len;i++)
	{
        Ma[l++]=tmp[i];
        Ma[l++]='#';
	}
	l--;
    int mxxx=0;
	int mx=0,id=0;
	for(int i=1;i<l;i++)
	{
		Mp[i]=mx>i?min(Mp[2*id-i],mx-i):1;
		while(Ma[i+Mp[i]]==Ma[i-Mp[i]])Mp[i]++;
		if(i+Mp[i]>mx)
		{
			mx=i+Mp[i];
			id=i;
		}
		mxxx=max(mxxx,Mp[i]);
	}
	return mxxx;
}
int main()
{
//#define LOCAL
    //std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("test.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        int len=strlen(s);int cnt=0;
        int ans=0;
        for(int i=0;i<len;i++)
        {
            if(isok(s[i]))
            {
                tmp[cnt++]=s[i];
                tmp[cnt]='\0';
                memset(Ma,0,sizeof(Ma));
                memset(Mp,0,sizeof(Mp));
                int tlen=strlen(tmp);
                ans=max(Manacher(tlen),ans);
            }
            else
            {
                tmp[0]='\0';
                cnt=0;
            }
        }
        if(!ans) printf("0\n");
        else printf("%d\n",ans-1);
    }
    return 0;
}