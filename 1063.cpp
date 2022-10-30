#include<bits/stdc++.h>
#include<vector>
#define N 100000
using namespace std;
vector<int>p[N];
void dfs(int pa){
	for(int i=0;i<p[pa].size();i++){
		dfs(p[pa][i]);
	}
	cout<<pa<<' ';
}
int main(){
	int n;
	cin>>n;
	int t;
	for(int i=0;i<n;i++){
		cin>>t;
		if(t!=-1)p[t].push_back(i);
	}
	dfs(0);
}