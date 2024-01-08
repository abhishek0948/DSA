#include<bits/stdc++.h>
using namespace std;
void print(int *arr,int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
void bubblesort(int *arr,int size){
    print(arr,size);
    if(size==0)
        return ;
    if(size==1)
        return ;

    for(int i=0;i<size;i++){
        if(arr[i]>arr[i+1])
            swap(arr[i],arr[i+1]);
    }
    
    bubblesort(arr,size-1);
    
}
int main(){
    int arr[6]={100,-2,30,14,5,20};
    bubblesort(arr,6);
    print(arr,6);
}