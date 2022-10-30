#include<iostream>
using namespace std;
typedef struct node{
	int data;
	node* next;
	node* pre;
}node;
int main(){
	node* head=new node;
	head->data=-1;
	node*tail=head;
	head->pre=tail->next=NULL;
	node *temp;
	int q;
	cin>>q;
	int top=0;
	int flag=1;
	while(q--){
		int cmd;
		cin>>cmd;
		if(cmd==1){
			temp=new node;
			cin>>temp->data;
			if(flag){
				temp->pre=tail;
				tail->next=temp;
				tail=tail->next;
				tail->next=NULL;
				top++;
			}
			else{
				temp->pre=head;
				head->next=temp;
				temp->next=head->next;
				if(head->next)head->next->pre=temp;
			}
		}
		else if(cmd==2)top--;
		else if(cmd==3){
			if(flag)flag=0;
			else flag=1;
		}
		if(top==0)cout<<-1<<endl;
		else {
			if(flag)cout<<tail->data<<endl;
			else cout<<head->next->data<<endl;
		}
	}
}