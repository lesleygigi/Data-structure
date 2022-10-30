#include<bits/stdc++.h>
using namespace std;
#define N 105
#define inf INT_MAX/2
int n,m;
map<string,map<string,int>>d;
string ip[N];
int dijkstra(string u,string v){
    int dis[N]={0},vis[N]={0};
    int idx1=-1,idx2=-1;
    for(int i=0;i<n;i++){
        if(ip[i]==u)idx1=i;
        if(ip[i]==v)idx2=i;
        if(idx1!=-1&&idx2!=-1)break;
    }
    for(int i=0;i<n;i++){
        dis[i]=d[u][ip[i]];
    }
    dis[idx1]=0,vis[idx1]=1;
    int ret=-1;
    for(int i=1;i<n;i++){
        int min=inf,temp;
        for(int j=0;j<n;j++){
            if(!vis[j]&&dis[j]<min){
                min=dis[j];
                temp=j;
            }
        }
        if(min==inf)break;
        vis[temp]=1;
        for(int j=0;j<n;j++){
            if(dis[temp]+d[ip[temp]][ip[j]]<dis[j]){
                dis[j]=dis[temp]+d[ip[temp]][ip[j]];
                d[u][ip[j]]=dis[j];
            }
        }
        if(temp==idx2){ret=dis[temp];break;}
    }
    if(ret!=-1){
        d[u][v]=d[v][u]=ret;
    }
    return ret;
}
int main(){
    cin>>n>>m;
    string u,v;
    int t;
    for(int i=0;i<m;i++){
        cin>>u>>v>>t;
        if(d[u][v]){
            d[u][v]=d[v][u]=t<d[u][v]?t:d[u][v];
        }
        else{
            d[u][v]=d[v][u]=t;
        }
    }
    auto it=d.begin();
    for(int i=0;i<n;i++){
        ip[i]=it->first;
        it++;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(!d[ip[i]][ip[j]])d[ip[i]][ip[j]]=d[ip[j]][ip[i]]=inf;
        }
    }
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>u>>v;
        cout<<dijkstra(u,v)<<endl;
    }
}