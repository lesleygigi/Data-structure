#include<bits/stdc++.h>
#define N 10000
using namespace std;
typedef struct{
	string no;
	int c;
	int r1,r2;
	int score;
}node;
int cmp(const node&a,const node&b){
	if(a.score==b.score)return a.no<b.no;
	return a.score>b.score;
}
int main(){
	int n,k,r;
	cin>>n;
	node d[N];
	int idx=0;
	for(int i=0;i<n;i++){
		cin>>k;
		int a=idx;
		for(int j=0;j<k;j++){
			d[idx].c=i+1;
			cin>>d[idx].no>>d[idx].score;
			idx++;
		}
		int b=idx;
		sort(d+a,d+b,cmp);
		r=1;
		for(int j=0;j<k;j++){
			if(j>0&&d[a+j].score==d[a+j-1].score)d[a+j].r1=d[a+j-1].r1;
			else d[a+j].r1=r;
			r++;
		}
	}
	sort(d,d+idx,cmp);
	cout<<idx<<endl;
	r=1;
	for(int j=0;j<idx;j++){
		if(j>0&&d[j].score==d[j-1].score)d[j].r2=d[j-1].r2;
		else d[j].r2=r;
		r++;
	}
	for(int i=0;i<idx;i++){
		cout<<d[i].no<<' '<<d[i].r2<<' '<<d[i].c<<' '<<d[i].r1<<endl;
	}
}