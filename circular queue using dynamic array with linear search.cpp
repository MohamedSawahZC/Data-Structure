#include <iostream>
#include <cassert>

using namespace std;
/*
 ================================Queue ================================
 Queue work with FIFO (First in First out)
 Real Examples:
 1- Cinema Queue
 2- Clinic Reservation
 3- Printer
 4- Call Center System
 5- CPU Scheduling in Operating System [Task 1 , Task 2 , Task 2]
 In Queue:
  ~ We add in the back
  ~ Delete from the head
Note:
rear initial value = MAX_SIZE -1;
rear = (rear+1) % MAX_SIZE;
Elements between front,rear this is the queue range
Methods:
    isEmpty() : For check if queue is isEmpty
    isFull() : For check if queue is full
    enqueue(): To add element to queue
    dequeue(): To delete element (pop) from the queue
    getFront(): To get the front
    getRear(): To get the rear
    getSize(): To get stack size
    clear(): To clear the queue
 ======================================================================
*/
const int MAX_SIZE = 100;
class arrayQueueType{
private:
    int rear; //you can call it back
    int front; //you can call it head
    int length;
    int *arr;
    int maxSize;
public:
    arrayQueueType(int size){
        if(size<=0){
            maxSize=100;
        }else{
            maxSize=size;
        }
        front=0; //First element in the queue
        rear=maxSize-1; //100-1 = 99 end of the queue
        length=0;
        arr=new int[maxSize] ;
    }
//@desc Method To check if the queue is isEmpty
int isEmpty()
	{
		return length == 0;
	}
//@desc Method  To check if the queue full
bool isFull(){
    return length==maxSize;
}
//@desc Method to add to queue
void addQueue(int element){
    if(isFull()){
        cout<<"Queue full cannot Enqueu..."<<endl;
    }else{
        rear = (rear + 1) % maxSize;
			arr[rear] = element;
			length++;
    }
}
//@desc Method to delele from the queue
void deleteQueue(){
    if(isEmpty()){
        cout<<"Empty queue cannot dequeue..."<<endl;
    }else{
        front = (front+1)%maxSize;
        --length;
    }
}

//@desc Method to get front from the queue
    int frontQueue(){
       	assert(!isEmpty());
		return arr[front];
    }
//@desc Method to get rear from the queue
    int rearQueue(){
        assert(!isEmpty()); //assert stop the program if there is any problem
        return arr[rear];
    }
//@desc Method to get front in variable
void getFront(int&getFront){
    getFront = arr[front];
}
//@desc Method to print Queue elements
void printQueue(){
    if(isEmpty()){
        cout<<"Sorry empty Queue"<<endl;
    }else{
        cout<<"[ ";
    for(size_t i = front; i != rear; i = (i + 1) % maxSize){
        cout<<arr[i]<<" ";
    }
    cout << arr[rear];
    cout<<" ]"<<endl;
    }
}

//@desc Method to search in Queue
int queueSearch(int element){
   int pos = -1;
		if (!isEmpty())
		{
			for (int i = front; i != rear; i = (i + 1) % maxSize)
				if (arr[i] == element)
				{
					pos = i;
					break;
				}
			if (pos == -1)
			{
				if (arr[rear] == element)
					pos = rear;
			}
		}
		else
			cout << "Q is empty ! " << endl;
		return pos;
}



};


int main() {
    arrayQueueType q1(10);
    q1.printQueue();
    q1.addQueue(10);
    q1.addQueue(12);
    q1.addQueue(20);
    q1.addQueue(30);
    q1.printQueue();
    cout<<q1.frontQueue()<<endl;
    q1.deleteQueue();
    q1.printQueue();
    cout<<q1.frontQueue()<<endl;
    cout<<q1.queueSearch(20)<<endl;
    return 0;
}