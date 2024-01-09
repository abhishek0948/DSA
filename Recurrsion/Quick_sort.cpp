#include<iostream>
using namespace std;
int partition(int *arr,int s,int e){
    int pivot=arr[s];

    int cnt=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivot)
            cnt++;
    }

    //Place pivot at right position
    int pivotindex=s+cnt;
    swap(arr[s],arr[pivotindex]);

    //Sort left part < pivot and right > pivot
    int i=s;int j=e;

    while(i < pivotindex && j > pivotindex){
        while(arr[i] < pivot){
            i++;
        }

        while(arr[j] > pivot){
            j--;
        }

        if(i < pivotindex && j > pivotindex){
            swap(arr[i++],arr[j--]);
        }
    }

    return pivotindex;
}
void quicksort(int *arr,int s,int e){
    //Base Case
    if(s>=e)
        return ;
    //Pivot point
    int pivot=partition(arr,s,e);
    //Left part
    quicksort(arr,s,pivot-1);
    //Right part
    quicksort(arr,pivot+1,e);
}

int main(){
    int arr[10]={-1,2,100,0,-100,10,3,9,1,8};

    quicksort(arr,0,9);

    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }

    return 1;
}

//------------------------------------------------------------------------------------------------------------
//For reference between Lomutos and Hoare Parition - 
//https://www.geeksforgeeks.org/hoares-vs-lomuto-partition-scheme-quicksort/

//Lomutos Parition scheme - Taking last element as a pivot
int Lomutospartition(int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(arr[i], arr[j]); 
        } 
    } 
    swap(arr[i + 1], arr[high]); 
    return (i + 1); 
} 
void Lomutosquicksort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = Lomutospartition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        Lomutosquicksort(arr, low, pi - 1); 
        Lomutosquicksort(arr, pi + 1, high); 
    } 
} 

//Hoare's Parition Scheme - Taking first element as pivot 
//Note - Pivot is not placed at its right position in Hoare's Partion 
int Hoarepartition(int arr[], int low, int high) 
{ 
    int pivot = arr[low]; 
    int i = low - 1, j = high + 1; 
  
    while (true) { 
        // Find leftmost element greater than 
        // or equal to pivot 
        do { 
            i++; 
        } while (arr[i] < pivot); 
  
        // Find rightmost element smaller than 
        // or equal to pivot 
        do { 
            j--; 
        } while (arr[j] > pivot); 
  
        // If two pointers met. 
        if (i >= j) 
            return j; 
  
        swap(arr[i], arr[j]); 
    } 
} 

void HoarequickSort(int arr[], int low, int high) 
{ 
    if (low < high) { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = Hoarepartition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        HoarequickSort(arr, low, pi); 
        HoarequickSort(arr, pi + 1, high); 
    } 
} 

  