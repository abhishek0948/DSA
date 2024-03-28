// https://www.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1
#include<bits/stdc++.h>
using namespace std;
//Approach 1 : By pushing arrs and heapifying 
class Solution{
    public:
    void heapify(vector<int> &arr,int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

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
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> ans;
        for(auto i:a)
            ans.push_back(i);   
        for(auto i:b)
            ans.push_back(i);
      
        int size=ans.size();
        for(int i=(size/2)-1;i>=0;i--){
            heapify(ans,size,i);
        }
        
        return ans;
    }
};
//----------------------------------------------------------------------------------------------------
//Approach 2 : By inserting one element in the array and using heap insertion 
class Solution{
    public:
    void insert(vector<int>& a, int x)
    {
        int size = a.size();
        a.push_back(x);
        
        for(int i = size; i != 0 && a[i] > a[(i - 1) / 2];)
        {
            swap(a[i], a[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        for(int i = 0; i < m; i++)
            insert(a, b[i]);
        return a;
    }
};
//-------------------------------------------------------------------------------------------------------
//Approach 3 : by directly using STL funcion 
class Solution{
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        for(int i=0;i<m;i++){
            a.push_back(b[i]);
        }
        make_heap(a.begin(),a.end());
        return a;
    }
};