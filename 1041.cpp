#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char s[10001],t[10001];
	cin>>s>>t;
	int flag;
	int pos=-1;
	for(int i=0;i<strlen(s);i++){
		flag=1;
		if(s[i]==t[0]){
			for(int j=0;j<strlen(t);j++){
				if(s[i+j]!=t[j]){flag=0;break;}
			}
			if(flag){
				pos=i;break;
			}
		}
	}
	cout<<pos<<endl;
}