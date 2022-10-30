#include<iostream>
using namespace std;
typedef struct node{
	int data;
	node*pre;
	node*next;
}node;
int main(){
	int m,n;
	cin>>m>>n;
	int dic[10000]={0};
	node *head=new node;
	int word;
	cin>>word;
	head->data=word;
	dic[word]=1;
	node *p=head;
	node *temp;
	int ret=1;
	int len=1;
	for(int i=1;i<n;i++){
		cin>>word;
		if(dic[word]==0){
			ret++;
			if(len==m){
				temp=head;
				dic[temp->data]=0;
				head=head->next;
				delete temp;
			}
			temp=new node;
			temp->data=word;
			temp->pre=p;
			p->next=temp;
			p=p->next;
			if(len!=m)len++;
			dic[word]=1;
		}
	}
	cout<<ret<<endl;
}