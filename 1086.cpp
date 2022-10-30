// 判断欧拉回路是否存在的方法

// 有向图：图连通，所有的顶点出度=入度。

// 无向图：图连通，所有顶点都是偶数度。 


//此题是无向图
//判断连通，用并查集
#include<bits/stdc++.h>
using namespace std;
#define N 1001
int ancestors[N];
int find(int a){//找祖宗
    return a==ancestors[a]?a:find(ancestors[a]);
}
int main(){
    for(int i=0;i<N;i++)ancestors[i]=i;
    int data[N]={0};
    int n,m;
    cin>>n>>m;
    int a,b;
    int p;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        data[a]++;data[b]++;
        int pa=find(a);
        int pb=find(b);
        if(pa!=pb)ancestors[pb]=pa;
    }
    p=find(a);
    int flag=1;
    for(int i=1;i<=n;i++){
        if(data[i]%2||find(data[i])!=p){
            flag=0;
            break;
        }
    }
    cout<<flag<<endl;
}