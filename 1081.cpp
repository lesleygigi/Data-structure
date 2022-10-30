#include<bits/stdc++.h>
#define N 10000
using namespace std;

int f(int parent[],int idx){
	if(idx==parent[idx])return idx;
	return parent[idx]=f(parent,parent[idx]);
}
int main(){
	int student,club,number,parent[N]={0},temp[N]={0},cnt[N]={0};
	cin>>student>>club;
	for(int i=1;i<=student;i++)parent[i]=i;
	while(club--){
		cin>>number;
		for(int i=0;i<number;i++){
			cin>>temp[i];
		}
		int fa,fb;
		for(int i=1;i<number;i++){
			fa=f(parent,temp[i-1]);
			fb=f(parent,temp[i]);
			if(fa!=fb)parent[fb]=fa;
		}
	}
	for(int i=1;i<=student;i++)cnt[f(parent,parent[i])]++;
	int ret=0;
	for(int i=1;i<student;i++){
		ret=cnt[i]>ret?cnt[i]:ret;
	}
	cout<<ret<<endl;
}