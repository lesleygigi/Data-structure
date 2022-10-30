#include<bits/stdc++.h>
#define N 10005
using namespace std;

long long int ret=LONG_LONG_MAX;
int retval=INT_MAX;
typedef struct node{
	int val;
	node*left;
	node*right;
}node;
node* create(int in[],int post[],int b1,int n1,int n2){
	if(n1-b1<0)return NULL;
	node *root=new node;
	root->val=post[n2];
	int pos;
	for(int i=b1;i<=n1;i++){
		if(in[i]==post[n2]){
			pos=i;break;
		}
	}
	int rightnum=n1-pos;
	root->left=create(in,post,b1,pos-1,n2-1-rightnum);
	root->right=create(in,post,pos+1,n1,n2-1);
	return root;
}
void dfs(node *root,int nowval){
	if(root==NULL)return;
	if(root->left==NULL&&root->right==NULL){
		if(nowval+root->val<ret){
			ret=nowval+root->val;
			retval=root->val;
		}
		else if(nowval+root->val==ret){
			retval=root->val<retval?root->val:retval;
		}
	}
	else{
		dfs(root->left,nowval+root->val);
		dfs(root->right,nowval+root->val);
	}
}
int main(){
	int in[N];
	int post[N];
	int n=0,t;
	while(cin>>t){
		in[n++]=t;
		if(getchar()=='\n')break;
	}
	for(int i=0;i<n;i++){
		cin>>post[i];
	}
	node* root=create(in,post,0,n-1,n-1);
	dfs(root,0);
	cout<<retval<<endl;
}