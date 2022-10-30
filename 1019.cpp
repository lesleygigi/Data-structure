#include<iostream>
using namespace std;
#define MAXSIZE 100000
int main(){//维护两个栈，一个原始栈，一个max栈
	int stack[MAXSIZE]={0};
	int smax[MAXSIZE]={0};
	int top=0;
	int n,cmd,x;
	cin>>n;
	while(n--){
		cin>>cmd;
		if(cmd==0){
			cin>>x;
			stack[top]=x;
			if(top==0||(top>0&&x>smax[top-1]))smax[top]=x;
			else smax[top]=smax[top-1];
			top++;
		}
		else if(cmd==1){
			if(top==0)continue;
			else top--;
		}
		else if(cmd==2){
			if(top==0)cout<<0<<endl;
			else cout<<smax[top-1]<<endl;
		}
	}
}