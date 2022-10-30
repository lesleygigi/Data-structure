#include<bits/stdc++.h>
using namespace std;
int get(queue<char>&num){
	int sign=1;
	int ret=0;
	if(num.front()=='-'){
		sign=-1;num.pop();
	}
	while(!num.empty()){
		ret=ret*10+num.front()-'0';
		num.pop();
	}
	return ret*sign;
}
int main(){
	int op[128];
	op['(']=op[')']=0;
	op['-']=op['+']=1;
	op['*']=op['/']=2;
	stack<int>s1;//操作数栈
	stack<char>s2;//操作符栈
	char s[100];
	cin>>s;
	bool negtive=false;
	queue<char>num;
	char c;
	for(int i=0;i<strlen(s);i++){
		c=s[i];
		negtive=false;
		if(c=='-'){
			if(i==0)negtive=true;
			else if(!isdigit(s[i-1]))negtive=true;
		}
		if(negtive){
			while(!num.empty())num.pop();
			num.push(c);
			continue;
		}
		if(isdigit(c))num.push(c);
		else{
			if(!num.empty()){
				s1.push(get(num));
			}
			if(s2.empty()||c=='(')s2.push(c);
			else{
				while(!s2.empty()&&op[c]<=op[s2.top()]){
					char o=s2.top();s2.pop();
					if(o=='(')break;
					int n2=s1.top();s1.pop();
					int n1=s1.top();s1.pop();
					switch(o){
						case '-':
						s1.push(n1-n2);
						break;
						case '+':
						s1.push(n1+n2);
						break;
						case '*':
						s1.push(n1*n2);
						break;
						case '/':
						s1.push(n1/n2);
						break;
					}
				}
				if(c!=')')s2.push(c);
			}
		}
	}
	if(!num.empty()){
		s1.push(get(num));
	}
	while(!s2.empty()){
		char o=s2.top();s2.pop();
		if(o=='(')break;
		int n2=s1.top();s1.pop();
		int n1=s1.top();s1.pop();
		switch(o){
			case '-':
			s1.push(n1-n2);
			break;
			case '+':
			s1.push(n1+n2);
			break;
			case '*':
			s1.push(n1*n2);
			break;
			case '/':
			s1.push(n1/n2);
			break;
		}
	}
	cout<<s1.top()<<endl;
}