#include<bits/stdc++.h>
#define N 1000
using namespace std;
int main(){
	int n;
	cin>>n;
	int d[N];
	for(int i=0;i<n;i++){
		cin>>d[i];
	}
	int i,j;
	for(i=0;i<n-1;i++){
		int min=i;
		for(j=i+1;j<n;j++){
			if(d[j]<d[min])min=j;
		}
		swap(d[i],d[min]);
		for(j=0;j<n;j++){
			cout<<d[j];
			if(j==n-1&&i!=n-1)cout<<endl;
			else cout<<' ';
		}
	}
}