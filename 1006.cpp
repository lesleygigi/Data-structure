#include<iostream>
using namespace std;

typedef struct node
{
    int data;   //存储数据
    struct node* next;  //指向下一个节点的指针
} NODE;
NODE* insertLinklist(NODE* head, int tar, int val) {
   NODE *t=new NODE;
   t->data=val;
   if(head==NULL){
    head=t;
    head->next=NULL;
   }
   else{
      NODE *p=head;
      while(p->data!=tar)p=p->next;
      t->next=p->next;
      p->next=t;
   }
   return head;
}

NODE* deleteLinklist(NODE* head, int tar){
   if(head){
    if(head->data==tar){
        NODE *p=head;
        head=head->next;
        delete p;
    }
    else{
        NODE*p=head;
        int flag=0;
        while(p->next){
            if(p->next->data==tar){
                flag=1;break;
            }
            else p=p->next;
        }
        if(flag){
            NODE*t=p->next->next;
            delete p->next;
            p->next=t;
        }
    }
   }
   return head;
}

NODE* createLinklist(){
    NODE *p=NULL;
    int n;
    cin>>n;
    if(n){
        p=new NODE;
        p->data=0;
        NODE *cur=p;
        for(int i=0;i<n;i++){
            NODE *temp=new NODE;
            cin>>temp->data;
            cur->next=temp;
            cur=cur->next;
        }
        cur->next=NULL;
    }
    return p;
}
int main()
{
    /* 输入及其他处理，细节隐藏不表 */

    NODE* head = createLinklist();    
    int q;
    cin>>q;
    while(q--){
        int cmd;
        cin>>cmd;
        int tar,val;
        if(cmd==0){
            cin>>tar>>val;
            head=insertLinklist(head,tar,val);
        }
        else{
            cin>>tar;
            head=deleteLinklist(head,tar);
        }
    }

    NODE *p=head->next;
    while(p){
        cout<<p->data<<' ';
        p=p->next;
    }
    return 0;
}