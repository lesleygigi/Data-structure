#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	map<string,double>data;
	string s;
	while(getline(cin,s)){
		data[s]++;
	}
	for(int i=0;i<data.size();i++){
		printf("%.4f",data[i]/n);
	}
}