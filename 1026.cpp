#include<iostream>
using namespace std;
#define N 101
typedef long long int ll;
int main(){
    int n;
    scanf("%d",&n);
    ll row[N]={0},col[N]={0},diag1[2*N]={0},diag2[2*N]={0};
    int x,y;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        row[x]++;
        col[y]++;
        diag1[y+x]++;
        diag2[y-x+N]++;
    }
    ll ans=0;
    for(int i=0;i<N;i++){
        if(row[i]>=2)ans+=row[i]*(row[i]-1)/2;
        if(col[i]>=2)ans+=col[i]*(col[i]-1)/2;
    }
    for(int i=0;i<2*N;i++){
        if(diag1[i]>=2)ans+=diag1[i]*(diag1[i]-1)/2;
        if(diag2[i]>=2)ans+=diag2[i]*(diag2[i]-1)/2;
    }
    cout<<ans<<endl;
}