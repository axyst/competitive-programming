#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define NMAX 100000
#define mid(l,r) (((l)+(r))/2)

struct vl{
	int at,df;
};

struct node{
	int l,r;
	int val;
};

int pd,pf;
int dict[NMAX*4+100];
vl sf[NMAX+10],en[NMAX+10];
node tree[NMAX*2+10000];

bool cmp_at(const vl a,const vl b){
	return a.at>b.at;
}

bool cmp_df(const vl a,const vl b){
	return a.df>b.df;
}

void push_up(int tn){
	tree[tn].val=tree[tree[tn].l].val+tree[tree[tn].r].val;
}

int create(int l,int r){
	int tn=pf++;

	if(l==r)tree[tn].l=tree[tn].r=tree[tn].val=0;
	else{
		tree[tn].l=create(l,mid(l,r));
		tree[tn].r=create(mid(l,r)+1,r);
		push_up(tn);
	}
	return tn;
}

int find(int tn,int l,int r,int q){
	//printf("[%d,%d] q=%d\n",l,r,q);
	if(!tree[tn].val)return 0;
	if(l==r)return l;
	if(mid(l,r)>q){
		int tmp=find(tree[tn].l,l,mid(l,r),q);
		if(tmp)return tmp;
	}
	return find(tree[tn].r,mid(l,r)+1,r,q);
}

void update(int tn,int l,int r,int q,int d){
	//printf("update [%d]+=%d\n",q,d);
	if(l==r)tree[tn].val+=d;
	else{
		if(mid(l,r)>=q)update(tree[tn].l,l,mid(l,r),q,d);
		else update(tree[tn].r,mid(l,r)+1,r,q,d);
		push_up(tn);
	}
}

int main(){
	int t,n,m;
	int ybz,ans;
	int i,j;

	scanf("%d",&t);
	for(ybz=1;ybz<=t;ybz++){
		pd=0;
		pf=1;

		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++){
			scanf("%d%d",&sf[i].at,&sf[i].df);
			dict[pd++]=sf[i].at;
			dict[pd++]=sf[i].df;
		}
		for(i=0;i<m;i++){
			scanf("%d%d",&en[i].at,&en[i].df);
			dict[pd++]=en[i].at;
			dict[pd++]=en[i].df;
		}
		if(n<m)goto not_poss;
		sort(dict,dict+pd);
		for(i=0;i<n;i++){
			sf[i].at=lower_bound(dict,dict+pd,sf[i].at)-dict;
			sf[i].df=lower_bound(dict,dict+pd,sf[i].df)-dict;
		}
		for(i=0;i<m;i++){
			en[i].at=lower_bound(dict,dict+pd,en[i].at)-dict;
			en[i].df=lower_bound(dict,dict+pd,en[i].df)-dict;
		}

		sort(sf,sf+n,cmp_at);
		sort(en,en+m,cmp_df);
		for(i=0;i<m;i++)
			if(sf[i].at<en[i].df)goto not_poss;
		create(1,pd);
		j=0;
		ans=n;
		for(i=0;i<m;i++){
			for(;(j<n)&&(sf[j].at>=en[i].df);j++)
				update(1,1,pd,sf[j].df,1);
			int tmp=find(1,1,pd,en[i].at);
			if(tmp){
				update(1,1,pd,tmp,-1);
				//printf("find %d > %d\n",dict[tmp],dict[en[i].at]);
			}else{
				update(1,1,pd,find(1,1,pd,0),-1);
				ans--;
			}
		}
		goto output;
		not_poss:
		ans=-1;

		output:
		printf("Case #%d: %d\n",ybz,ans);
	}
	return 0;
}

