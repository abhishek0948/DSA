// https://www.geeksforgeeks.org/introduction-to-trie-data-structure-and-algorithm-tutorials/
#include <bits/stdc++.h>
using namespace std;
class TrieNode
{   
    public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch){
        this->data = ch;
        this->isTerminal = false;
        for (int i = 0; i < 26; i++)
            this->children[i] = NULL;
    }
};

class Trie
{
    TrieNode *root;

    public:

    Trie(){
        root = new TrieNode('\0');
    }

    // function to insert node into the tries
    void insertUtil(TrieNode *&root, string word){
        if (word.length() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    /** Inserts a word into the trie. */

    void insert(string word){
        insertUtil(root, word);
    }

    // function to search in tries

    bool searchUtil(TrieNode *root, string word){
        if (word.length() == 0){
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL){
            child = root->children[index];
        }
        else
        {
            return false;
        }

        return searchUtil(child, word.substr(1));
    }

    /** Returns if the word is in the trie. */
    bool search(string word){
        return searchUtil(root, word);
    }

    // function to search the prefix present or not in tries
    bool prefixUtil(TrieNode *root, string word){
        if (word.length() == 0){
            return true;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            return false;
        }

        return prefixUtil(child, word.substr(1));
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */

    bool startsWith(string prefix){
        return prefixUtil(root, prefix);
    }
};

int main()
{
    Trie *root = new Trie();

    root->insert("AT");
    root->insert("BABY");
    root->insert("BALL");

    cout << root->search("BALL") << endl;
}