#include<bits/stdc++.h>
#define N 105
using namespace std;
//同一祖宗，同一阵营
int findf(int a[],int x){
	int k=x;
	while(a[k]!=k){
		k=a[k];
	}
	while(x!=k){
		int j=a[x];
		a[j]=k;
		x=j;
	}
	return k;
}
void newf(int a[],int x,int y){
	int fx=findf(a,x);
	int fy=findf(a,y);
	a[fx]=fy;
}
int main(){
	int a[N],b[N];
	int t;
	cin>>t;
	int cas=0;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)a[i]=i,b[i]=-1;
		char cmd;
		int x,y;
		for(int i=0;i<m;i++){
			cin>>cmd>>x>>y;
			if(cmd=='A'){
				if(b[x]==-1){
					b[x]=y;
				}
				else{
					newf(a,b[x],y);//将x的敌人结合为朋友
				}
				if(b[y]==-1){
					b[y]=x;
				}
				else{
					newf(a,x,b[y]);//将y的敌人结合为朋友
				}
			}
			else{
				int fx=findf(a,x);
				int fy=findf(a,y);
				if(fx==fy){
					cout<<"In the same gang."<<endl;
				}
				else{
					if(b[fx]==fy||b[fy]==fx)
						cout<<"In different gangs."<<endl;
					else 
						cout<<"Not sure yet."<<endl;
				}
			}
		}
	}
}