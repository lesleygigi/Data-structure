#include<bits/stdc++.h>
#define N 105
using namespace std;

typedef struct{
    long int weight=0;
    long int cnt=0;
}edge;

int main(){
    long int n,m,u,v,w;
    edge d[N][N];
    long int dis[N]={0};
    long int vis[N]={0};
    long int cnt[N]={0};
    long int pre[N];
    for(long int i=0;i<N;i++)pre[i]=1,cnt[i]=1;
    pre[1]=-1;
    for(long int i=0;i<N;i++){
        for(long int j=0;j<N;j++)d[i][j].weight=LONG_MAX/2;
        d[i][i].weight=0;
    }
    cin>>n>>m;
    for(long int i=0;i<m;i++){
        cin>>u>>v>>w;
        if(d[u][v].cnt&&w<d[u][v].weight){
            d[u][v].cnt=d[v][u].cnt=1;
            d[u][v].weight=d[v][u].weight=w;
        }
        else if(!d[u][v].cnt||w==d[u][v].weight){
            d[u][v].cnt++;
            d[v][u].cnt++;
            d[u][v].weight=d[v][u].weight=w;
        }
    }
    for(long int i=1;i<=n;i++)dis[i]=d[1][i].weight,cnt[i]=d[1][i].cnt;
    vis[1]=1;
    long int flag=1;
    for(long int i=1;i<n;i++){
        long int min=LONG_MAX/2,temp;
        for(long int j=1;j<=n;j++){
            if(!vis[j]&&dis[j]<min){
                min=dis[j];
                temp=j;
            }
        }
        if(min==LONG_MAX/2){flag=0;break;}
        vis[temp]=1;
        for(long int j=1;j<=n;j++){
            if(dis[temp]+d[temp][j].weight==dis[j])cnt[j]+=cnt[temp]*d[temp][j].cnt;
            else if(dis[temp]+d[temp][j].weight<dis[j]){
                dis[j]=dis[temp]+d[temp][j].weight;
                pre[j]=temp;
                cnt[j]=cnt[temp]*d[temp][j].cnt;
            }
        }
        if(temp==n)break;
    }
    if(flag==0)cout<<"-1\n0\n-1\n";
    else{
        stack<int>path;
        path.push(n);
        long int p=n;
        while(pre[p]!=-1){
            path.push(pre[p]);
            p=pre[p];
        }
        cout<<dis[n]<<endl;
        cout<<cnt[n]<<endl;
        while(!path.empty()){
            cout<<path.top()<<' ';
            path.pop();
        }
        cout<<endl;
    }
}