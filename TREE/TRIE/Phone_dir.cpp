//https://www.naukri.com/code360/problems/implement-a-phone-directory_1062666?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
    char ch;
    TrieNode* children[26];
    bool isEnd;
 
    TrieNode(char c){
        ch = c;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        isEnd = false;
    }
};

class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode('\0');
    }

    void insert(TrieNode* root,string word){

        if(word.length()==0){
            root->isEnd = true;
            return;
        }

        TrieNode* child;
        int index = word[0] - 'a';

        if(root->children[index]==NULL){
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        else{
            child = root->children[index];
        }

        insert(child,word.substr(1));
    }

    void print_all_list(TrieNode* curr,vector<string> &temp,string prefix){

        if(curr->isEnd){
            temp.push_back(prefix);
        }

        for(char ch='a'; ch<'z'; ch++){
            TrieNode* next = curr->children[ch-'a'];

            if(next!=NULL){
                prefix.push_back(ch);
                print_all_list(next,temp,prefix);
                prefix.pop_back();
            }

        }

    }

    vector<vector<string>> getalllist(string str){

        TrieNode* prev = root;
        vector<vector<string>> output;

        string prefix;

        for(int i=0;i<str.size();i++){
            char lastch = str[i];

            prefix.push_back(lastch);

            //check for lastch
            TrieNode* curr = prev->children[lastch-'a'];

            if(curr==NULL){
                break;
            }

            vector<string> temp;

            print_all_list(curr,temp,prefix);

            output.push_back(temp);

            temp.clear();

            prev = curr;

        }   
        return output;
    }

};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{

    int n = contactList.size();
    Trie* t = new Trie();

    for(int i=0;i<n;i++){
        t->insert(t->root,contactList[i]);
    }

    return t->getalllist(queryStr);

}