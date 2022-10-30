#include<bits/stdc++.h>
#define N 100005
using namespace std;
void getnext(string t,int next[]){
	int tlen=t.length();
	next[0]=-1;
	int k=-1;
	int j=0;
	while(j<tlen-1){
		if(k==-1||t[j]==t[k]){
			k++,j++;
			next[j]=k;
		}
		else{
			k=next[k];
		}
	}
}
int kmp(string s,string t,int next[]){
	int i=0,j=0;
	int slen=s.length(),tlen=t.length();
	while(i<slen&&j<tlen){
		if(j==-1||s[i]==t[j]){
			i++,j++;
		}
		else{
			j=next[j];
		}
	}
	if(j==tlen){
		return i-j;
	}
	else return -1;
}
int main(){
	string s,t;
	cin>>s>>t;
	int next[N];
	getnext(t,next);
	int idx=kmp(s,t,next);
	cout<<idx<<endl;
	for(int i=0;i<t.length();i++){
		cout<<next[i];
		if(i!=t.length()-1)cout<<' ';
	}
}