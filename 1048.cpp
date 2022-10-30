#include<bits/stdc++.h>
using namespace std;
typedef struct{
	int r,c;
	int val;
}node;
int cmp(const node&a,const node&b){
	if(a.r==b.r)return a.c<b.c;
	return a.r<b.r;
}
int main(){
	int m,n,c;
	cin>>m>>n>>c;
	node *d=new node[c];
	for(int i=0;i<c;i++){
		cin>>d[i].c>>d[i].r>>d[i].val;
	}
	sort(d,d+c,cmp);
	for(int i=0;i<c;i++){
		cout<<d[i].r<<' '<<d[i].c<<' '<<d[i].val<<endl;
	}
	delete[] d;
}