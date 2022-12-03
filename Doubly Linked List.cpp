#include <iostream>
using namespace std;
class doublyLinkedList{
private:
    struct Node{
        int item;
        Node *next;
        Node *prev;
    };
    Node *first;
    Node *last;
    int length;
public:
    doublyLinkedList(){
        first=last=NULL;
        length=0;
    }

//@desc Method to check if linked list is empty
bool isEmpty(){
    return length==0;
}
//@desc Method to insert at linked list
void insert(int element){
    Node *newNode = new Node();
    newNode->item=element;
    if(length==0){
        first=last=newNode;
        newNode->next=newNode->prev=NULL;
    }else{
        newNode->next=first;
        newNode->prev=NULL;
        first->prev=newNode;
        first=newNode;
    }
    length++;
}
//@desc Method to insert at linked list in last
void insertLast(int element){
    Node *newNode=new Node();
    newNode->item=element;
    if(length==0){
        first=last=newNode;
        newNode->next=newNode->prev=NULL;
    }else{
        newNode->next=NULL;
        newNode->prev=last;
        last->next=newNode;
        last=newNode;
    }
    length++;
}
//@desc Method to insert at specific position
void insertAt(int pos,int element){
    if(pos<0 || pos>length){
        cout<<"Out of range .."<<endl;
    }
    Node *newNode=new Node();
    newNode->item=element;
    if(pos==0){
         insert(element);
    }else if(pos==length){
        insertLast(element);
    }else{
       Node *current = first;
       for(int i=1;i<pos;i++){
           current=current->next;
       }
       newNode->next=current->next;
       newNode->prev=current;
       current->next=newNode;
    }
    length++;
    
}
//@desc Method to delete from first
void removeFirst(){
    if(length==0){
        cout<<"Empty list ...!"<<endl;
    }else if(length==1){
        delete first;
        last=first;NULL;
        length--;
    }else{
        Node *current=first;
        first=first->next;
        first->prev=NULL;
        delete current;
        length--;
    }
}

//@desc Method to remove last
void removeLast(){
     if(length==0){
        cout<<"Empty list ...!"<<endl;
    }else if(length==1){
        delete first;
        last=first;NULL;
        length--;
    }else{
        Node *current=last;
        last=last->prev;
        last->next=NULL;
        delete current;
        length--;
    }
}

//@desc Method to remove by element
	void removeByElement(int item)
	{
		if (isEmpty())
		{
			cout << "Empty List Can't Remove ";
			return;
		}
		Node*current = first->next;

		if (first->item == item)//delete the first element, special case
		{
			/*
			first = current->next;
			if (first != NULL)
				first->prev = NULL;
			delete current;
			return;
			*/
			removeFirst();
			return;
		}
		else
		{
			

			while (current != NULL)//current->item!=element
			{
				if (current->item == item)
					break;
				current = current->next;
			}

			if (current == NULL) {
				cout << "The item is not there\n";
				return;
			}
			else if (current->next == NULL) {
				removeLast();
				return;
			}

			else
			{
				current->prev->next = current->next;
				//if (current->next != NULL)
				current->next->prev = current->prev;
				delete current;
				length--;
			}

		}


	}
//@desc Method to display linked list
void display() {
		if (isEmpty())
		{
			cout << "Empty List Can't Display...!";
		}
		else {
			Node* temp = first;
			while (temp != nullptr) {
				cout << temp->item << " ";
				temp = temp->next;
			}
		}
		cout << endl;

	}
//@desc Method to reverse Display
void reverse_display() {
		if (isEmpty())
		{
			cout << "Empty List Can't Display Reverse...!";
		}
		else
		{
			Node* temp = last;
			while (temp != NULL) {
				cout << temp->item << " ";
				temp = temp->prev;
			}
		}

	}

};
int main() {
   doublyLinkedList dl;
	dl.insertAt(0, 4);
	dl.insertAt(1, 6);
	dl.insertAt(2, 7);
	dl.insert(2);
	dl.insertLast(10);
	dl.removeByElement(7);
	dl.display();
	dl.reverse_display();
}