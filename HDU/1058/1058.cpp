#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int hum[6000];
void cal()
{
    hum[1]=1;
    int c2,c3,c5,c7,t0,t1,t2,t3;
    c2=c3=c5=c7=1;
    for(int i=2;i<=5842;i++)
    {
        t0=2*hum[c2];
        t1=3*hum[c3];
        t2=5*hum[c5];
        t3=7*hum[c7];
        hum[i]=min(min(t0,t1),min(t2,t3));
        if(hum[i]==t0) c2++;
        if(hum[i]==t1) c3++;
        if(hum[i]==t2) c5++;
        if(hum[i]==t3) c7++;
    }
}
int main()
{
    int n,ca=1;
    cal();
    //sort(hum+1,hum+5843);
    while(scanf("%d",&n)&&n)
    {
        if(n%10==1&&n%100!=11) printf("The %dst humble number is %d.\n",n,hum[n]);
        else if(n%10==2&&n%100!=12) printf("The %dnd humble number is %d.\n",n,hum[n]);
        else if(n%10==3&&n%100!=13) printf("The %drd humble number is %d.\n",n,hum[n]);
        else printf("The %dth humble number is %d.\n",n,hum[n]);
    }
    return 0;
}