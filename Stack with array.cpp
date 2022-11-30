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
   
Stack : Methods:
1- Push: To add element
2- Pop: To delete element
3- getTop: To get the last element we add it in the Stack
4- isEmpty: To check if stack is isEmpty
===========================================================
*/
const int MAX_SIZE =100;
class stack{
    int top;
    int item[MAX_SIZE];
public:
//@desc Constructor to give the top initial value
    stack(){
        top=-1;
    }
//@desc Method to push element to stack
    void push(int Element){
        if(top>=MAX_SIZE-1){
            cout<<"Stack is full on push";
        }else{
            top++;
        item[top] = Element;
        }
    }
//@desc Method to check if the stack is isEmpty
bool isEmpty(){
    if (top==-1){
        return true;
    }else{
        return false;
    }
}
//@desc Method to delete (pop) Element from the stack    
    void pop(){
        if (isEmpty()){
            cout<<"Stack is empty";
        }else{
            top--;
        }
    }
//@desc Method to pop element with saving element value
    void popWithSave(int&Element){
        if (isEmpty()){
            cout<<"Stack is empty on pop";
        }else{
            Element=item[top];
            top--;
        }
    }
//@desc Method to get the top Element
    void pop(int&stackTop){
        if (isEmpty()){
            cout<<"Stack is empty on get top";
        }else{
            stackTop=item[top];
           cout<<stackTop<<endl;
        }
    }
//@desc Method to print all stack elements
    void print(){
       if(isEmpty()){
           cout<<"Stack is empty on get stack data";
       }else{
           cout<<"[ ";
            for (int i=top;i>=0;i--){
            cout<<item[i]<<" ";
        }
        cout<<"]"<<endl;
       }
    }
};
int main() {
    stack myStack;
    myStack.push(5);
    myStack.push(10);
    myStack.push(12);
    myStack.push(15);
    myStack.push(20);
    myStack.print();
    
    myStack.pop();
    myStack.pop();
    myStack.print();
    
    
}