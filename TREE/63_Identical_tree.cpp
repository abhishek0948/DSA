#include"62_binary_tree.cpp"
// https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1
//-------------------------------------------------------------------------------------
//Approach 1 : Recurrsion
// class Solution
// {
//     public:
//     //Function to check if two trees are identical.
//     bool isIdentical(Node *r1, Node *r2)
//     {
//         //Your Code here
//         if(!r1  || !r2){
//             if(r1 || r2) return false;
//             else{
//                 return true;
//             }
//         }
        
//         bool leftans=isIdentical(r1->left,r2->left);
//         bool rightans=isIdentical(r1->right,r2->right);
//         bool ch= r1->data==r2->data ;
//         if(leftans&& rightans && ch ) return true;
//         else return false;
        
//     }
// };
//----------------------------------------------------------------------------------------
//Approach 2 : iterative 
// bool isIdentical(Node *r1, Node *r2)
//     {
//         vector<int> v1,v2;
//         queue<Node*> q1,q2;
//         q1.push(r1);
//         q2.push(r2);
//         while(!q1.empty()){
//             auto q=q1.front();
//             q1.pop();
//             v1.push_back(q->data);
//             if(q->left) q1.push(q->left);
//             if(q->right) q1.push(q->right);
//         }
//         while(!q2.empty()){
//             auto q=q2.front();
//             q2.pop();
//             v2.push_back(q->data);
//             if(q->left) q2.push(q->left);
//             if(q->right) q2.push(q->right);
//         }
//         return v1==v2;
//     }