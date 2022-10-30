#include<iostream>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[10001];
	for(int i=0;i<n;i++)cin>>a[i];
	int b[5001]={0};
	int cnt=0;
	int l=0,r=n-1;
	for(int i=0;i<n;i++){
		if(b[a[i]]==0){
			cnt++;
		}
		b[a[i]]++;
		if(cnt==m){r=i;break;}
	}
	while(b[a[l]]-1){
		b[a[l]]--;l++;
	}
	int retl=l,retr=r;
	int ret=r-l;
	for(int i=r;i<n;i++){
		b[a[i]]++;
		r=r+1;
		while(b[a[l]]-1){b[a[l]]--;l++;}
		if(r-l<ret){ret=r-l;retl=l;retr=r;}
	}
	cout<<retl+1<<' '<<retr+1<<endl;
}