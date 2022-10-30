#include<bits/stdc++.h>
#define N 1000
using namespace std;
int n;
int d[N];
void Qsort(int begin,int end){
	int k=d[begin];
	int i=begin,j=end;
	if(i>=j)return;
	while(i!=j){
		while(i<j&&d[j]>=k)j--;
		if(i<j)d[i]=d[j];
		while(i<j&&d[i]<=k)i++;
		if(i<j)d[j]=d[i];
	}
	d[i]=k;
	for(int q=0;q<n;q++){
		cout<<d[q];
		if(q==n-1)cout<<endl;
		else cout<<' ';
	}
	Qsort(begin,i-1);
	Qsort(i+1,end);
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>d[i];
	Qsort(0,n-1);
}