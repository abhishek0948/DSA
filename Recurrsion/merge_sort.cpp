#include<iostream>
using namespace std;
void print(int *arr,int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
void merge(int *arr,int s,int e){
    if(s>=e) 
        return;

    int mid=(s+e)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid ;

    int *first=new int[len1];
    int *second=new int[len2];

    //Copying
    int mainindex=s;
    for(int i=0;i<len1;i++){
        first[i]=arr[mainindex++];
    }
    mainindex=mid+1;
    for(int i=0;i<len2;i++){
        second[i]=arr[mainindex++];
    }

    //Merging two sorted arrays
    int index1=0,index2=0;
    mainindex=s;
    while(index1 < len1 && index2 < len2 ){
        if(first[index1] < second[index2]){
            arr[mainindex++]=first[index1++];
        } 
        else{
            arr[mainindex++]=second[index2++];
        }
    }

    while(index1 < len1){
        arr[mainindex++]=first[index1++];
    }
    while(index2 < len2){
        arr[mainindex++]=first[index2++];
    }
    // cout<<"Printing in merge : ";
    // int size=e-s+1;
    // print(arr,size);
}

void mergesort(int *arr,int s,int e){
    if(s>=e)
        return ;

    int mid=(s+e)/2;
    //left part
    mergesort(arr,s,mid);
    //Right part
    mergesort(arr,mid+1,e);

    //Merging
    merge(arr,s,e);
}

int main(){
    int arr[5]={5,1,0,-10,-20};
    mergesort(arr,0,4);
    print(arr,5);

    return 1;
}