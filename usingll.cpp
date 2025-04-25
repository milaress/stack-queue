#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node(int a){
        data=a;
        next=nullptr;
    }
};
class mystack{
    private:
    Node* top;
    public:
    mystack(){
        top=nullptr;
    }
    void push(int a){
        Node* newnode= new Node(a);
            newnode->next=top;
            top=newnode;
    }
    int pop(){
        if(top==nullptr){
            cout<<"stack already empty /n";
            return -1;
        }
        int poppedvalue=top->data;
        Node* temp= top;
        top=top->next;
        delete temp;
        return poppedvalue;
    }
    bool empty(){
        return top==nullptr;
    }
    void display(){
        if(top==nullptr){
            cout<<"stack is empty";
            return;
        }
        Node* it=top;
        while(it!=nullptr){
            cout<<it->data<<" ";
            it=it->next;
        }
        cout<<endl;
    }
};