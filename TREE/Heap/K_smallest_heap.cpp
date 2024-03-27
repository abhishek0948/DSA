// https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1

#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int kthSmallest(int arr[], int l, int r, int k) {
       //Approach 1 : directing sorting 
        sort(arr,arr+r+1);
        return arr[k-1];
       
       //Approach 2 : by using heap
       priority_queue<int> q;
       
       for(int i=0;i<k;i++){
           q.push(arr[i]);
       }
       
       for(int i=k;i<r+1;i++){
           if(arr[i] < q.top()){
               q.pop();
               q.push(arr[i]);
           }
       }
       
       return q.top();
    }
};