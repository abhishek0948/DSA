//https://www.codingninjas.com/studio/problems/find-k-th-smallest-element-in-bst_1069333?leftPanelTab=0&leftPanelTabValue=DISCUSS

//Approach 1 : Using inorder , SC : O(H)
// void inorder(BinaryTreeNode<int>* root, int k,int &count,int &ans){
//     if(root==NULL){
//         return ;
//     }

//     inorder(root->left,k,count,ans);
//     count++;
//     if(count==k)
//         ans=root->data;
//     inorder(root->right,k,count,ans);
// }
// int kthSmallest(BinaryTreeNode<int>* root, int k) {
//     int count=0;int ans=-1;
//     inorder(root,k,count,ans);
//     return ans;
// }
//-------------------------------------------------------------------------------------------------
//Approach 2 : Using morris Traversal , SC : O(1)
// int morrisTraveersal(BinaryTreeNode<int>* root, int& i, int k){
//     BinaryTreeNode<int>* curr = root;
//     BinaryTreeNode<int>* predecessor = NULL;
//     while(curr != NULL){
//         if(curr->left == NULL){
//             if(i++ == k){
//                 return curr->data;
//             }
//             curr = curr->right;
//         }
//         else {
            
//             predecessor = curr->left;
//             while(predecessor->right != NULL && predecessor->right != curr){
//                 predecessor = predecessor->right;
//             }

//             //now we have 2 possible case
//             //1st the predecessor right is pointing to null
//             if(predecessor->right == NULL){
//                 predecessor->right = curr;
//                 curr = curr->left;
//             }
//             else {
//                 //case 2 predecessor right is already pointing to curr 
//                 predecessor->right = NULL;
//                 if(i++ == k)    
//                     return curr->data;

//                 curr = curr->right;
//             }
//         }
//     }

//     return -1;
// }