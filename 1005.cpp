#include<iostream>
using namespace std;

typedef struct{
	int num[1005];
	int len;
}list;

int cmp(const list &a,const list &b){
	for(int i=0;i<a.len&&i<b.len;i++){
		if(a.num[i]>b.num[i])return 1;
		else if(b.num[i]>a.num[i])return -1;
	}
	if(a.len>b.len)return 1;
	else if(b.len>a.len)return -1;
	return 0;
}

int main(){
	int m,n;
	cin>>m>>n;
	list a,b;
	a.len=b.len=0;
	for(int i=0;i<m;i++){
		cin>>a.num[i];
		a.len++;
	}
	for(int i=0;i<n;i++){
		cin>>b.num[i];
		b.len++;
	}
	cout<<cmp(a,b)<<endl;
}