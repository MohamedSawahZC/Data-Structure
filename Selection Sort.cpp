#include <iostream>
using namespace std;

void selectionSort(int arr[],int n){
  int minIdx;
	                               //0  1  2  3  4  5
	for (int i = 0; i < n - 1; i++)//60 40 50 30 10 20
	{	
		minIdx = i;//4
    
		for (int j = i + 1; j < n; j++)
			if (arr[j] < arr[minIdx])
				minIdx = j;
	            swap(arr[minIdx], arr[i]);
	
	}
}
void print(int arr[],int n){
    cout<<"[ ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"]"<<endl;
    
}
void swap(int&x,int&y){
    int temp=x;
    x=y;
    y=temp;
}
int main() {
    int arr[] = { -60, 0, 50, 30, 10,20 };
    selectionSort(arr,6);
    print(arr,6);
}