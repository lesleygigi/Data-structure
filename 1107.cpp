#include<iostream>
using namespace std;
int main(){
	string s;
	cin>>s;
	int flag=1;
	if(s[0]>='A'&&s[0]<='Z'){
		int c1=0,c2=0;
		for(int i=1;i<s.length();i++){
			if(s[i]>='a'&&s[i]<'z'){
				c1=1;
			}
			if(s[i]>='A'&&s[i]<'Z'){
				c2=1;
			}
			if(c1&&c2){
				flag=0;break;
			}
		}
	}
	else{
		for(int i=1;i<s.length();i++){
			if(s[i]>='A'&&s[i]<'Z'){
				flag=0;break;
			}
		}
	}
	if(flag)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}