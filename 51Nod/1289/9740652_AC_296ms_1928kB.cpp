#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=100005;
int main()
{
    ios::sync_with_stdio(false);
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while(scanf("%d",&n)==1)
    {
        int ans=n;
        stack<int>st;int a,b;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            if(!b)
            {
                while(!st.empty())
                {
                    ans--;
                    if(a>st.top()) st.pop();
                    else break;
                }
            }
            else st.push(a);
        }
        cout<<ans<<endl;
    }
}
