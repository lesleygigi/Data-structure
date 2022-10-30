#include<bits/stdc++.h>
using namespace std;
void dfs(HUFFNODE*root,map<string,char>&decode,string s){
	if(!root)return;
	if(!root->leftChild&&!root->rightChild){
		decode[s]=root->data;
		return;
	}
	dfs(root->leftChild,decode,s+'0');
	dfs(root->rightChild,decode,s+'1');
}
void decipherHuffmanCoding(HUFFNODE* head, char cipher[]){
	map<string,char>decode;
	dfs(head,decode,"");
	string code="";
	for(int i=0;i<strlen(cipher);i++){
		code+=cipher[i];
		if(decode[code]){
			cout<<decode[code];
			code="";
		}
	}
	cout<<endl;
}