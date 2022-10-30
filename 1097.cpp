#include<bits/stdc++.h>
using namespace std;
#define N 1005
int n,m;
int p[N];
typedef struct{
    int v1,v2;
    int w;
}edge;
struct cmp{
    bool operator()(const edge*a,const edge*b){
        return a->w>b->w;
    }
};
priority_queue<edge*,vector<edge*>,cmp>q;
int find(int c){
    return c==p[c]?c:p[c]=find(p[c]);
}
void init(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        p[i]=i;
    }
    for(int i=1;i<=m;i++){
        edge* tmp=new edge;
        cin>>tmp->v1>>tmp->v2>>tmp->w;
        q.push(tmp);
    }
}
int kruskal(){
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
    return cost;
}
int main(){
    init();
    int cost=kruskal();
    printf("%d",cost);
}