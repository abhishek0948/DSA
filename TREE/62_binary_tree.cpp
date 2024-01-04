#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* buildtree(Node* root){

    cout<<"Enter the data :"<<endl;
    int data;
    cin>>data;

    root=new Node(data);
    if(data==-1){
        return NULL;
    }

    cout<<"Enter the data for inserting in left :"<<endl;
    root->left=buildtree(root->left);
    cout<<"Enter the data for inserting in right :"<<endl;
    root->right=buildtree(root->right);

    return root;
}

void levelordertraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL); //To add a seperate between levels

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();

        if(temp==NULL){
            //previous level has been completely traversed
            cout<<endl;
            if(!q.empty()){
                //Queue has still some child nodes
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

//For iterative traversal use stack<Node*> 
//LNR
void inorder(Node* root){ 
    //base case
    if(root==NULL) return ;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

//NLR
void preorder(Node* root){
    //base case
    if(root==NULL) return ;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

//LRN
void postorder(Node* root){
    //base case
    if(root==NULL) return ;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void preOrderWithIteration(Node* root){

    stack<Node*> s;
    Node* curr = root; 
    while(!s.empty() || curr!=NULL){
        if(curr){
            cout<<curr->data<<" ";
            s.push(curr);
            curr= curr->left;
        }else{
            curr = s.top();
            s.pop(); 
            curr = curr->right;
        }
    };
}
void inOrderWithIteration(Node* root){

    stack<Node*> s;
    Node* curr = root; 
    while(!s.empty() || curr!=NULL){
        if(curr){
            
            s.push(curr);
            curr= curr->left;
        }else{
            curr = s.top();
            cout<<curr->data<<" ";
            s.pop(); 
            curr = curr->right;
        }
    };
}


/* 
TO DO : postOrderWithIteration(Node* root)
*/

//There is also boundary traversal and Diagonal traversal

int main(){
    Node* root=NULL;
    //Creating tree
    root=buildtree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    //LevelOrdertraversal
    // cout<<"Printing the LOT"<<endl;
    // levelordertraversal(root);cout<<endl;

    //Inorder
    inorder(root);cout<<endl;
    inOrderWithIteration(root);cout<<endl;

    //Preorder
    preorder(root);cout<<endl;
    preOrderWithIteration(root);cout<<endl;

    // //Postorder
    // postorder(root);cout<<endl;

    return 1;
}