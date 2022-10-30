#include<iostream>
using namespace std;
#define N 1000
typedef unsigned long long int ull;
int main(){
	ull c[N]={0};
	c[0]=c[1]=1;
	for(int i=2;i<N;i++){
		for(int j=0;j<i;j++){
			c[i]+=c[j]*c[i-j-1];
		}
	}
	int n;
	cin>>n;
	cout<<c[n]<<endl;
}