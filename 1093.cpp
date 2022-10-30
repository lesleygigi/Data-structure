#include<bits/stdc++.h>
using namespace std;
#define N 105
#define inf INT_MAX/2
int n,m;
int d[N][N];
int dis[N];

void init(){
    for(int i=1;i<=n;i++){
        dis[i]=0;
        for(int j=1;j<=n;j++){
            if(i!=j)d[i][j]=inf;
            else d[i][j]=0;
        }
    }
}

void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(d[i][j]>d[i][k]+d[k][j])
                    d[i][j]=d[i][k]+d[k][j];
            }
        }
    }
}

int main(){
    cin>>n>>m;
    init();
    int u,v,t;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>t;
        if(t<d[u][v])d[u][v]=d[v][u]=t;
    }
    floyd();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dis[i]<d[i][j])dis[i]=d[i][j];
        }
    }
    int min=inf;
    int k;
    for(int i=1;i<=n;i++){
        if(dis[i]<min)min=dis[i],k=i;
    }
    if(min==inf)cout<<'0'<<endl;
    else cout<<k<<' '<<min<<endl;
}