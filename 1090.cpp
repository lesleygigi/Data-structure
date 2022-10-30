#include<bits/stdc++.h>
#define N 35
using namespace std;
int n,m;
map<string,int>c;
double d[N][N];
void reset(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)d[i][j]=1;
            else d[i][j]=0;
        }
    }
}
void floyd(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(d[i][j]<d[i][k]*d[k][j])
                    d[i][j]=d[i][k]*d[k][j];
            }
        }
    }
}
int main(){
    int cas=0;
    while(cin>>n&&n!=0){
        reset();
        c.clear();
        string money;
        for(int i=0;i<n;i++){
            cin>>money;
            c[money]=i;
        }
        cin>>m;
        string ci,cj;
        double r;
        for(int i=0;i<m;i++){
            cin>>ci>>r>>cj;
            d[c[ci]][c[cj]]=r;
        }
        floyd();
        int flag=0;
        for(int i=0;i<n;i++){
            if(d[i][i]>1){flag=1;break;}
        }
        cout<<"Case "<<++cas<<": ";
        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}