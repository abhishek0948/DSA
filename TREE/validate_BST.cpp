// https://www.codingninjas.com/studio/problems/validate-bst_799483?leftPanelTab=0&leftPanelTabValue=PROBLEM
#include"62_binary_tree.cpp"
//Approach 1 : By using recurrsion
bool isBST(Node *root,int min,int max){
    if(root==NULL){
        return true;
    }

    if(root->data >=min && root->data<=max){
        bool leftans=isBST(root->left, min, root->data);
        bool rightans=isBST(root->right, root->data , max);
        return leftans && rightans;
    }
    
    else{
        return false;
    }
 
}
bool validateBST(Node *root) {
   return isBST(root,INT_MIN,INT_MAX);
}

//Approach 2 : BY using inorder property of BST
void inorder(Node *root,vector<int> &ch){
    if(root==NULL){
        return;
    }

    inorder(root->left,ch);
    ch.push_back(root->data);
    inorder(root->right,ch);
}
bool validateBST(Node *root){
    vector<int> ch;

    inorder(root,ch);

    for(int i=1;i<ch.size();i++){
        if(ch[i]<ch[i-1]){
            return false;
        }
    }
    return true;
}