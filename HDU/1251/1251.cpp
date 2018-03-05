#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#define LL long long
using namespace std;
typedef struct trienode
{
    int num;
    trienode *next[26];
}node;
node *root;
void create(char *s)
{
    node *r=root,*t;
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        int id=s[i]-'a';
        if(r->next[id]==NULL)
        {
            t=new trienode;
            t->num=1;
            for(int j=0;j<26;j++)
                t->next[j]=NULL;
            r->next[id]=t;
            r=t;
        }
        else
        {
            r=r->next[id];
            r->num++;
        }
    }
}
int look(char *s)
{
    node *r=root;
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        int id=s[i]-'a';
        if(r->next[id]==NULL) return 0;
        else r=r->next[id];
    }
    return r->num;
}
void del(node *r)
{
    for(int i=0;i<26;i++)
        if(r->next[i]!=NULL)
            del(r->next[i]);
    free(r);
}
int main()
{
    root=new node;
    root->num=0;
    for(int i=0;i<26;i++)
        root->next[i]=NULL;
    char tem[12];
    while(gets(tem)&&tem[0]!='\0')
    {
        create(tem);
        memset(tem,0,sizeof(tem));
    }
    while(scanf("%s",tem)!=EOF)
    {
        printf("%d\n",look(tem));
        memset(tem,0,sizeof(tem));
    }
    del(root);
    return 0;
}