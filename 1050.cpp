#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int d[5005];
	for(int i=0;i<n;i++){
		cin>>d[i];
	}
	int a=0,b=0,c=0;
	int r=n;
	while(r>1){
		int t=1;
		c++;
		for(int i=0;i+1<r;i++){
			a++;
			if(d[i]>d[i+1]){
				swap(d[i],d[i+1]);
				b++;
				t=i+1;
			}
		}
		r=t;
	}
	cout<<a<<' '<<b<<' '<<c<<endl;
}