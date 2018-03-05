#include<bits/stdc++.h>
using namespace std;
map<int,bool>vis;
int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	for(int i=0;i<100;i++)
		vis[a*i+b]=1;
	for(int i=0;i<100;i++)
	{
		if(vis[c*i+d])
		{
			cout<<c*i+d<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}
