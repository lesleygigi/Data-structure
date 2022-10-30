#include<iostream>
#include<list>
#include<map>
using namespace std;
typedef struct node{
    int data;
    node* next;
    node* pre;
}node;
int main(){//记得释放内存
    int pp,c;
    int cas=1;
    while(cin>>pp>>c&&!(pp==0&&c==0)){
        cout<<"Case "<<cas++<<':'<<endl;
        node *head,*tail;
        node *p=new node;
        p->data=1;
        node *cur=p;
        node *temp;
        if(pp>1000){
            for(int i=2;i<=1000;i++){
                temp=new node;
                temp->data=i;
                cur->next=temp;
                temp->pre=cur;
                cur=cur->next;
            }
        }
        else{
            for(int i=2;i<=pp;i++){
                temp=new node;
                temp->data=i;
                cur->next=temp;
                temp->pre=cur;
                cur=cur->next;
            }
        }
        head=p;
        tail=cur;
        head->pre=tail->next=NULL;
        while(c--){
            char cmd;
            node *t;
            cin>>cmd;
            if(cmd=='N'){
                cout<<head->data<<endl;
                t=head;
                head=head->next;
                tail->next=t;t->pre=tail;
                tail=tail->next;
            }
            if(cmd=='E'){
                int x;
                cin>>x;
                t=head;
                int flag=0;
                while(t->next!=NULL){
                    if(t->data==x){
                        flag=1;break;
                    }
                    else t=t->next;
                    if(t==tail&&t->data==x)flag=1;
                }
                if(flag==0){
                    t=new node;
                    t->data=x;
                    t->next=head;head->pre=t;
                    head=t;
                }
                else{
                    if(t!=head){
                        if(t==tail){
                            t->next=head;head->pre=t;
                            head=head->pre;
                            tail=tail->pre;
                        }
                        else{
                            t->pre->next=t->next;
                            t->next->pre=t->pre;
                            t->next=head;head->pre=t;
                            head=head->pre;
                        }
                    }
                }
            }
            head->pre=tail->next=NULL;
        }
        node *t;
        while(head){
            t=head;head=head->next;delete t;
        }
    }
}