#include<bits/stdc++.h>
#define N 10000
using namespace std;
typedef struct{
	int r1,r2;
	string name;
}node;
int cmp(const node&a,const node&b){
	if(a.r2==b.r2)return a.r1<b.r1;
	return a.r2>b.r2;
}
int main(){
	int n;
	cin>>n;
	int idx=0;
	node d[N];
	for(int i=0;i<n;i++){
		cin>>d[i].name>>d[i].r2;
		d[i].r1=idx++;
	}
	sort(d,d+n,cmp);
	for(int i=0;i<n;i++){
		cout<<d[i].name<<' '<<d[i].r2<<endl;
	}
}