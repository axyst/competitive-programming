#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
char str[2020];
int out[7][2020];
int main()
{
    //freopen("test.txt","r",stdin);
    int n;
    while(scanf("%d",&n)==1)
    {
        scanf("%s",str);
        for(int i=0;i<n;i++)
        {
            int id=str[i]-'A';
            if(id==0) out[0][i]=out[1][i]=out[2][i]=out[3][i]=out[4][i]=0;
            else if(id==1) out[0][i]=out[1][i]=out[2][i]=out[3][i]=out[4][i]=1;
            else if(id==2) out[0][i]=out[1][i]=out[2][i]=out[3][i]=out[4][i]=2;
            else if(id==3) out[0][i]=out[1][i]=out[2][i]=out[3][i]=out[4][i]=3;
            else if(id==4) out[0][i]=out[1][i]=out[2][i]=out[3][i]=out[4][i]=4;
        }
        for(int i=0;i<5;i++)
        {
            if(i==0)
            {
                for(int j=0;j<n;j++)
                {
                    printf("***");
                }

            }
            else if(i==1)
            {
                for(int j=0;j<n;j++)
                    if(out[i][j]==0) printf("*.*");
                    else if(out[i][j]==1) printf("*.*");
                    else if(out[i][j]==2) printf("*..");
                    else if(out[i][j]==3) printf("*.*");
                    else if(out[i][j]==4) printf("*..");
            }
            else if(i==2)
            {
                for(int j=0;j<n;j++)
                    if(out[i][j]==0) printf("***");
                    else if(out[i][j]==1) printf("***");
                    else if(out[i][j]==2) printf("*..");
                    else if(out[i][j]==3) printf("*.*");
                    else if(out[i][j]==4) printf("***");
            }
            else if(i==3)
            {
                for(int j=0;j<n;j++)
                    if(out[i][j]==0) printf("*.*");
                    else if(out[i][j]==1) printf("*.*");
                    else if(out[i][j]==2) printf("*..");
                    else if(out[i][j]==3) printf("*.*");
                    else if(out[i][j]==4) printf("*..");
            }
            else if(i==4)
            {
                for(int j=0;j<n;j++)
                    if(out[i][j]==0) printf("*.*");
                    else if(out[i][j]==1) printf("***");
                    else if(out[i][j]==2) printf("***");
                    else if(out[i][j]==3) printf("***");
                    else if(out[i][j]==4) printf("***");
            }
            printf("\n");
        }

    }
    return 0;
}