#include<bits/stdc++.h>
using namespace std;
#define N 1005
int n,m;
int p[N];
typedef struct{
    int v1,v2;
    int w;
}edge;
void init(){
    for(int i=1;i<=n;i++){
        p[i]=i;
    }
}
int find(int c){
    return c==p[c]?c:p[c]=find(p[c]);
}
struct cmp{
    bool operator()(const edge*a,const edge*b){
        return a->w>b->w;
    }
};
int main(){
    cin>>n>>m;
    init();
    priority_queue<edge*,vector<edge*>,cmp>q;
    for(int i=1;i<=m;i++){
        edge* g=new edge;
        cin>>g->v1>>g->v2>>g->w;
        q.push(g);
    }
    int cost=0;
    while(!q.empty()){
        edge* tmp=q.top();q.pop();
        int p1=find(tmp->v1),p2=find(tmp->v2);
        if(p1!=p2){
            p[p2]=p1;
            cost+=tmp->w;
        }
        delete tmp;
    }
    int flag=1;
    int p=find(1);
    for(int i=1;i<=n;i++)if(find(i)!=p){flag=0;break;}
    if(flag)cout<<cost<<endl;
    else cout<<-1<<endl;
}