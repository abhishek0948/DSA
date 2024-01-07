#include<iostream>
using namespace std;

int fact(int n){
    //base case
    if(n==0)
    return 1;
    
    //RR
    return n*fact(n-1);
}

int pow(int n){
    //base case
    if(n==0)
    return 1;

    //RR
    return 2*pow(n-1);
}

int main(){
    int n;
    cin>>n;
    cout<<fact(n)<<endl;

    int p;
    cin>>p;
    cout<<pow(p);

    return 1;
}