#include<iostream>
using namespace std;
class qeue{
    private:
    int size, cursize, start, end;
    int *q;
    public:
    qeue(){
        q= new int [16];
        cursize=0;
        end=-1;
        start=0;
    }
    qeue(int maxsize){
        size=maxsize;
        q= new int[size];
        cursize=0;
        start=0;
        end=-1;
    }
    void push(int x){
        if(cursize==size){
            cout<<"the qeue is full "<<endl;
            exit(1);
        }
        end=(end+1)%size;
        q[end]=x;
        cursize++;
    }
    int pop(){
        if(cursize==0){
            cout<<"the qeue is already empty"<<endl;
            return -1;
        }
        start=(start+1)%size;
        cursize--;
    }
    int top(){
        if(cursize==0){
            throw runtime_error("the qeue is empty");
        }
        return q[start];
    }
    bool isempty(){
        return cursize==0;
    }
    void print(){
        if (isempty()) {
            cout << "Queue is empty.\n";
            return;
        }
        for(int i=0; i<cursize; i++){
            cout<<q[(start+i)%size]<<" ";
        }
        cout<<endl;
    }
    

};