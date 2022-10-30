#include<bits/stdc++.h>
#define N 50005
using namespace std;
int p[N],d[N];
int fp(int x){
    if(p[x]!=x){
        int t=fp(p[x]);
        d[x]+=d[p[x]];
        p[x]=t;
    }
    return p[x];
}
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)p[i]=i;
    int res=0;
    while(k--){
        int t,x,y;
        cin>>t>>x>>y;
        if(x>n||y>n)res++;
        else{
            int px=fp(x),py=fp(y);
            if(t==1){
                if(px==py&&(d[x]-d[y])%3!=0)res++;
                else if(px!=py){
                    p[px]=py;
                    d[px]=d[y]-d[x];
                }
            }
            else{
                if(px==py&&(d[x]-d[y]-1)%3!=0)res++;
                else if(px!=py){
                    p[px]=py;
                    d[px]=d[y]-d[x]+1;
                }
            }
        }
    }
    cout<<res<<endl;
}