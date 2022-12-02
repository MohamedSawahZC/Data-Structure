#include <iostream>
#include <cassert>
using namespace std;
template<class t>
class linkedQueue{
    private:
    struct Node{
        t item;
        Node *next;
    };
    Node *frontPtr;
    Node *rearPtr;
    int length;
public:
    linkedQueue(){
        frontPtr=rearPtr=NULL;
        length=0;
    }
//@desc Method to check if queue is empty
bool isEmpty(){
    return length ==0;
}
//@desc Method to add (push) element to queue
void enqueue(t element){ 
    if(isEmpty()){
        frontPtr = new Node;
        frontPtr->item=element;
        frontPtr->next=NULL;
        rearPtr=frontPtr;
        length++;
    }else{
        Node *newPtr=new Node;
        newPtr->item=element;
        newPtr->next=NULL;
        rearPtr->next=newPtr;
        rearPtr=newPtr;
        length++;
    }
}
//@desc Method to delete element from queue (pop)
void dequeue(){
    if(isEmpty()){
        cout<<"Queue is already empty.."<<endl;
    }else{
        Node *tempPtr = frontPtr;
        if(frontPtr==rearPtr){
            frontPtr=NULL;
            rearPtr=NULL;
            length=0;
        }else{
            frontPtr=frontPtr->next;
            tempPtr->next=NULL;
            delete tempPtr;
            length--;
        }
    }
}
//@desc Method to get front
t getFront(){
    assert(isEmpty());
    return frontPtr->item;
}
//@desc Method to get rear
t getRear(){
    assert(isEmpty());
    return rearPtr->item;
}
//@desc Method to get front and store it
void getFrontWithSave(int&element){
    element = frontPtr->item;
}
//@desc Method to clear Queue
void clearQueue(){
    if(isEmpty()){
        cout<<"Queue already is empty"<<endl;
    }else{
        Node *current;
        while(frontPtr!=NULL){
            current=frontPtr;
            frontPtr=frontPtr->next;
            delete current;
        }
        rearPtr = NULL;
        length=0;
    }
}

//@desc Method to display queue items
void display(){
   if(isEmpty()){
       cout<<"Queue is empty"<<endl;
   }else{
        Node *current=frontPtr;
    cout<<"[ ";
    while(current!=NULL){
        cout<<current->item<<" ";
        current=current->next;
    }
    cout<<"]"<<endl;
   }
}
//@desc Method to get queue size
int getSize(){
    return length;
}


};
int main() {
   linkedQueue<int> q1;
   q1.display();
   q1.clearQueue();
   q1.dequeue();
   q1.enqueue(10);
   q1.enqueue(20);
   q1.display();
      cout<<q1.getSize()<<endl;
   q1.dequeue();
   q1.display();
   cout<<q1.getSize()<<endl;
}