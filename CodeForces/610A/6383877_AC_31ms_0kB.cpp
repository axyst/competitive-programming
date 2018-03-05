#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main ()  
{  
    int n;  
    scanf("%d",&n);  
    if(n%2!=0) printf("0\n");  
    else  
    {  
        n/=2;  
        printf("%d\n",(n-1)/2);  
    }  
}  