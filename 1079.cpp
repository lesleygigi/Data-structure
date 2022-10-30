#include <bits/stdc++.h>
#define MAXN 107 // 最大节点个数
#define INFINITY_WEIGHT 0x3F3F3F // 权重无穷大
using namespace std;
typedef struct node{
    char data;//数据
    node* leftChild;
    node* rightChild;
    node* parent;//父节点

    char code;//标识是左节点还是右节点
    double weight;
    int leftcnt;//叶子结点个数
}NODE;
/**
 * [构建一课Huffman树]
 * @param  data[] [每个结点的值]
 * @param  weight[] [每个结点出现的频率]
 * @param  number [] [结点的个数]
 * @return   [Huffman树根]
 */
//你的程序需要正确输出每个字符的编码，且需要返回Huffman树的根节点。
struct cmp{
    bool operator()(const node*a,const node*b){//升序排序。因为优先队列默认是降序排序，所以这里的写法和普通sort相反
        if(a->weight==b->weight){
            if(a->leftcnt==b->leftcnt)return a->data>b->data;
            return a->leftcnt>b->leftcnt;
        }
        return a->weight>b->weight;
    }
};
/**
 * [构建一课Huffman树]
 * @param  data[] [每个结点的值]
 * @param  weight[] [每个结点出现的频率]
 * @param  number [] [结点的个数]
 * @return   [Huffman树根]
 */
NODE* createHuffmanTree(char data[], double weight[], int number){
    priority_queue<node*,vector<node*>,cmp>pq;
    node **a=new node*[number];
    for(int i=0;i<number;i++){//为所有叶子结点做初始化
        a[i]=new node;
        a[i]->data=data[i];
        a[i]->leftChild=a[i]->rightChild=NULL;
        a[i]->weight=weight[i];
        a[i]->leftcnt=1;
        pq.push(a[i]);
    }
    while(pq.size()>=2){
        node *temp=new node;//创立父节点
        temp->leftChild=pq.top();pq.pop();
        temp->leftChild->code='0';
        temp->rightChild=pq.top();pq.pop();
        temp->rightChild->code='1';
        temp->leftChild->parent=temp->rightChild->parent=temp;
        temp->data=temp->leftChild->data<temp->rightChild->data?temp->leftChild->data:temp->rightChild->data;
        temp->leftcnt=temp->leftChild->leftcnt+temp->rightChild->leftcnt;
        temp->weight=temp->leftChild->weight+temp->rightChild->weight;
        pq.push(temp);
    }
    node*head=pq.top();pq.pop();
    head->parent=NULL;
    for(int i=0;i<number;i++){
        int depth=0;
        string code="";
        node* temp=a[i];
        while(temp->parent){
            depth++;
            code+=temp->code;
            temp=temp->parent;
        }
        reverse(code.begin(),code.end());
        cout<<a[i]->data<<' '<<code<<' '<<depth<<' ';
        printf("%.3f\n",a[i]->weight*depth);
    }
    return head;
}

int main(int argc, const char* argv[]){
    char data[]="ABCDEFGH";
    double weight[]={0.4,0.15,0.15,0.1,0.1,0.05,0.04,0.01};
    int number=8;
    createHuffmanTree(data,weight,number);
}