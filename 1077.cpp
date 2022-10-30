#include<bits/stdc++.h>
#define N 100005
using namespace std;
typedef struct{
	string msg;
	int prior;
}winq;
int main(){
	int n;
	cin>>n;
	winq d[N];
	int size=0;
	while(n--){
		string cmd;
		cin>>cmd;
		if(cmd=="PUT"){
			cin>>d[size].msg>>d[size].prior;
			size++;
			int son=size-1;
			int dad=(son-1)/2;
			while(dad>=0){
				if(d[dad].prior<d[son].prior)break;
				else{
					swap(d[dad],d[son]);
					son=dad;
					if(!son)break;
					dad=(son-1)/2;
				}
			}
		}
		else{
			if(!size)cout<<"EMPTY QUEUE!"<<endl;
			else{
				cout<<d[0].msg<<endl;
				swap(d[0],d[size-1]);
				size--;
				int dad=0;
				int son=dad*2+1;
				while(son<size){
					if(son+1<size&&d[son+1].prior<d[son].prior)son++;
					if(d[dad].prior<d[son].prior)break;
					else{
						swap(d[dad],d[son]);
						dad=son;
						son=dad*2+1;
					}
				}
			}
		}
	}
}