#include<iostream>

#ifndef _RBQ_H_
#define _RBQ_H_
class RBQ
{
private:
    int *p;
    int *head;
    int *tail;
    int mysize;
    int MAXSIZE=100001;
public:
    void enqueue(int elem);//Enqueues elem if the queue has room; throws an string ( "Full" )exception if queue is full
    int dequeue();//Returns and removes the element at the front of the queue; throws astring( "-1" ) exception if queue is empty
    int peek();//Returns element at the front of the queue; throws a string( "-1" )exception if queue is empty
    bool isEmpty();//Returns true if queue is empty and false otherwise
    bool isFull();//Returns true if queue is full and false otherwise
    int size();//Returns number of elements in the queue.
    RBQ(/* args */);
    ~RBQ();
};
#endif

RBQ::RBQ(){
    p=new int[MAXSIZE];
    head=tail=p;
    mysize=0;
}
RBQ::~RBQ(){
    delete[] p;
}
bool RBQ::isFull(){
    if(mysize==MAXSIZE)return true;
    else return false;
}
bool RBQ::isEmpty(){
    if(mysize==0)return true;
    else return false;
}
void RBQ::enqueue(int elem){
    if(isFull()){
        throw "Full";
    }
    else{
        *tail=elem;
        if(tail==(p+MAXSIZE-1))tail=p;
        else tail++;
        mysize++;
    }
}
int RBQ::dequeue(){
    if(isEmpty()){
        throw "-1";
        return -1;
    }
    else{
        int ret=*head;
        if(head==(p+MAXSIZE-1))head=p;
        else head++;
        mysize--;
        return ret;
    }
}
int RBQ::peek(){
    if(isEmpty()){
        throw "-1";
    }
    else{
        return *head;
    }
}
int RBQ::size(){
    return mysize;
}

using namespace std;
int main(){
    int q;
    (cin>>q).get();
    RBQ circle{};
    while(q--){
        string cmd;
        (cin>>cmd).get();
        try{
            if(cmd=="dequeue"){
                int ret=circle.dequeue();
                if(ret!=-1)cout<<ret<<endl;
            }
            if(cmd=="enqueue"){
                int elem;
                (cin>>elem).get();
                circle.enqueue(elem);
            }
        }
        catch (const char * error){
            cout<<error<<endl;
        }
    }
}
