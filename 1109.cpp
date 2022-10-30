#include<bits/stdc++.h>
#define N 10005
using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[N];
	for(int i=0;i<n;i++)cin>>arr[i];
	for(int i=1;i<n;i++){
		int l=0,r=i-1;
		int cmpcnt=0;
		while(l<=r){
			int mid=(l+r)/2;
			if(arr[i]>=arr[mid])l=mid+1;
			else r=mid-1;
			cmpcnt++;
		}
		int t=arr[i];
		for(int j=i-1;j>=l;j--)arr[j+1]=arr[j];
		arr[l]=t;
		cout<<cmpcnt<<endl;
	}
}