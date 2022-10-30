#include<bits/stdc++.h>
using namespace std;
#define N 1000
int main(){
	int n;
	cin>>n;
	int d[N];
	for(int i=0;i<n;i++){
		cin>>d[i];
	}
	for(int i=1;i<n;i++){
		int key=d[i];
		int j=i-1;
		while(j>=0&&d[j]>key){
			d[j+1]=d[j];
			j--;
		}
		d[j+1]=key;
		for(j=0;j<n;j++){
			cout<<d[j];
			if(j==n-1)cout<<endl;
			else cout<<' ';
		}
	}
}