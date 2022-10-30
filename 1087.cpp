#include<bits/stdc++.h>
using namespace std;
#define N 1005
int v[N]={0};
int n,m,s,flag=0;
set<int>d[N];
vector<int>res;
int dfs(int idx){
    if(v[idx])return 0;
    v[idx]=1;
    res.push_back(idx);
    for(auto i:d[idx]){
        if(dfs(i)){
            res.push_back(idx);
        }
    }
    return 1;
}
int main(){
    cin>>n>>m>>s;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        d[a].insert(b);
        d[b].insert(a);
    }
    dfs(s);
    int flag=0;
    for(int i=1;i<=n;i++)if(!v[i]){flag=1;break;}
    for(int i=0;i<res.size();i++)cout<<res[i]<<' ';
    if(flag)cout<<0<<endl;
}