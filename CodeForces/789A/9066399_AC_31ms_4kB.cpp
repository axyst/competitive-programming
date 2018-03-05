#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
    int n,k,w;scanf("%d%d",&n,&k);
	int ans=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&w);
		ans+=(w+k-1)/k;
	}
	printf("%d\n",(ans+1)/2);
    return 0;
}