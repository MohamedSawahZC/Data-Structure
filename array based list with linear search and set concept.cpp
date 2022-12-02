#include <iostream>
using namespace std;
class arrayList{
    private:
    int *arr;
    int MAX_SIZE;
    int length;
public:
    arrayList(int size=10){
        if(size<=0){
            MAX_SIZE=10;
        }else{
            MAX_SIZE=size;
        }
        length=0;
        arr = new int[MAX_SIZE];
        
    }
//@desc Method to check if the array isEmpty
bool isEmpty(){
    return length==0;
}
//@desc Method to check if dynamic array is full
bool isFull(){
    return length==MAX_SIZE;
}
//@desc Method to get array size
int getSize(){
    return length;
}
//@desc Method to print elements
void print(){
    cout<<"[ ";
    for (size_t i=0; i<length;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"]"<<endl;
}
//@desc Method to push to array in specific index
void insertAt(int pos,int element){
    if(isFull()){
    }else if(pos<0 || pos>length){
        cout<<"Out of range.. "<<endl;
    }else{
        for(size_t i=length;i>pos;i--){
		arr[i] = arr[i - 1];	//shift right
        }
        arr[pos] = element;	//insert the item at the specified position
        length++;	//increment the length
    }
}
//@desc Method to remove on position
void removeAt(int pos){
    if(isEmpty()){
        cout<<"Empty List"<<endl;
    }else if(pos<0||pos>length){
        cout<<"Out of range"<<endl;
    }else{
        for(size_t i=pos;i<length;i++){
            arr[i]=arr[i+1];
            length--;
        }
    }
}
//@desc Method to insert element at the end of list
void insertAtEnd(int element){
    if(isFull()){
        cout<<"List is full on add at end"<<endl;
    }else{
        arr[length] = element;
        length++;
    }
}

//@desc Method to search on specific element in our list
int search(int element){
    for(size_t i=0;i<length;i++){
        if(arr[i]==element){
            return i;
        }else{
            return -1;
        }
        
    }
}

//@desc Method insertWithout duplicate

void insertDuplicate(int element){
    if(search(element)==-1){
        insertAtEnd(element);
    }else{
        cout<<"Element already in ...!"<<endl;
    }
}
//@desc Method to update in specific position
void updateAtPosition(int pos,int element){
    if(pos<0||pos>=length){
        cout<<"Out of range ..."<<endl;
    }else{
        arr[pos]=element;
    }
}

//@desc Method to print element in specific position
int getElement(int pos){
    if(pos<0||pos>=length){
        cout<<"Out of range ..."<<endl;
    }else{
        return arr[pos];
    }
}

//@desc delete elements after finish work from memory
~arrayList(){
    delete[] arr;
}

//@desc Method to clear
void clear(){
    length=0;
}


};

int main() {
    arrayList arr;
    arr.insertAt(0,10);
    arr.insertAt(1,20);
    arr.insertAtEnd(30);
    arr.print();
    
}