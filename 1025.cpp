#include<iostream>
using namespace std;
int n;
int x,y,x2,y2;
int visit[101][101]={0};
bool flag=false;
void dfs(int mat[][101],int i,int j){
	if(!(i>=0&&i<n)||!(j>=0&&j<n))return;
	if(i==x2&&j==y2){
		flag=true;return;
	}
	if(flag)return;
	if(i-1>=0&&mat[i-1][j]==0){
		if(visit[i-1][j]==0){
			visit[i-1][j]=1;
			i=i-1;
			dfs(mat,i,j);
			i=i+1;
			visit[i-1][j]=0;
		}
		if(flag)return;
	}
	if((i-1>=0&&j+1<n)&&mat[i-1][j+1]==0){
		if(visit[i-1][j+1]==0){
			visit[i-1][j+1]=1;
			i=i-1;j=j+1;
			dfs(mat,i,j);
			i=i+1;j=j-1;
			visit[i-1][j+1]=0;
		}
		if(flag)return;
	}
	if(j+1<n&&mat[i][j+1]==0){
		if(visit[i][j+1]==0){
			visit[i][j+1]=1;
			j=j+1;
			dfs(mat,i,j);
			j=j-1;
			visit[i][j+1]=0;
		}
		if(flag)return ;
	}
	if((i+1<n&&j+1<n)&&mat[i+1][j+1]==0){
		if(visit[i+1][j+1]==0){
			visit[i+1][j+1]=1;
			i=i+1;j=j+1;
			dfs(mat,i,j);
			i=i-1;j=j-1;
			visit[i+1][j+1]=0;
		}
		if(flag)return;
	}
	if(i+1<n&&mat[i+1][j]==0){
		if(visit[i+1][j]==0){
			visit[i+1][j]=1;
			i=i+1;
			dfs(mat,i,j);
			i=i-1;
			visit[i+1][j]=0;
		}
		if(flag)return;
	}
	if((i+1<n&&j-1>=0)&&mat[i+1][j-1]==0){
		if(visit[i+1][j-1]==0){
			visit[i+1][j-1]=1;
			i=i+1;j=j-1;
			dfs(mat,i,j);
			i=i-1;j=j+1;
			visit[i+1][j-1]=0;
		}
		if(flag)return;
	}
	if(j-1>=0&&mat[i][j-1]==0){
		if(visit[i][j-1]==0){
			visit[i][j-1]=1;
			j=j-1;
			dfs(mat,i,j);
			j=j-1;
			visit[i][j-1]=0;
		}
		if(flag)return;
	}
	if((i-1>=0&&j-1>=0)&&mat[i-1][j-1]==0){
		if(visit[i-1][j-1]==0){
			visit[i-1][j-1]=1;
			i=i-1;j=j-1;
			dfs(mat,i,j);
			i=i+1;j=j+1;
			visit[i-1][j-1]=0;
		}
		if(flag)return;
	}
}
int main(){
	cin>>n;
	cin>>x>>y>>x2>>y2;
	int mat[101][101];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			mat[i][j]=getchar()-'0';
		}
		getchar();
	}
	dfs(mat,x,y);
}