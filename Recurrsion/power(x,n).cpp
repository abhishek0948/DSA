// https://leetcode.com/problems/powx-n/
//Approach 1 : Recurrsive approach
class Solution {
public:
    double solve(double x,long n){
        if(n==0) 
            return 1;

        if(n<0)
            return solve(1/x,-n);

        if((n%2)==0)
            return solve(x*x,n/2);

        return x*solve(x*x,(n-1)/2);
    }
    double myPow(double x, int n) {
        return solve(x,(long)n);
    }
};

//Approach 2 : iterative approach
class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long nn=n;
        if(nn<0) nn = -1 * nn;
        
        while(nn){
            if(nn%2){
                ans=ans*x;
                nn=nn-1;
            }
            else{
                x=x*x;
                nn=nn/2;
            }
        }

        if(n<0) ans=(double)(1.0)/(double)(ans);
        return ans;
    }
};