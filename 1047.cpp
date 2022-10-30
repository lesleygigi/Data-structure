#include<bits/stdc++.h>
#include<iostream>
#include<map>
#include<set>
#define N 30000
using namespace std;
int gethash(string s){
	int h=0;
	for(int i=0;i<s.size();i++){
		h=h*26+s[i];
		h%=N;
	}
	return h;
}
int main(){
	int n;
	cin>>n;
	string password[N];
	for(int i=0;i<n;i++){
		cin>>password[i];
	}
	map<string,int>match[N];
	for(int i=0;i<n;i++){
		set<string>substrset;
		for(int j=0;j<password[i].size();j++){
			for(int k=1;j+k<=password[i].size();k++){
				substrset.insert(password[i].substr(j,k));
			}
		}
		auto it=substrset.begin();
		while(it!=substrset.end()){
			int h=gethash(*it);
			match[h][*it]++;
			it++;
		}
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		int h=gethash(password[i]);
		cnt=cnt+match[h][password[i]]-1;
	}
	cout<<cnt<<endl;
}