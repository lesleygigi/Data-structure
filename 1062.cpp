#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	int cas=0;
	while(t--){
		int d[5][5];
		int cnt=0;
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++)cin>>d[i][j];
		}
		cout<<"case #"<<cas++<<':'<<endl;
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				int flag=1;
				for(int k=0;k<5;k++){
					if(d[i][k]>d[i][j]){flag=0;break;}
				}
				if(flag){
					for(int k=0;k<5;k++){
						if(d[k][j]<d[i][j]){flag=0;break;}
					}
				}
				if(flag){
					cnt++;
					cout<<i<<' '<<j<<endl;
				}
			}
		}
		if(cnt==0)cout<<"-1 -1"<<endl;
	}
}