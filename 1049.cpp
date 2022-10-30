#include<bits/stdc++.h>
using namespace std;
#define N 1000
typedef struct{
	int r,c,v;
}tri;
typedef struct{
	int n,m,c;
	tri node[N];
}mat;
int main(){
	mat a,b;
	scanf("%d%d%d",&a.n,&a.m,&a.c);
	for(int i=0;i<a.c;i++){
		scanf("%d%d%d",&a.node[i].r,&a.node[i].c,&a.node[i].v);
	}
	scanf("%d%d%d",&b.n,&b.m,&b.c);
	for(int i=0;i<b.c;i++){
		scanf("%d%d%d",&b.node[i].r,&b.node[i].c,&b.node[i].v);
	}
	tri ret[2*N];
	int idx=0,i,j;
	for(i=0,j=0;i<a.c&&j<b.c;){
		if(a.node[i].r==b.node[j].r&&a.node[i].c==b.node[j].c){
			ret[idx].r=a.node[i].r;ret[idx].c=a.node[i].c;
			ret[idx].v=a.node[i].v+b.node[j].v;
			idx++,i++,j++;
		}
		else if(a.node[i].r<b.node[j].r||(a.node[i].r==b.node[j].r&&a.node[i].c<b.node[j].c)){
			ret[idx].r=a.node[i].r,ret[idx].c=a.node[i].c;
			ret[idx].v=a.node[i].v;
			idx++;i++;
		}
		else if(b.node[j].r<a.node[i].r||(a.node[i].r==b.node[j].r&&b.node[j].c<a.node[i].c)){
			ret[idx].r=b.node[j].r,ret[idx].c=b.node[j].c;
			ret[idx].v=b.node[j].v;
			idx++;j++;
		}
	}
	while(i<a.c){
		ret[idx].r=a.node[i].r,ret[idx].c=a.node[i].c;
		ret[idx].v=a.node[i].v;
		idx++;i++;
	}
	while(j<b.c){
		ret[idx].r=b.node[j].r,ret[idx].c=b.node[j].c;
		ret[idx].v=b.node[j].v;
		idx++;j++;
	}
	for(int k=0;k<idx;k++){
		printf("%d %d %d\n",ret[k].r,ret[k].c,ret[k].v);
	}
}