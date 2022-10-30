#include<bits/stdc++.h>
#define N 6000
using namespace std;
// int main(){
// 	int n;
// 	cin>>n;
// 	while(n--){
// 		int d,i;
// 		cin>>d>>i;
// 		int state[N]={0};
// 		int no;
// 		int max=pow(2,d)-1;
// 		for(int k=0;k<i;k++){
// 			no=1;
// 			while(no<=max){
// 				state[no]=!state[no];
// 				no=state[no]?no*2:no*2+1;
// 				if(no>max)break;
// 			}
// 		}
// 		cout<<no/2<<endl;
// 	}
// }
// 每个小球都会落到结点上，只能往左或者往右，我们分析小球的奇偶性，
// 发现：若小球编号是奇数，则是往左落下的第（I+1）/2个小球；若
// 小球是偶数，则是往右落下的第I / 2个小球。以此判断来模拟最
// 后一个小球的路线。
int main(){
	int n;
	cin>>n;
	while(n--){
		int d,i;
		cin>>d>>i;
		int k=1;
		for(int j=0;j<d-1;j++){
			if(i%2){
				k=k*2;
				i=(i+1)/2;
			}
			else{
				k=k*2+1;
				i=i/2;
			}
		}
		cout<<k<<endl;
	}
}