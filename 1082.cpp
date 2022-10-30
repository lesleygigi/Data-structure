#include<bits/stdc++.h>
#define N 10000
using namespace std;
string f(map<string,string>&parent,string s){
	if(parent[s]==s)return s;
	return parent[s]=f(parent,parent[s]);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		map<string,string>parent;
		map<string,int>son;
		int n;
		cin>>n;
		string s1,s2;
		for(int i=0;i<n;i++){
			cin>>s1>>s2;
			if(parent[s1]==""){
				parent[s1]=s1;
				son[s1]=1;
			}
			if(parent[s2]==""){
				parent[s2]=s2;
				son[s2]=1;
			}
			string fa,fb;
			fa=f(parent,s1);
			fb=f(parent,s2);
			if(fb!=fa){	
				parent[fb]=fa;
				son[fa]+=son[fb];
			}
			cout<<son[fa]<<endl;
		}
	}
}