#include<bits/stdc++.h>
using namespace std;
#define N 105
#define inf INT_MAX
int edge[N][N];
int n;
int a[N],b[N];
void init(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)edge[i][j]=inf;
    }
}
int prim(bool flag){
    int cost[N],vis[N];
    int sum=0;
    for(int i=1;i<=n;i++){
        cost[i]=edge[1][i];
        vis[i]=0;
    }
    vis[1]=1;
    for(int i=2;i<=n;i++){
        int min=inf,k;
        if(flag){
            for(int j=1;j<=n;j++){
                if(!vis[j]&&cost[j]<=min){
                    min=cost[j];
                    k=j,a[i]=k;
                }
            }
        }
        else{
            for(int j=n;j>=1;j--){
                if(!vis[j]&&cost[j]<=min){
                    min=cost[j];
                    k=j,b[i]=k;
                }
            }
        }
        sum+=min;
        vis[k]=1;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&edge[k][j]<cost[j]){
                cost[j]=edge[k][j];
            }
        }
    }
    return sum;
}
int main(){
    while(cin>>n){
        init();
        int x[N],y[N];
        for(int i=1;i<=n;i++){
            cin>>x[i]>>y[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                edge[i][j]=edge[j][i]=abs(x[i]-x[j])+abs(y[i]-y[j]);
            }
        }
        int res1=prim(1),res2=prim(0);
        cout<<res1<<endl;
        int flag=0;
        for(int i=2;i<=n;i++){
            if(a[i]!=b[i]){
                flag=1;break;
            }
        }
        if(n==3&&edge[1][2]==edge[1][3])flag=0;
        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}