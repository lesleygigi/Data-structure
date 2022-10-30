#include<iostream>
using namespace std;
int main(){
	char s1[100],s2[100];
	cin>>s1>>s2;
	char *p1=s1,*p2=s2;
	char s[200];
	int idx=0;
	while(*p1&&*p2){
		s[idx++]=*p1;
		s[idx++]=*p2;
		p1++,p2++;
	}
	while(*p1){
		s[idx++]=*p1,p1++;
	}
	while(*p2){
		s[idx++]=*p2,p2++;
	}
	s[idx]='\0';
	cout<<s<<endl;
}