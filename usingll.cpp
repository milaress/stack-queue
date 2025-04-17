#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
class qeue
{
private:
    Node* start;
    Node* end;
    int size;
public:
    qeue(): start(nullptr),end(nullptr),size(0){}

    void push(int x){
        Node* newnode = new Node[x];
        if(start==nullptr){
            start=end=newnode;
        }else{
            end->next=newnode;
            end=newnode;
        }
        size++;
    }

    void pop(){
        if(start==nullptr){
            cout<<"the queue is already empty"<<endl;
        }
        Node* temp=start;
        start=start->next;
        //if the queue becomes empty
        if(start==nullptr){
            end=nullptr;
        }
        delete temp;
        size--;
    }

    int top(){
        return start->data;
    }

    bool empty(){
        return start==nullptr;
    }

    void print(){
        Node* temp=start;
        while (temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

