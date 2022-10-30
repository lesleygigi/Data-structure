#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct poem{
    vector<string>s;
    poem *last=NULL;
    poem *next=NULL;
};
int main(){
    int p,n;
    (cin>>p>>n).get();
    poem **data=new poem*[p];
    string line;
    for(int i=0;i<p;i++){
        data[i]=new poem;
        for(int j=0;j<n;j++){
            getline(cin,line);
            (data[i]->s).push_back(line);
        }
    }
    for(int i=0;i<p;i++){
        for(int j=0;j<p;j++){
            if(i!=j&&data[j]->next==NULL){
                if(data[j]->s[n-1]==data[i]->s[0]){
                    data[j]->next=data[i];
                    data[i]->last=data[j];
                    break;
                }
            }
        }
    }
    poem *head;
    for(int i=0;i<p;i++){
        if(data[i]->last==NULL){
            head=data[i];break;
        }
    }
    while(head){
        for(int i=0;i<n-1;i++){
            cout<<(head->s)[i]<<endl;
        }
        if(!head->next)cout<<(head->s)[n-1]<<endl;
        head=head->next;
    }
 }