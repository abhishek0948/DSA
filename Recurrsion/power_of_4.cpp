// https://leetcode.com/problems/power-of-four/solutions/4197471/c-log2-vs-bitset-vs-1-line-0ms-beats-100/
#include<bits/stdc++.h>
using namespace std;
//Approach 1 : Recurrsion
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<1) return false;

        if(n==1) return true;

        return n%4==0 && isPowerOfFour(n/4);
    }
};

//Approach 2 : Bit Set
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n<0) return 0;
        bitset<31> x(n);
        if (x.count()!=1) return 0;
        for(int i=0; i<31; i+=2)
            if(x[i]) return 1;
        return 0;
    }
};

//Approach 3 : Bit masking 
bool isPowerOfFour(int n) {
    return n>0 && !(n & (n-1)) && !(n & 0x2aaaaaaa);
}
