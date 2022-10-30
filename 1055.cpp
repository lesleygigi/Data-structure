#include<bits/stdc++.h>
#define N 1000
using namespace std;
int n;
int d[N];
void select(int begin,int end){
	int i,j;
	for(i=begin;i<end;i++){
		int min=i;
		for(j=i+1;j<=end;j++){
			if(d[j]<d[min])min=j;
		}
		swap(d[i],d[min]);
	}
}
void Qsort(int begin,int end){
	if(end-begin<2000){
		select(begin,end);
		return;
	}
	if(begin>=end)return;
	int a=begin,b=(begin+end+1)/2,c=end;
	if(d[a]>d[b])swap(a,b);
	if(d[a]>d[c])swap(a,c);
	if(d[b]>d[c])swap(b,c);
	swap(d[begin],d[a]);
	swap(d[(begin+end+1)/2],d[b]);
	swap(d[end],d[c]);
	swap(d[begin],d[(begin+end+1)/2]);
	int k=d[begin];
	int i=begin,j=end;
	while(i!=j){
		while(i<j&&d[j]>=k)j--;
		if(i<j)d[i]=d[j];
		while(i<j&&d[i]<=k)i++;
		if(i<j)d[j]=d[i];
	}
	d[i]=k;
	Qsort(begin,i-1);
	Qsort(i+1,end);
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>d[i];
	Qsort(0,n-1);
	for(int i=0;i<n;i++){
		cout<<d[i]<<' ';
	}
}