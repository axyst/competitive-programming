#include<bits/stdc++.h>

using namespace std;
int n;
char a[80],b[80];

long long get(int t,char a[]){
    if (t==1) {
        return a[n-1]-'0';
    }
    if (a[n-t]=='0') return get(t-1,a); else {
        return (1LL<<t)-get(t-1,a)-1LL;
    }
}
int main()
{
    scanf("%d%s%s",&n,a,b);
    int ans=1;
    for (int i=0;i<n;i++){
        if (a[i]!=b[i]) ans++;
    }
    long long ansa=get(n,a);
    long long ansb=get(n,b);
    cout<<ansb-ansa-1LL<<endl;
    return 0;
}