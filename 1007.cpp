#include<iostream>
using namespace std;
typedef struct node{
	int data;
	node *pre;
	node *next;
}node;
int main(){
	node *head=new node;
	cin>>head->data;
	node *p=head;
	node *temp;
	int n;
	while(cin>>n&&n!=-1){
		temp=new node;
		temp->data=n;
		p->next=temp;
		temp->pre=p;
		p=p->next;
	}
	p->next=head;
	head->pre=p;
	int flag=0;
	while(cin>>n&&n!=-1){
		p=head;
		while(p!=p->next){
			if(p->data==n){
				flag=1;
				p->pre->next=p->next;
				p->next->pre=p->pre;
				temp=p;p=p->next;
				delete temp;
			}
			if(flag==0)cout<<-1<<endl;
			flag=0;
		}
	}
	while(p!=p->next){
		cout<<p->data<<' ';
		p=p->next;
	}
}