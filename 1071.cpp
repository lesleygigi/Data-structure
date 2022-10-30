#include<bits/stdc++.h>
using namespace std;
typedef struct node{
	int val;
	node*left;
	node*right;
	int h;
}node;
int height(node* root){
	return root==NULL?0:root->h;
}
int max(int a,int b){
	return a>b?a:b;
}
int balance(node* root){
	if(root==NULL)return 0;
	return height(root->left)-height(root->right);
}

//单旋转
//LL失衡作右旋转，RR失衡作左旋转,镜像对称

//root为最小不平衡二叉树的根节点，插入的结点插在root的左孩子的左子树上
//需要将root的左孩子作为新的根节点
node* LL_rotate(node* root){
	node* x=root->left;
	root->left=x->right;//root的左子树变为x的右子树
	x->right=root;//root变为其左子树的右子树
	root->h=max(height(root->left),height(root->right))+1;
	x->h=max(height(x->left),height(x->right))+1;
	return x;
}
node* RR_rotate(node* root){
	node* x=root->right;
	root->right=x->left;
	x->left=root;
	root->h=max(height(root->left),height(root->right))+1;
	x->h=max(height(x->left),height(x->right))+1;
	return x;
}

//复合旋转

//先左旋再右旋
//新插入的结点位于root的左孩子root1的右子树上
//那么首先需要对以root1为根节点的子树进行左旋(RR_rotate)
//然后对以root为根节点的子树进行右旋
node* LR_rotate(node* root){
	root->left=RR_rotate(root->left);
	return LL_rotate(root);
}

//先右旋再左旋
//与上面的情况是对称的
node* RL_rotate(node* root){
	root->right=LL_rotate(root->right);
	return RR_rotate(root);
}

//调节失衡二叉树
//node为当前失衡节点
node* re_balance(node* root){
    if (!root)
        return root;
    int bf=balance(root);
    int bf_l=balance(root->left);
    int bf_r=balance(root->right);
    if(bf>1 && bf_l>0)
        root=LL_rotate(root);
    if(bf>1 && bf_l<0)
        root=LR_rotate(root);
    if(bf<-1 && bf_r<0)
        root=RR_rotate(root);
    if(bf<-1 && bf_r>0)
        root=RL_rotate(root);
    return root;
}

//插入操作
node* insert(node* root,int val){
	if(!root){
		root=new node;
		root->val=val;
		root->h=1;
		root->left=NULL;
		root->right=NULL;
		return root;
	}
	if(val<root->val){
		root->left=insert(root->left,val);
	}
	else if(val>root->val){
		root->right=insert(root->right,val);
	}
	//先调整高度，再平衡二叉树
	root->h=max(height(root->left),height(root->right))+1;
	root=re_balance(root);
	return root;
}
int main(){
	node* root=NULL;
	int n;
	cin>>n;
	int v;
	for(int i=0;i<n;i++){
		cin>>v;
		root=insert(root,v);
	}
	cout<<root->val<<' '<<root->h<<endl;
}