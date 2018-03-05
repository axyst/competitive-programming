#include<bits/stdc++.h>
using namespace std;
map<int,bool>vis;
int main()
{
	int n,m,k,x;cin>>n>>m;
	bool y=0;
	for(int i=0;i<m;i++)
    {
        vis.clear();
        scanf("%d",&k);
        bool flag=0;
        for(int j=0;j<k;j++)
        {
            scanf("%d",&x);
            if(vis[-x]) flag=1;
            vis[x]=1;
        }
        if(!flag) y=1;
    }
    if(y) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
	return 0;
}