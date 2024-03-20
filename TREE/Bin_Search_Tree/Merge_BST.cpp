#include"62_binary_tree.cpp"
using namespace std;
//Approach 1 : By flatting tree to link list and merging 
//Step 1 : Convert the given to tree to LL
//Step 2 : merge the to sorted LL
//Step 3 : Build a BST from merged LL
 
//Approach 2 : By using 2 arrays  SC : O(m+n)
void inorder(Node* root,vector<int> &in){
    if(root==NULL)
        return ;

    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

vector<int> merge(vector<int> &arr1,vector<int> &arr2){
    vector<int> merged(arr1.size()+arr2.size());

    int i=0;int j=0;int k=0;

    while( i< arr1.size() && j < arr2.size()){
        if(arr1[i] < arr2[j]){
            merged[k++]=arr1[i++];
        }
        else{
            merged[k++]=arr2[j++];
        }
    }

    while(i < arr1.size()){
        merged[k++]=arr1[i++];
    }

    while(i < arr2.size()){
        merged[k++]=arr2[j++];
    }
}

Node* inordertoBST(int s,int e,vector<int> &in){
    if(s > e)
        return NULL;

    int mid = (s+e)/2;
    Node* root=new Node(in[mid]);
    root->left=inordertoBST(s,mid-1,in);
    root->right=inordertoBST(mid+1,e,in);
    return root;
}
Node* mergeBST(Node* root1,Node* root2){
    //Step 1 : strore inorder
    vector<int> arr1,arr2;
    inorder(root1,arr1);
    inorder(root2,arr2);

    //Step 2 : Merge two sorted arrays
    vector<int> mergedarr=merge(arr1,arr2);

    //Step 3 : Convert inorder to BST
    int s=0;int e=mergedarr.size()-1;
    return inordertoBST(s,e,mergedarr);
}