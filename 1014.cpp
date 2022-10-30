#include<iostream>
using namespace std;
typedef struct node{
	int data;
	node *pre;
	node *next;
}node;
node *creat(int n){
	node *p=new node;
	p->data=0;
	p->pre=p;
	p->next=p;
	if(n){
		p->data=1;
		node *cur=p;
		node *temp;
		for(int i=2;i<=n;i++){
			temp=new node;
			temp->data=i;
			temp->pre=cur;
			cur->next=temp;
			cur=cur->next;
		}
		cur->next=p;
	}
	return p;
}
int main(){
	int n,i,k;
	cin>>n>>i>>k;
	node *head=creat(n);
	node *p=head;
	while(p->next!=p){
		for(int k=0;k<i;k++){
			p=p->next;
		}
		cout<<p->data<<' ';
		node *t=p->next;
		node *pre=p;
		node *next=t->next;
		pre->next=next;
		next->pre=pre;
		delete t;
	}
	cout<<p->data<<endl;
}