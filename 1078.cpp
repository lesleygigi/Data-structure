#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	priority_queue<int,vector<int>,greater<int>>d;
	int t;
	for(int i=0;i<n;i++){
		cin>>t;
		d.push(t);
	}
	int ret=0;
	while(d.size()>=2){
		int a=d.top();d.pop();
		int b=d.top();d.pop();
		ret+=a+b;
		d.push(a+b);
	}
	cout<<ret<<endl;
}