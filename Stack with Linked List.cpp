#include <iostream>
using namespace std;
/*
==================== Stack Description ====================
Stack work with Strategy LIFO (Last In First Out)
- Last Element added is the first element will deleted when
  we use Stack
Stack Examples:
1- Keyboard (When you type a char and try delete this char
   you delete last char added)
2- Browsing on web and go back from the current page to the
   last page you was in
-----------------------------------------------------------
Q: Why we need to use a Linked list in some situations?
A: Because array have a fixed size and it will be a big
   problem if we don't know how coming data is big
-----------------------------------------------------------
Our Stack Method:
Pop()
Push()
getTop()
display()
===========================================================
*/
template <class t>
class stack{
private:
    struct node{
        t item;
        node *next;
    };
    node *top,*currentPtr;
    
public:
//@desc Call constructor to add initial value to our top while creating stack
    stack(){
        top=NULL;
    }

//@desc Method to push data to our stack(Linked list)
void push(t newItem){
    node *newItemPtr = new node;
    if (newItemPtr==NULL){
        cout<<"Stack cannot allocate memory"<<endl;
    }else{
           newItemPtr->item=newItem;
    newItemPtr->next=top;
    top = newItemPtr;
    }
 
}
//@desc Method to check if stack is empty
bool isEmpty(){
    return top==NULL;
}

//@desc Method to pop element from stack
void pop(){
    if(isEmpty()){
        cout<<"Stack is empty on pop"<<endl;
    }else{
        node *temp = top;
        top = top->next;
        temp=temp->next =NULL;
        delete temp;
    }
}

//@desc Method to pop element from stack and save deleted element or value
void popWithSave(t&stackTop){
    if(isEmpty()){
        cout<<"Stack is empty on pop"<<endl;
    }else{
        stackTop=top->item;
        node*temp = top;
        top = top->next;
        temp=temp->next =NULL;
        delete temp;
    }
}

//@desc Method to get element on the top
void getTop(t&stackTop){
    if(isEmpty()){
        cout<<"Stack is empty on get top"<<endl;
    }else{
        stackTop = top->item;
    }
}

//@desc Method to display all stack elements
void display(){
    currentPtr = top;
    cout<<"\n Items in stack: ";
    cout<<"[ ";
    while(currentPtr!=NULL){
        cout<<currentPtr->item<<" ";
        currentPtr=currentPtr->next;
    }
    cout<<"]\n";
}

};

int main() {
    stack<int> MyStack;
    MyStack.push(5);
    MyStack.push(10);
    MyStack.push(20);
    MyStack.display();
    int x=0;
    MyStack.getTop(x);
    cout<<" Top is: "<<x<<endl;
    MyStack.pop();
   
    MyStack.display();
     MyStack.getTop(x);
    cout<<" Top is: "<<x<<endl;
   
}