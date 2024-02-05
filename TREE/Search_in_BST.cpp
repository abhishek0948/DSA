// https://www.codingninjas.com/studio/problems/search-in-bst_1402878?leftPanelTabValue=SUBMISSION
#include"62_binary_tree.cpp"

//Approach 1 : Recurrsive way (extra fun call space)
bool searchInBST(Node *root, int x) {
    if(root==NULL)
        return false;

    if(root->data==x){
        return true;
    }

    else if(root->data<x){
        return searchInBST(root->right, x);
    }

    else if(root->data>x){
        return searchInBST(root->left,x);
    }
}

//Approach 2 : Iterative way 
bool searchInBST(Node *root, int x) {
    
    Node* temp=root;
    while(temp!=NULL){

        if(temp->data==x){
            return true;
        }
        else if(temp->data<x){
            temp=temp->right;
        }
        else{
            temp=temp->left;
        }
    }
    return false;
}