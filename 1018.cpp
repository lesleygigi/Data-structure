#include<iostream>
#include<string>
using namespace std;


//环形队列 搜索超时
typedef struct node{
	string name;
	int d;
	node *pre,*next;
}node;
int main(){
	int n,m;
	cin>>n>>m;
	node *head=new node;
	cin>>head->d>>head->name;
	node *p=head;
	node *temp;
	for(int i=1;i<n;i++){
		temp=new node;
		cin>>temp->d>>temp->name;
		p->next=temp;
		temp->pre=p;
		p=p->next;
	}
	p->next=head;
    head->pre=p;
	p=head;
	int flag,k;
	for(int i=0;i<m;i++){
		cin>>flag>>k;
		if(p->d==0){
			if(flag==0){
				for(int j=0;j<k;j++)p=p->pre;
			}
			else for(int j=0;j<k;j++)p=p->next;
		}
		else{
			if(flag==0){
				for(int j=0;j<k;j++)p=p->next;
			}
			else for(int j=0;j<k;j++)p=p->pre;
		}
	}
	cout<<p->name<<endl;
}


//静态数组 随机访问 效率高
#include<iostream>
#include<string>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	string data[100005];
    bool d[100005];
    for(int i=0;i<n;i++){
        cin>>d[i]>>data[i];
    }
    int idx=0;
    int flag,k;
    for(int i=0;i<m;i++){
        cin>>flag>>k;
        if(d[idx]==0){
            if(flag==0){
                idx-=k;if(idx<0)idx+=n;
            }
            else {
                idx+=k;if(idx>=n)idx-=n;
            }
        }
        else{
            if(flag==0){
                idx+=k;if(idx>=n)idx-=n;
            }
            else {
                idx-=k;if(idx<0)idx+=n;
            }
        }
    }
    cout<<data[idx]<<endl;
}