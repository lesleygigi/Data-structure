#include<bits/stdc++.h>
using namespace std;
typedef struct node{
	int data;
	node* left;
	node* right;
}node;
node* create(const string&exp,int &idx){
	if(idx>=exp.size())return NULL;
	while(idx<exp.size()&&exp[idx]!='(')idx++;
	idx++;
    int sign=1;
	int num=0;
	int flag=0;
    if(idx<exp.size()&&exp[idx]=='-'){sign=-1;idx++;}
	while(idx<exp.size()&&exp[idx]!='('&&exp[idx]!=')'){
		flag=1;
		num=num*10+exp[idx]-'0';
		idx++;
	}
	if(!flag)return NULL;
	node* root=new node;
    num*=sign;
	root->data=num;
	root->left=create(exp,idx);
	root->right=create(exp,idx);
	return root;
}
void dfs(node*root,int val,int n,int &ret){
	if(root&&!root->left&&!root->right&&val+root->data==n)ret=1;
	if(!root||ret)return;
	dfs(root->left,val+root->data,n,ret);
	dfs(root->right,val+root->data,n,ret);
}
int main(){
	int n;
	while(cin>>n){
		string exp;
		int l=0,r=0;
		char ch;
		while((ch=getchar())!='(');
		exp+=ch;
		l++;
		while(r<l){
			ch=getchar();
			if(ch==' '||ch=='\n')continue;
			else if(ch=='(')l++;
			else if(ch==')')r++;
			exp+=ch;
		}
		while((ch=getchar())!='\n');
        int idx=0;
		node *root=create(exp,idx);
		int ret=0;
		dfs(root,0,n,ret);
		if(ret)cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
}