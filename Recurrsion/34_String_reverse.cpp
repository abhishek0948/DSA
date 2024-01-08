// https://www.codingninjas.com/studio/problems/reverse-the-string_799927?leftPanelTab=0
#include <bits/stdc++.h> 
using namespace std;
void ans(string &st,int s,int e){

	if(s>e)
	  return ; 
	
	swap(st[s],st[e]);
	s++;e--;
	ans(st,s,e);
	
}

string reverseString(string str)
{   
	ans(str,0,str.length()-1);
	return str;
}