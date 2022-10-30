#include<iostream>
using namespace std;
int main(){
	int k;
	cin>>k;
	while(k--){
		int n;
		cin>>n;
		char temp[100];
		int top=0;
		char pop[100];
		cin>>pop;
		for(int i=0,j=0;i<n;i++){
			temp[top++]=i+1+'0';
			while(top&&j<n&&temp[top-1]==pop[j]){
				top--;
				j++;
			}
		}
		if(top==0)cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
}