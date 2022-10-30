#include<bits/stdc++.h>
using namespace std;
int d[26];
void df(string t,int m){//根据模式串t,计算d数组,t的长度为m
	for(int i=0;i<m;i++)d[i]=m;
	for(int i=0;i<m-1;i++){
		d[t[i]-'a']=m-(i+1);//根据定义，从左到右扫描p串的0~m-2的字符,最后一个字符不扫描
	}
}
int bm(string s,string t,int n,int m){
	int i,j,k;
	i=m-1;//从后向前匹配
	do{
		j=m-1;//指针j移动到t串的最后，从后向前比较
		k=i;//在依次比较的过程中,i指针不移动,k移动
		while(j>=0&&t[j]==s[k]){
			j--,k--;
		}
		if(j<0)return i+1-m;//找到匹配,返回s中匹配开始的位置
		i=i+d[s[i]-'a'];//没有匹配成功,i指针后移；
		//如果s[i]字符没有在t中出现,则指针向后移动m个位置
		//如果s[i]字符只出现在t的最后，指针也向后移动m个位置
		//如果s[i]字符是x，它出现在t的0~m-2的某个位置，则指针向后移动，让当前t[i]和p的最后一个x字符对齐
	}while(i<n);
	return -1;
}
int main(){
	string s,t;
	cin>>s>>t;
	int n=s.length(),m=t.length();
	df(t,m);
	cout<<bm(s,t,n,m)<<endl;
	for(int i=0;i<26;i++)cout<<d[i]<<' '; 
}