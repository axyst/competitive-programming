#include<bits/stdc++.h>  
using namespace std;  
double mat[1005][1005];  
void Floyd(int n)  
{  
    for(int k=1;k<=n;k++)  
        for(int i=1;i<=n;i++)  
            for(int j=1;j<=n;j++)  
                mat[i][j]=max(mat[i][j],mat[i][k]*mat[k][j]);  
}  
int main()  
{  
    int n;  
    while(scanf("%d",&n)!=EOF)  
    {  
        double tem;  
        for(int i=1;i<=n;i++)  
            for(int j=1;j<=n;j++)  
                scanf("%lf",&mat[i][j]);  
        Floyd(n);  
        int t;  
        scanf("%d",&t);  
        while(t--)  
        {  
            int t1,t2;  
            scanf("%d%d",&t1,&t2);  
            if(mat[t1][t2]) printf("%.3lf\n",mat[t1][t2]);  
            else printf("What a pity!\n");  
        }  
    }  
    return 0;  
}