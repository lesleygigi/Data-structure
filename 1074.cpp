#include<bits/stdc++.h>
#define N 205
using namespace std;
void min_heapify(int arr[],int start,int end){
    //建立父节点指标和子节点指标
    int dad=start;
    int son=dad*2+1;
    while(son<=end){//若子节点指标在范围内才做比较
        if(son+1<=end&&arr[son+1]<arr[son])//先比较两个子节点大小，选择最大的那一个
            son++;
        if(arr[dad]<arr[son])//如果父节点大于子节点表示调整完毕，直接跳出函数
            return;
        else{//否则交换父子内容再继续子节点和孙节点的比较
            swap(arr[dad],arr[son]);
            dad=son;
            son=dad*2+1;
        }
    }
}
void heap_sort(int arr[],int len){
    //初始化，i从最后一个父节点开始调整
    for(int i=len/2-1;i>=0;i--){
        min_heapify(arr,i,len-1);
    }
    //先将第一个元素和已经排好序的元素的前一位做交换，再从新调整（）刚调整元素之前的元素，知道排序完毕
    for(int i=len-1;i>0;i--){
        swap(arr[0],arr[i]);
        min_heapify(arr,0,i-1);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    int arr[N];
    int t=m<n?m:n;
    for(int i=0;i<t;i++){
        scanf("%d",&arr[i]);
    }
    for(int j=t/2-1;j>=0;j--){
        min_heapify(arr,j,t-1);
    }
    for(int i=m;i<n;i++){
        int temp;
        scanf("%d",&temp);
        if(temp>arr[0]){
            swap(temp,arr[0]);
            int dad=0;
            int son=dad*2+1;
            while(son<t){//若子节点指标在范围内才做比较
                if(son+1<t&&arr[son+1]<arr[son])//先比较两个子节点大小，选择最大的那一个
                    son++;
                if(arr[dad]<arr[son])//如果父节点大于子节点表示调整完毕，直接跳出函数
                    break;
                else{//否则交换父子内容再继续子节点和孙节点的比较
                    swap(arr[dad],arr[son]);
                    dad=son;
                    son=dad*2+1;
                }
            }
        }
    }
    heap_sort(arr,t);
    for(int i=0;i<m&&i<n;i++){
        printf("%d ",arr[i]);
    }
}