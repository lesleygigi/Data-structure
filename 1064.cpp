#include<bits/stdc++.h>
#include<vector>
using namespace std;
char c;
typedef struct node{
	int lev;
	char data;
	node* parent;
	vector<node*>child;
}node;
node *creat(node* tree,int n){
	node*p=tree;
	node*t;
	for(int i=1;i<n;i++){
		t=new node;
		cin>>c>>t->lev>>c>>t->data>>c>>c;
		if(p->lev==t->lev)p=p->parent;
		p->child.push_back(t);
		t->parent=p;
		p=t;
	}
	return tree;
}
void post(node* tree){
	for(int i=0;i<tree->child.size();i++){
		post(tree->child[i]);
	}
	cout<<tree->data;
}
int main(){
	int n;
	cin>>n;
	node* tree=new node;
	tree->parent=NULL;
	cin>>c>>tree->lev>>c>>tree->data>>c>>c;
	tree=creat(tree,n);
	post(tree);
}