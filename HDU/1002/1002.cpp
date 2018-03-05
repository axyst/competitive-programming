#include<stdio.h>
#include<string.h>
int main()
{
    char op1[1002],op2[1002];
    int c,i,j,n,m,s1[1002],s2[1002],len1,len2,count;
    count=1;
    scanf("%d",&n);
    m=n;
    while(m--)
    {
        memset(s1,0,1002*sizeof(int));
        memset(s2,0,1002*sizeof(int));
        scanf("%s",op1);
        scanf("%s",op2);
        len1=strlen(op1);
        len2=strlen(op2);
        c=0;
        for(i=len1-1;i>=0;i--)
            s1[c++]=op1[i]-'0';
        c=0;
        for(i=len2-1;i>=0;i--)
            s2[c++]=op2[i]-'0';
        for(i=0;i<1002;i++)
        {
            s1[i]+=s2[i];
            if(s1[i]>=10)
            {
                s1[i]-=10;
                s1[i+1]++;
            }
        }
        printf("Case %d:\n",count++);
        printf("%s + %s = ",op1,op2);
        for(i=1001;i>=0;i--)
            if(s1[i])
                break;
        for(j=i;j>=0;j--)
            printf("%d",s1[j]);
        printf("\n");
        if(count!=n+1)
            printf("\n");
    }
    return 0;
}