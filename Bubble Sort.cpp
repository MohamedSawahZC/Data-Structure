#include <iostream>
using namespace std;
void bubbleSort(int arr[],int n){
    bool flag=true;
    int counter=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag=false;
            }
            counter++;
        }
        if(flag==true){
            break;
        }
    }
    cout<<"Counter : "<<counter<<endl;
}
void swap(int&x,int&y){
    int temp=x;
    x=y;
    y=temp;
}
void print(int arr[],int n){
    cout<<"[ ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"]"<<endl;
    
}
int main() {
     int arr[] = { -60, 0, 50, 30, 10,20 };
      bubbleSort(arr,6);
      print(arr,6);
}