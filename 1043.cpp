#include<bits/stdc++.h>
using namespace std;
#define N 128

int bc[N];//坏字符数组
//建立坏字符数组
void generateBC(string str,int bc[]){
	for(int i=0;i<N;i++)bc[i]=-1;
	for(int i=0;i<str.size();i++)
		bc[str[i]]=i;
}


//建立好后缀数组，suffix为后缀字符对应前面的位置，prefix存储：是否存在匹配的前缀字串
void generateGS(string str,int suffix[],bool prefix[]){
	int n=str.size();
	for(int i=0;i<n-1;i++){
		suffix[i]=-1;
		prefix[i]=false;
	}
	for(int i=0;i<n-1;i++){
		int j=i;//从第一个字符开始遍历
		int k=0;//最后一个字符的变化,对应str[n-1-k];
		while(j>=0&&str[j]==str[n-1-k]){
			j--;
			k++;
			suffix[k]=j+1;//若k==1,则是一个字符长度的后缀对应匹配位置值
		}
		if(j==-1)//说明有前缀字符对应
			prefix[k]=true;
	}
}


//返回好后缀移动的次数,index为坏字符位置-其后面就是好后缀，size为str大小
int getGsmove(int suffix[],bool prefix[],int index,int size){
	int len=size-(index+1);//好字符的长度
	if(suffix[len]!=-1)//当前len长度的后缀坏字符串前边有匹配的字符
		return index+1-suffix[len];//后移位数=好后缀的位置(index+i)-搜索词中的上一次出现位置
	//index为坏字符位置，index+1为好后缀,index+2为子好后缀
	for(int i=index+2;i<size;i++){
		if(prefix[size-i])
			return i;
	}
	return 0;
}


int bm(string str,string pattern){
	int n=str.size();
	int m=pattern.size();
	int *suffix=new int[m];
	bool *prefix=new bool[m];
	generateBC(pattern,bc);
	generateGS(pattern,suffix,prefix);
	int i=0;
	while(i<=n-m){//i<n-m
		int j=0;
		for(j=m-1;j>=0;j--){
			if(pattern[j]!=str[i+j])//从后往前匹配str和patter
				break;
		}
		if(j<0)//匹配结束
		{
			delete[] prefix;
			delete[] suffix;
			return i;//返回模式串在文本串中首次出现的下标索引
		}
		else{
			int numbc=j-bc[str[i+j]];//bc移动的位数
			int numgs=0;
			if(j<m-1)//若最后一个字符就是坏字符，则无需判断好字符
			{
				numgs=getGsmove(suffix,prefix,j,m);
			}
			i+=numbc>numgs?numbc:numgs;
		}
	}
	delete[] prefix;
	delete[] suffix;
	return -1;
}
int main(){
	string a,b;
	cin>>a>>b;
	cout<<bm(a,b)<<endl;
}