#include<bits/stdc++.h>
using namespace std;
#define N 10005
typedef struct node{
	int val;
	node* left;
	node* right;
}node;
node* create(int preorder[],int start,int end){
	if(start>=end)return NULL;
	node *root=new node;
	root->val=preorder[start];
	int i;
	for(i=start+1;i<end;i++){
		if(preorder[i]>preorder[start])break;
	}
	root->left=create(preorder,start+1,i);
	root->right=create(preorder,i,end);
	return root;
}
void postorder(node* root){
	if(!root)return;
	if(!root->left&&!root->right){
		cout<<root->val<<endl;return;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->val<<endl;
}
int main(){
	int preorder[N];
	int n=0;
	while(cin>>preorder[n++]);
	node *root=create(preorder,0,n-1);
	postorder(root);
}