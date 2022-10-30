#include<bits/stdc++.h>
using namespace std;
#define N 505
#define inf INT_MAX/2
int n,m,s,d;
int l[N][N];
int w[N][N];
int v[N];
int dis[N];
void init(){
    cin>>n>>m>>s>>d;
    for(int i=0;i<n;i++){
        v[i]=0;
        for(int j=0;j<n;j++){
            l[i][j]=w[i][j]=inf;
        }
    }
    int u,v,length,weight;
    for(int i=0;i<m;i++){
        cin>>u>>v>>length>>weight;
        if(length<l[u][v])l[u][v]=l[v][u]=length,w[u][v]=w[v][u]=weight;
        if(length==l[u][v]&&weight<w[u][v])w[u][v]=w[v][u]=weight;
    }
}
void dijkstra(){
    for(int i=0;i<n;i++){
        dis[i]=l[s][i];
    }
    v[s]=1;
    for(int i=1;i<n;i++){
        int min=inf,k;
        for(int j=0;j<n;j++){
            if(!v[j]&&dis[j]<min)min=dis[j],k=j;
        }
        v[k]=1;
        for(int j=0;j<n;j++){
            if(dis[k]+l[k][j]==dis[j]&&w[s][k]+w[k][j]<w[s][j])w[s][j]=w[s][k]+w[k][j];
            if(dis[k]+l[k][j]<dis[j]){
                dis[j]=dis[k]+l[k][j];
                w[s][j]=w[s][k]+w[k][j];
            }
        }
    }
}
int main(){
    init();
    dijkstra();
    cout<<dis[d]<<' '<<w[s][d]<<endl;
}