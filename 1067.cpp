#include<bits/stdc++.h>
using namespace std;
typedef struct node{
	string name;
	int isCata;//标记是目录或文件
	vector<node*>child;
}node;
bool cmp(node*a,node*b){
	if(a->isCata!=b->isCata)return a->isCata>b->isCata;
	return a->name<b->name;
}
void dfs(node*root,int level){
	if(root==NULL)return;
	for(int i=0;i<level;i++)cout<<"  ";
	cout<<root->name<<endl;
	sort(root->child.begin(),root->child.end(),cmp);
	for(int i=0;i<root->child.size();i++){
		dfs(root->child[i],level+1);
	}

}
int main(){
	int n;
	cin>>n;

	//建立根节点
	node*root=new node;
	root->name="root";
	root->isCata=1;
	

	string temp,str;
	node* curRoot;
	for(int j=0;j<n;j++){
		curRoot=root;
		cin>>str;
		for(int i=0;i<=str.size();i++){
			if(str[i]=='\\'){//目录
				//在当前父目录中寻找，判断其是否存在
				int flag=0;
				//有该目录
				for(int k=0;k<curRoot->child.size();k++){
					if(curRoot->child[k]->name==temp&&curRoot->child[k]->isCata==1){
						//则切换当前目录
						curRoot=curRoot->child[k];
						flag=1;
						break;
					}
				}
				if(!flag){//没有该目录则创建该目录
					node* newnode=new node;
					newnode->name=temp;
					newnode->isCata=1;
					//将该结点加入父目录
					curRoot->child.push_back(newnode);
					//切换当前目录
					curRoot=newnode;
				}
				temp.clear();
			}
			else if(i==str.size()){//文件
				if(!temp.empty()){//到达最后，而单词不空，说明是文件
					//将文件加入父节点中
					node* newnode=new node;
					newnode->name=temp;
					newnode->isCata=0;
					curRoot->child.push_back(newnode);
				}
				temp.clear();
			}
			else{//字符
				temp+=str[i];
			}
		}
	}
	dfs(root,0);
}