#include<iostream>
#include<string>
using namespace std;
#include<stdio.h>
#include<string.h>


int main(){
	int l=-1000000000,r=1000000000;
	int mid=0;
	//cout<<mid<<endl;
	printf("%d\n",mid);
	fflush(stdout);
	//string s;
	char s[10];
	// scanf("%s",s);
	// fflush(stdin);
	//if(s=="small")l=0;
	// if(strcmp(s,"small")==0)l=0;
	// if(strcmp(s,"big")==0)r=0;
	//while(cin>>s&&s!="equal")
	while(scanf("%s",s)&&strcmp(s,"equal")!=0){
		//if(s=="small")l=mid+1;
		fflush(stdin);
		if(strcmp(s,"small")==0)l=mid+1;
		else r=mid-1;
		mid=(l+r)/2;
		//cout<<mid<<endl;
		printf("%d\n",mid);
		fflush(stdout);
	}
}