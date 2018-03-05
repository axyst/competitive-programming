#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char one[100][50];
char two[100][50];
int main()
{
    //freopen("test.txt","r",stdin);
    int k1,k2;scanf("%d%d",&k1,&k2);
    getchar();
    int wk=0,wq=0,wb=0,wn=0,wr=0,wp=0;
    int bk=0,bq=0,bb=0,bn=0,br=0,bp=0;
    int wk2=0,wq2=0,wb2=0,wn2=0,wr2=0,wp2=0;
    int bk2=0,bq2=0,bb2=0,bn2=0,br2=0,bp2=0;
    for(int i=0;i<k1;i++)
    {
        gets(one[i]);
        if(strcmp(one[i],"black king")==0) bk++;
        else if(strcmp(one[i],"black queen")==0) bq++;
        else if(strcmp(one[i],"black bishop")==0) bb++;
        else if(strcmp(one[i],"black knight")==0) bn++;
        else if(strcmp(one[i],"black rook")==0) br++;
        else if(strcmp(one[i],"black pawn")==0) bp++;
        else if(strcmp(one[i],"white king")==0) wk++;
        else if(strcmp(one[i],"white queen")==0) wq++;
        else if(strcmp(one[i],"white bishop")==0) wb++;
        else if(strcmp(one[i],"white knight")==0) wn++;
        else if(strcmp(one[i],"white rook")==0) wr++;
        else if(strcmp(one[i],"white pawn")==0) wp++;
    }
    //cout<<"next"<<endl;
    for(int i=0;i<k2;i++)
    {
        gets(two[i]);
        if(strcmp(two[i],"black king")==0) bk2++;
        else if(strcmp(two[i],"black queen")==0) bq2++;
        else if(strcmp(two[i],"black bishop")==0) bb2++;
        else if(strcmp(two[i],"black knight")==0) bn2++;
        else if(strcmp(two[i],"black rook")==0) br2++;
        else if(strcmp(two[i],"black pawn")==0) bp2++;
        else if(strcmp(two[i],"white king")==0) wk2++;
        else if(strcmp(two[i],"white queen")==0) wq2++;
        else if(strcmp(two[i],"white bishop")==0) wb2++;
        else if(strcmp(two[i],"white knight")==0) wn2++;
        else if(strcmp(two[i],"white rook")==0) wr2++;
        else if(strcmp(two[i],"white pawn")==0) wp2++;
    }
    if(k1+k2<32)
    {
        cout<<"impossible"<<endl;
        return 0;
    }
/*
    cout<<wk<<' '<<wq<<' '<<wb<<' '<<wn<<' '<<wr<<' '<<wp<<endl;
    cout<<bk<<' '<<bq<<' '<<bb<<' '<<bn<<' '<<br<<' '<<bp<<endl;
    cout<<wk2<<' '<<wq2<<' '<<wb2<<' '<<wn2<<' '<<wr2<<' '<<wp2<<endl;
    cout<<bk2<<' '<<bq2<<' '<<bb2<<' '<<bn2<<' '<<br2<<' '<<bp2<<endl;
*/
    int awk=0;int awq=0;int awb=0;int awn=0;int awr=0;int awp=0;
    int abk=0;int abq=0;int abb=0;int abn=0;int abr=0;int abp=0;
    if(wk<1&&wk+wk2>=1)
        awk=1-wk;
    if(wq<1&&wq+wq2>=1)
        awq=1-wq;
    if(wb<2&&wb+wb2>=2)
        awb=2-wb;
    if(wn<2&&wn+wn2>=2)
        awn=2-wn;
    if(wr<2&&wr+wr2>=2)
        awr=2-wr;
    if(wp<8&&wp+wp2>=8)
        awp=8-wp;
    if(bk<1&&bk+bk2>=1)
        abk=1-bk;
    if(bq<1&&bq+bq2>=1)
        abq=1-bq;
    if(bb<2&&bb+bb2>=2)
        abb=2-bb;
    if(bn<2&&bn+bn2>=2)
        abn=2-bn;
    if(br<2&&br+br2>=2)
        abr=2-br;
    if(bp<8&&bp+bp2>=8)
        abp=8-bp;
/*
    cout<<awk<<' '<<awq<<' '<<awb<<' '<<awn<<' '<<awr<<' '<<awp<<endl;
    cout<<abk<<' '<<abq<<' '<<abb<<' '<<abn<<' '<<abr<<' '<<abp<<endl;
*/
    if(wk+awk>=1&&wq+awq>=1&&wb+awb>=2&&wn+awn>=2&&wr+awr>=2&&wp+awp>=8
    &&bk+abk>=1&&bq+abq>=1&&bb+abb>=2&&bn+abn>=2&&br+abr>=2&&bp+abp>=8)
    {
        for(int i=0;i<awk;i++) cout<<"white king"<<endl;
        for(int i=0;i<awq;i++) cout<<"white queen"<<endl;
        for(int i=0;i<awb;i++) cout<<"white bishop"<<endl;
        for(int i=0;i<awn;i++) cout<<"white knight"<<endl;
        for(int i=0;i<awr;i++) cout<<"white rook"<<endl;
        for(int i=0;i<awp;i++) cout<<"white pawn"<<endl;
        for(int i=0;i<abk;i++) cout<<"black king"<<endl;
        for(int i=0;i<abq;i++) cout<<"black queen"<<endl;
        for(int i=0;i<abb;i++) cout<<"black bishop"<<endl;
        for(int i=0;i<abn;i++) cout<<"black knight"<<endl;
        for(int i=0;i<abr;i++) cout<<"black rook"<<endl;
        for(int i=0;i<abp;i++) cout<<"black pawn"<<endl;
    }
    else cout<<"impossible"<<endl;
    return 0;
}
close