#include<bits/stdc++.h>
#include<iostream>
#include<map>
#include<string>
#include<sstream>
#define N 1000
using namespace std;
// 一定包含 ticky:
// 紧跟日志等级，日志等级分为 ernode 和 INFO 2 个等级：
// 错误可能包含以上示例以外的其他错误信息
// 任何一条错误信息的最长长度不超过 1024 个字节
// 错误信息只包含 Extended ASCII（即 ASCII 编码从 0 ~ 255）中的可见字符和空格。
// 假设任何一个用户名的长度不超过 64 个字节，
map<string,string>month{{"Jan","01"},{"Feb","02"},{"Mar","03"},{"Apr","04"},
						{"May","05"},{"Jun","06"},{"Jul","07"},{"Aug","08"},
						{"Sep","09"},{"Oct","10"},{"Nov","11"},{"Dec","12"}};
typedef struct{
	string time="";
	bool state=false;
	string info="";
	string username="";
}node;

typedef struct{
	int er=0;
	int in=0;
	string name="";
}user;

typedef struct{
	string info="";
	string time="";
	int cnt=0;
}ernode;

int cmp1(const node&a,const node&b){
	return a.info<b.info;
}

int cmp2(const ernode&a,const ernode&b){
	if(a.cnt==b.cnt){
		if(a.time==b.time)return a.info<b.info;
		return a.time<b.time;
	}
	return a.cnt>b.cnt;
}

int cmp3(const user&a,const user&b){
	return a.name<b.name;
}
int main(){
	int n=0;
	node data[N];
	user userdata[N];
	string s;
	while(cin>>s){
		int flag=1;
		data[n].info=data[n].time=data[n].username="";
		data[n].time+=month[s];
		cin>>s;
		if(s.size()<2)s='0'+s;
		data[n].time+=s;cin>>s;data[n].time+=s;
		cin>>s;
		cin>>s;
		if(s!="ticky:"){getline(cin,s);flag=0;}
		if(flag==0)continue;
		cin>>s;
		if(s=="INFO")data[n].state=true;
		else data[n].state=false;
		while(cin>>s&&s[0]!='(')data[n].info=data[n].info+s+' ';
		data[n].info.pop_back();
		data[n].username=s.substr(1);
		while(getchar()!='\n'){
			cin>>s;
			data[n].username=data[n].username+' '+s;
		}
		data[n].username.pop_back();
		s=data[n].username;
		int hash=0;
		for(int i=0;i<s.size();i++){
			hash=hash*255+s[i];
			hash%=N;
		}
		while(userdata[hash].name!=""&&userdata[hash].name!=s)hash=(hash+1)%N;
		userdata[hash].name=s;
		if(data[n].state)userdata[hash].in++;
		else userdata[hash].er++;
		n++;
	}
	sort(data,data+n,cmp1);
	ernode erdata[N];int idx1=0;
	for(int i=0;i<n;){
		if(!data[i].state){
			erdata[idx1].info=data[i].info;
			erdata[idx1].time=data[i].time;
		}
		else {
			i++;continue;
		}
		while(erdata[idx1].info==data[i].info){
			erdata[idx1].cnt++;
			erdata[idx1].time=data[i].time<erdata[idx1].time?data[i].time:erdata[idx1].time;
			i++;
		}
		idx1++;
	}
	sort(erdata,erdata+idx1,cmp2);
	cout<<"ERROR MESSAGE"<<endl<<"ERROR,COUNT"<<endl;
	for(int i=0;i<idx1;i++){
		cout<<erdata[i].info<<','<<erdata[i].cnt<<endl;
	}
	sort(userdata,userdata+N,cmp3);
	cout<<"USER STATISTICS"<<endl<<"USERNAME,INFO,ERROR"<<endl;
	int idx2=0;
	while(idx2<N&&userdata[idx2].name=="")idx2++;
	while(idx2<N){
		cout<<userdata[idx2].name<<','<<userdata[idx2].in<<','<<userdata[idx2].er<<endl;
		idx2++;
	}
}