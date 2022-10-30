#include<bits/stdc++.h>
using namespace std;
#define N 1005
#define inf 9999

double p[N];
double q[N];
int root[N][N];
double w[N][N];
double e[N][N];

//动态规划
void optimalBST(int n){
    //初始化只包含虚拟键的子树
    for(int i=1;i<=n+1;i++){
        w[i][i-1]=q[i-1];
        e[i][i-1]=q[i-1];
    }
    //从下往上，从左往右逐步计算
    for(int len=1;len<=n;len++){
        for(int i=1;i<=n-len+1;i++){
            int j=i+len-1;
            e[i][j]=inf;
            w[i][j]=w[i][j-1]+p[j]+q[j];
            //遍历每个结点作为根节点得情况，找到总代价最小的那个
            for(int k=i;k<=j;k++){
                double temp=e[i][k-1]+e[k+1][j]+w[i][j];
                if(temp<e[i][j]){
                    e[i][j]=temp;
                    root[i][j]=k;
                }
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    for(int i=0;i<=n;i++){
        cin>>q[i];
    }
    optimalBST(n);
    cout<<e[1][n]<<endl;
}


