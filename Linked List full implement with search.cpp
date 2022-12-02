#include <iostream>
using namespace std;
class linkedList{
private:
    struct Node{
        int item;
        Node *next;
    };
    Node *first;
    Node *last;
    int length;
public:
    linkedList(){
        first=last=NULL;
        length=0;
    }

//@desc Method to check if list empty
bool isEmpty(){
    return length==0;
}
//@desc Method to insert element
void insertFirst(int element){
    Node *newNode=new Node;
    newNode->item=element;
    if(length==0){
        first=last=newNode;
        newNode->next=NULL;
    }else{
        newNode->next=first;
        first=newNode;
    }
     length++;
}

//@desc Method to insert element at last
void insertLast(int element){
    Node *newNode=new Node;
    newNode->item=element;
    if(length=0){
         first=last=newNode;
        newNode->next=NULL;
    }else{
        last->next=newNode;
        newNode->next=NULL;
        last=newNode;
    }
    length++;
}

//@desc Method to insert at position
void insertAt(int pos,int element){

    if(pos<0||pos>length){
        cout<<"Out of range ..."<<endl;
    }
        Node *newNode=new Node;
    newNode->item=element;
    if(pos==0){
        insertFirst(element);
    }else if(pos==length){
        insertLast(element);
    }else{
        Node *current=first;
        for(size_t i=1;i<pos;i++){
            current=current->next;
        }
        newNode->next=current->next;
        current->next=newNode;

    }
    length++;
}
//@desc Method to print or display linkedList
void print(){
    Node *current=new Node;
    current=first;
    cout<<"[ ";
    while(current!=NULL){
        cout<<current->item<<" ";
        current=current->next;
    }
    cout<<"]"<<endl;
}

//@desc Method to remove first
void removeFirst(){
    if(length==0){
        return;
    }else if(length==1){
        delete first;
        last=first=NULL;
        length--;
    }else{
        Node *current = first;
        first=first->next;
        delete current;
        length--;
    }
}

//@desc Method to remove last
void removeLast(){
       if(length==0){
        return;
    }else if(length==1){
        delete first;
        last=first=NULL;
        length--;
    }else{
        Node *current=first->next;
        Node *prev=first;
        while(current!=last){
            prev=current;
            current=current->next;
            delete current;
            prev->next=NULL;
        }
    } 
}

//@desc Method to remove by element
void remove(int element){
    if(isEmpty()){
        return;
    }else{
        Node *current,*prev;
        if(first->item==element){
            current=first;
            first=first->next;
            delete current;
            length--;
        }
        if(length==0){
                last=NULL;
            }else{
                current=first->next;
                prev=first;
                while(current!=NULL){
                if(current->item==element)
                        break;
                    
                prev=current;
                current=current->next;
                }
                if(current==NULL){
                    cout<<"element not found"<<endl;
                }else{
                    prev->next=current->next;
                    if(last==current) last=prev;
                  delete current;
                    length--;

                }
                  
            }
    }
}
//@desc Method to reverse linked list
void reverse(){
    Node *prev,*current,*next;
    prev=NULL;
    current=first;
    next=current->next;
    while(next!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    first=prev;
}

//@desc Method to search for element
int search(int element){
  Node *current = first;
	int pos = 0;
	while (current != NULL)
	{
		if (current->item == element)
			return pos;
		current = current->next;
		pos++;
	}
	return -1;
}

    
};
int main() {
    linkedList l;
    l.insertFirst(10);
    l.insertLast(20);
    l.insertFirst(30);
    l.print();
    l.insertAt(1,12);
    l.print();
    l.remove(12);
    l.print();
    l.reverse();
    l.print();
    cout<<"10 in : "<<l.search(10)<<endl;

}