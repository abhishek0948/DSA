// https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1
#include"62_binary_tree.cpp"
class Solution{
    public:
    vector <int> zigZagTraversal(Node* root)
    {
    	vector<int> ans;
    	if(!root) return ans;
    	
    	queue<Node*> q;
    	q.push(root);
    	bool lefttoright=true;
    	
    	while(!q.empty()){
    	    int size=q.size();
    	    vector<int> temp(size);
    	    //level process
    	    for(int i=0;i<size;i++){
    	        Node* frontnode=q.front();
    	        q.pop();
    	        
    	        //Normal insert or reverse insert
    	        int index = lefttoright ? i : size - i - 1;
    	        temp[index] = frontnode->data;
    	        
    	        if(frontnode->left) q.push(frontnode->left);
    	        if(frontnode->right) q.push(frontnode->right);
    	        
    	    }
    	    
    	    //Direction change
    	    lefttoright=!lefttoright;
    	    for(auto i:temp){
    	        ans.push_back(i);
    	    }
    	}
    	return ans;
    }
};