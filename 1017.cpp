#include<iostream>
using namespace std;
typedef struct node{
	int idx;
	int q[1000];
}node;
int main(){
	int num[101]={0};
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		num[i]*=10;
	}
	int q[10000]={0};
	int idx=1;
	int ok=1;
	int sum=0;
	for(int i=1;ok==1;i++){
		int flag=0;
		for(int j=0;j<n;j++){
			if(num[idx]>0){flag=1;break;}
			else {
				idx++;idx%=n;if(idx==0)idx=n;
			}
		}
		if(flag==0){ok=0;break;}
		sum++;
		if(i>1&&q[i-1]==idx)continue;
		else{
			q[i]=idx;
			num[idx]--;
			idx++;idx%=n;if(idx==0)idx=n;
		}
	}
	node out[101];
	for(int i=1;i<=n;i++)out[i].idx=0;
	for(int i=1;i<=sum;i++){
		if(q[i])out[q[i]].q[out[q[i]].idx++]=i;
	}
	for(int i=1;i<=n;i++){
		cout<<"#"<<i<<endl;
		int cnt=out[i].idx/10;
		for(int j=0;j<cnt;j++){
			for(int k=0;k<10;k++){
				cout<<out[i].q[10*j+k]<<' ';
			}
			cout<<endl;
		}
	}
}