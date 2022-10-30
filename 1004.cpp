#include<iostream>
using namespace std;

int n;
int listdelete(int *list,int k){
	if(k<1||k>n)return -1;
	int e=list[k];
	for(int i=k;i<n;i++){
		list[i]=list[i+1];
	}
	--n;
	return e;
}

void listinsert(int *list,int k,int x){
	for(int i=n+1;i>k+1;i--){
		list[i]=list[i-1];
	}
	list[k+1]=x;
	++n;
}

int main(){
	cin>>n;
	int list[1000000]={0};
	for(int i=1;i<=n;i++){
		cin>>list[i];
	}
	int q;
	cin>>q;
	while(q--){
		int cmd;
		cin>>cmd;
		int k,x;
		switch(cmd){
		case 1:
            cin>>k>>x;
			listinsert(list,k,x);
			break;
		case 2:
			cin>>k;
			cout<<listdelete(list,k)<<endl;
			break;
		}
	}
}//