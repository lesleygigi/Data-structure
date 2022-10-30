#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int y[55]={0};
	int t;
	for(int i=0;i<n;i++){
		cin>>t;
		y[t]++;
	}
	for(int i=0;i<55;i++){
		if(y[i]){
			cout<<i<<":"<<y[i]<<endl;
		}
	}
}