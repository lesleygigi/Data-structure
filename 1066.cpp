#include<bits/stdc++.h>
#define N 55
using namespace std;
int height(char *pre,char *in,int n){
	if(n==0)return 0;
	int i;
	for(i=0;i<n;i++){
		if(in[i]==pre[0])break;
	}
	int left=height(pre+1,in,i);
	int right=height(pre+i+1,in+i+1,n-i-1);
	return max(left,right)+1;
}
int main(){
	int n;
	cin>>n;
	char pre[N];
	char in[N];
	cin>>pre>>in;
	cout<<height(pre,in,n);
}