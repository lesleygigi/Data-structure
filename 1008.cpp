#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[10000];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int v;
	cin>>v;
	int ret=-1;
	for(int i=0;i<n;i++){
		if(a[i]==v){
			ret=i;break;
		}
	}
	cout<<ret;
}