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

Node* minval(Node* root){
    Node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

//TC : O(log(n))
Node* insert(Node* root,int t){
    if(root==NULL){
        Node* temp=new Node(t);
        return temp;
    }


    if(t<root->data){
        root->left=insert(root->left,t);
    }

    else if(t>root->data){
        root->right=insert(root->right,t);
    }
    
    return root;
}

Node* deletefromBST(Node* root,int x){
    if(root==NULL){
        return root;
    }

    if(root->data==x){
        //0 child
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }

        //1 child
        //left child
        if(root->left && !root->right){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        //Right child
        if(!root->left && root->right){
            Node* temp=root->right;
            delete root;
            return temp;
        }

        //2 child
        if(root->left && root->right){
            int mini=minval(root->right)->data;
            root->data=mini;
            root->right=deletefromBST(root->right,mini);
            return root;
        }
    }

    else if(root->data>x){
        root->left=deletefromBST(root->left,x);
        return root;
    }

    else{
        root->right=deletefromBST(root->right,x);
        return root;
    }
}
void takeinput(Node* &root){
    int data;
    cout<<"Enter data to be inserted in BST : ";
    cin>>data;

    while(data!=-1){
        root=insert(root,data);
        cin>>data;
    }

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

int main(){
    Node* root=NULL;
    takeinput(root);

    levelordertraversal(root);

    return 1;
}