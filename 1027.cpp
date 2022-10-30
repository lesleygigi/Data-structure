#include<bits/stdc++.h>
using namespace std;
#define N 300000
int ret=0;
int n;
int out[N];
int retout[N];
int row[N]={0},col[N]={0},diag1[2*N]={0},diag2[2*N]={0};
void dfs(int idx,int x){
	if(idx==n){
		if(ret==0){
			for(int i=0;i<n;i++)retout[i]=out[i];
		}
		ret++;
		return;
	}
	for(int i=0;i<n;i++){
		if(row[x]==0&&col[i]==0&&diag1[i+x]==0&&diag2[i-x+N]==0){
			row[x]++,col[i]++,diag1[i+x]++,diag2[i-x+N]++;
			out[idx]=i;
			dfs(idx+1,x+1);
			row[x]--,col[i]--,diag1[i+x]--,diag2[i-x+N]--;
		}
	}
}
int main(){
	cin>>n;
	dfs(0,0);
	cout<<ret<<endl;
	if(ret){
		for(int i=0;i<n;i++){
			cout<<retout[i]<<' ';
		}
		cout<<endl;
	}
}