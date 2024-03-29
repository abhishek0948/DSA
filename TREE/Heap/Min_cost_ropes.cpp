// https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
#include <bits/stdc++.h>
using namespace std;
long long minCost(long long arr[], long long n) {
    priority_queue<long long int,vector<long long >,greater<long long int>> q;
        
    for(long long int i=0;i<n;i++)
        q.push(arr[i]);
            
    long long int sum=0,ans=0;
        
    while(q.size() > 1){
        long long a=q.top();
        q.pop();
            
        long long b=q.top();
        q.pop();
            
        sum=a+b;
            
        ans=ans+sum;
        q.push(sum);
    }
        
    return ans;
}