#include<bits/stdc++.h>
using namespace std;
#define N 10005

typedef struct node
{
    int idx;//当前下标
    node* next;//下一个邻点
}node;

node* G[N];
int vis[N];//是否访问了该点
int n,m;

void InitVisit(){
    for(int i=1;i<=n;i++)vis[i]=0;
}

void Init(){
    int v1,v2;
    node* newnode;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        G[i]=new node;
        G[i]->idx=i;
        G[i]->next=NULL;
    }
    for(int i=0;i<m;i++){
        cin>>v1>>v2;
        newnode=new node;
        newnode->idx=v2;
        newnode->next=G[v1]->next;
        G[v1]->next=newnode;

        newnode=new node;
        newnode->idx=v1;
        newnode->next=G[v2]->next;
        G[v2]->next=newnode;
    }
}
int BFS(int v){
    queue<int>q;
    int tmp;
    int level=0;
    int last=v;//该层最后一个访问的结点
    int tail=v;//每次访问的结点
    node* p;
    vis[v]=1;
    int cnt=1;
    q.push(v);
    while(!q.empty()){
        tmp=q.front();
        q.pop();
        p=G[tmp]->next;
        while(p){
            if(!vis[p->idx]){
                vis[p->idx]=1;
                q.push(p->idx);
                cnt++;
                tail=p->idx;
            }
            p=p->next;
        }
        if(tmp==last){
            level++;
            last=tail;
        }
        if(level==6)break;
    }
    return cnt;
}
int main(){
    Init();
    for(int i=1;i<=n;i++){
        InitVisit();
        double ret=((BFS(i)*1.0)/n)*100;
        printf("%d: %.2lf%%\n",i,ret);
    }
}