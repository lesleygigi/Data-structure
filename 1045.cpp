#include<bits/stdc++.h>
using namespace std;
int main(){
	int alp[128]={0};
	string s,t;
	cin>>s>>t;
	int a1=0,a2=0;
	for(int i=0;i<s.length();i++){
		alp[s[i]]++;
	}
	for(int i=0;i<s.length();i++){
		if(alp[t[i]]){
			a2++;
			alp[t[i]]--;
		}
		if(s[i]==t[i])a1++;
	}
	a2-=a1;
	cout<<a1<<' '<<a2<<endl;
}