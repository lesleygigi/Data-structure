#include<bits/stdc++.h>
#include<queue>
#define N 1000
using namespace std;
typedef struct node{
	int data;
	int pidx;
	node* parent;
	vector<node*>child;
}node;
void preorder(node*root){
	cout<<root->data<<' ';
	for(int i=0;i<root->child.size();i++){
		preorder(root->child[i]);
	}
}
void levelorder(node*root){
	queue<node*>q;
	q.push(root);
	while(!q.empty()){
		node *t=q.front();
		q.pop();
		cout<<t->data<<' ';
		for(int i=0;i<t->child.size();i++)q.push(t->child[i]);
	}
}
void postorder(node*root){
	if(root){
		for(int i=0;i<root->child.size();i++){
			postorder(root->child[i]);
		}
		cout<<root->data<<' ';
	}
}
void getnodecnt(node*root,int&nodecnt,int&length,int now){
	if(root->child.size()==0){
		cout<<root->data<<' ';
		nodecnt++;
	}
	else {
		for(int i=0;i<root->child.size();i++)getnodecnt(root->child[i],nodecnt,length,now+1);
	}
	length=now>length?now:length;
}
int main(){
	node arr[N];
	int idx,pidx;
	int cnt=1;
	while(cin>>idx&&cin>>pidx){
		arr[cnt].data=idx;
		arr[cnt].pidx=pidx;
		arr[cnt].parent=NULL;
		cnt++;
	}
	node *root;
	for(int i=1;i<cnt;i++){
		if(arr[i].pidx==-1)root=&arr[i];
		else {
			arr[i].parent=&arr[arr[i].pidx];
			arr[arr[i].pidx].child.push_back(&arr[i]);
		}
	}
	root->parent=NULL;
	preorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl;
	levelorder(root);
	cout<<endl;
	cout<<cnt-1<<endl;
	int nodecnt=0,length=0;
	getnodecnt(root,nodecnt,length,0);
	cout<<endl;
	cout<<nodecnt<<endl;
	cout<<length<<endl;
}