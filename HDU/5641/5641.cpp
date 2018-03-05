#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <string>  
#include <cmath>  
#include <cstdlib>  
#include <ctime>  
#include <stack>  
using namespace std;  
typedef __int64 ll;  
  
int main()  
{  
    //freopen("in.txt","r",stdin);  
    //freopen("out.txt","w",stdout);  
    int t,k,i,n;  
    int s[20],vis[20],mp[20][20];  
    scanf("%d",&t);  
    memset(mp,0,sizeof(mp));  
    mp[1][3]=1,mp[3][1]=1,mp[1][7]=1,mp[7][1]=1;  
    mp[1][9]=1,mp[9][1]=1,mp[2][8]=1,mp[8][2]=1;  
    mp[4][6]=1,mp[6][4]=1,mp[7][9]=1,mp[9][7]=1;  
    mp[7][3]=1,mp[3][7]=1,mp[9][3]=1,mp[3][9]=1;  
      
    while(t--)  
    {  
        memset(s,0,sizeof(s));  
        int flag=1;  
        scanf("%d",&n);  
        for(i=1;i<=n;i++)  
        {  
            scanf("%d",&s[i]);  
            if(s[i]<=0 || s[i] > 9)  
            {     
                flag=0;  
            }  
        }  
        if(flag==0)  
        {  
            printf("invalid\n");  
            continue;  
        }  
        if(n>9)    
            flag=0;  
        else if(n<4)   
            flag=0;  
        else{   
            memset(vis,0,sizeof(vis));  
            vis[s[1]]=1;  
            int head=s[1];  
            for(i=2;i<=n;i++)  
            {  
                int mid=(head+s[i])/2;  
                if(vis[s[i]]==1)  
                {     
                    flag=0;  
                    break;  
                }  
                else if(mp[head][s[i]]==1 && vis[mid]==0 )  
                {  
                    flag=0;  
                    break;  
                }  
                else{  
                    vis[s[i]]=1;  
                    head=s[i];  
                }  
            }  
        }     
          
        if(flag==1)  
                printf("valid\n");  
            else  
                printf("invalid\n");  
    }  
    return 0;  
}  