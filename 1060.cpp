#include<bits/stdc++.h>
using namespace std;
#define N 2000
typedef struct{
	int cnt=0;
	int val;
}node;
int cmp(const node&a,const node&b){
	if(a.cnt==b.cnt)return a.val<b.val;
	return a.cnt>b.cnt;
}
int main(){
	int t;
	cin>>t;
	int cas=0;
	while(t--){
		int a[501]={0};
		int n;
		cin>>n;
		int v;
		for(int i=0;i<n;i++){
			cin>>v;a[v]++;
		}
		node d[N];
		int idx=0;
		for(int i=0;i<501;i++){
			if(a[i]){
				d[idx].val=i;
				d[idx].cnt=a[i];
				idx++;
			}
		}
		sort(d,d+idx,cmp);
		cout<<"case #"<<cas++<<':'<<endl;
		for(int i=0;i<idx;i++){
			while(d[i].cnt--)cout<<d[i].val<<' ';
		}
		cout<<endl;
	}
}