#include<bits/stdc++.h>
using namespace std;
#define N 1005
int n,m;
int p[N];
long long int x[N],y[N];
typedef struct{
    int v1,v2;
    double w;
}edge;
struct cmp{
    bool operator()(const edge*a,const edge*b){
        return a->w>b->w;
    }
};
priority_queue<edge*,vector<edge*>,cmp>q;
int find(int c){
    if(c==p[c])return c;
    return p[c]=find(p[c]);
}
void init(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        p[i]=i;
    }
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    int u,v;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        int p1=find(u),p2=find(v);
        p[p2]=p1;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int p1=find(i),p2=find(j);
            if(p1!=p2){
                edge *tmp=new edge;
                tmp->v1=i,tmp->v2=j;
                tmp->w=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
                q.push(tmp);
            }
        }
    }
}
double kruskal(){
    double cost=0;
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
    double cost=kruskal();
    printf("%.2lf",cost);
}