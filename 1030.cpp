#include<bits/stdc++.h>
using namespace std;
#define N 505
typedef struct{
	string key="";
	string val="";
}HASH;
int main(){
	string s,s1,s2;
	HASH data[N];
	while(getline(cin,s)&&s.length()!=0){
		stringstream ss(s);
		ss>>s1>>s2;
		long long int h=0;
		int len=s2.length();
		for(int i=0;i<len;i++){
			h=h*31+s2[i];
		}
		h=h%N;
		while(data[h].key!=""&&h<N){
			h=(h+1)%N;
		}
		data[h].key=s2;
		data[h].val=s1;
	}
	while(cin>>s){
		long long int h=0;
		int len=s.length();
		for(int i=0;i<len;i++){
			h=h*31+s[i];
		}
		h=h%N;
		int flag=0;
		while(data[h].key!=""&&h<N){
			if(data[h].key==s){
				cout<<data[h].val<<endl;
				flag=1;break;
			}
			else h=(h+1)%N;
		}
		if(flag==0)cout<<"eh"<<endl;
	}
}