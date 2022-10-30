#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[1000000];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int v;
	cin>>v;
	int l=0,r=n;
	int ret=-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(v==a[mid]){
			ret=mid;break;
		}
		if(v<a[mid])r=mid-1;
		else l=mid+1;
	}
	cout<<ret;
}