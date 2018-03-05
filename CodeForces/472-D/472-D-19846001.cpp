/*
将1作为根，对于任意两点存在两种关系：
1.一个点位于另一个点的子树上。两点到1的距离之差绝对值等于两点距离。
2.两个点在某一个点的不同子树上。两点到1距离之和减去两点距离等于两倍某个点到1的距离。
*/
#include<iostream>  
#include<cstdio>  
#include<cstdlib>  
#include<string.h>  
#include<math.h>  
#include<algorithm>  
#include<vector>  
#include<queue>  
#include<map>  
using namespace std;  
int n;  
long long mp[2005][2005];  
map <long long,int> m;  
int main()  
{  
    int n;  
    cin>>n;  
    for(int i=1;i<=n;i++)  
        for(int j=1;j<=n;j++)  
            scanf("%I64d",&mp[i][j]);  
    for(int i=1;i<=n;i++)  
        for(int j=1;j<=n;j++)  
        {  
            if((i==j && mp[i][j]) || (i!=j && mp[i][j]==0) || mp[i][j]!=mp[j][i])  
            {  
                cout<<"NO"<<endl;  
                return 0;  
            }  
        }  
    for(int i=1;i<=n;i++)  
        m[2*mp[1][i]]=1;  
    for(int i=1;i<=n;i++)  
    {  
        for(int j=1;j<=n;j++)  
        {  
            if((mp[i][j]==abs(mp[1][i]-mp[1][j])) || m[mp[1][j]+mp[1][i]-mp[i][j]])continue;  
            cout<<"NO"<<endl;  
            return 0;  
        }  
    }  
    cout<<"YES"<<endl;  
    return 0;  
}