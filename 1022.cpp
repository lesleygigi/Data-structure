#include<bits/stdc++.h>
using namespace std;
double exp(){
	char s[10];
	cin>>s;
	switch(s[0]){
		case '+':return exp()+exp();
		case '-':return exp()-exp();
		case '*':return exp()*exp();
		case '/':return exp()/exp();
		default: return atof(s);
	}
}
int main(){
	cout<<exp()<<endl;
}