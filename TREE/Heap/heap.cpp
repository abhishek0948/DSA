#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
    int *arr;
    int size;

    heap(){
        arr=new int [100];
        arr[0]=-1;
        size=0;
    }

    void insert(int data){
        size=size+1;
        int index=size;
        arr[index]=data;

        while(index > 1){
            int parent=index/2;

            if(arr[parent] < arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return ;
            }

        }
    }

    void deletefromheap(){
        if(size==0){
            cout<<"Nothing to delete :"<<endl;
            return ;
        }
        //deleting root
        arr[1]=arr[size];
        size--;

        //Take root to its correct position 
        int i=1;
        while (i <= size)
        {   
            //This is for 1 based indexing             //For zero based indexing
            int left=2*i ;                             //int leftindex=2*1 + 1;
            int right=2*i + 1;                         //int leftindex=2*1 + 2;

            if(left<=size && right<=size){
                if(arr[left]>arr[right] && arr[left]>arr[i]){
                    swap(arr[left],arr[i]);
                    i=left;
                }
                else if(arr[left]<arr[right] && arr[right]>arr[i]){
                    swap(arr[right],arr[i]);
                    i=right;
                }
                else{
                    return;
                }
            }
            else if(left<=size && arr[left]>arr[i]){
                swap(arr[left],arr[i]);
                i=left;
            }
            else if(right<=size && arr[right]>arr[i]){
                swap(arr[right],arr[i]);
                i=right;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }

};

void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;

    if(left<n && arr[largest]<arr[left]){
        largest=left;
    }
    if(right<n && arr[largest]<arr[right]){
        largest=right;
    }

    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }

    return;
}

int main(){
    heap h1;
    h1.insert(10);
    h1.insert(20);
    h1.insert(1);
    h1.insert(40);
    h1.insert(-5);
    h1.print();
    // h1.deletefromheap();
    // h1.print();


    int arr[6]={-1,10,20,1,40,-5};
    int n=5;
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }

    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    
    return 1;
}