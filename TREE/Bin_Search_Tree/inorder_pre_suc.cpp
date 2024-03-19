// https://www.codingninjas.com/studio/problems/_893049?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&leftPanelTabValue=DISCUSS

#include<bits/stdc++.h>
using namespace std;
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    TreeNode* temp=root;
    int pred=-1;
    int suc= -1 ;

    while(temp && temp->data != key){

        if(temp->data >  key){
            suc=temp->data;
            temp=temp->left;
        }

        else{
            pred=temp->data;
            temp=temp->right;
        }

    }
    if (temp){
    TreeNode* lefttree=temp->left;
    while(lefttree!=NULL){
        pred=lefttree->data;
        lefttree=lefttree->right;
    }

    TreeNode* righttree=temp->right;
    while (righttree != NULL) {
        suc = righttree->data;
        righttree = righttree->left;
    }
    }   

    return { pred, suc };
}