// https://www.geeksforgeeks.org/problems/burning-tree/1
#include"62_binary_tree.cpp"
class Solution {
    Node* makeNodeToParentMappingAndFindTargetNode(Node* root, unordered_map<Node*, Node*> &parentMap, int target ) {
        // Level Order Traversal
        queue<Node*> q;
        Node* targetNode = 0;
        q.push(root);
        parentMap[root] = 0;
        
        while( !q.empty()) {
            Node* front  = q.front();  q.pop();
            
            if( front->data == target ){
                targetNode = front;
            }
            if( front->left) {
                q.push(front->left);
                parentMap[front->left] = front;   // Node ->  parent Node
            }
            if( front->right) {
                q.push(front->right);
                parentMap[front->right] = front;   // Node ->  parent Node
            }
        }
        return targetNode;
    }
    
    int burnTheTree(Node* targetNode, unordered_map<Node*, Node*> &parentMap) {
        // Map to keep track of burnt node
        unordered_map<Node*, bool> isBurnt;
        // Create a queue to increment the time conditionally
        queue<Node*> q;          // Currently set on fire nodes
        
        int t = 0;
        q.push(targetNode);
        isBurnt[targetNode] = 1;
        
        while( !q.empty()) {
            int size = q.size();
            bool isFireSpreaded = 0;
            
            for( int i=0; i<size; ++i) {
                Node* front = q.front();
                q.pop();
                // Checking if there is any left subtree node to burn
                if( front->left && !isBurnt[front->left] ) {
                    q.push(front->left);
                    isBurnt[front->left] = 1;
                    isFireSpreaded = 1;
                }
                // Checking if there is any right subtree node to burn
                if( front->right && !isBurnt[front->right] ) {
                    q.push(front->right);
                    isBurnt[front->right] = 1;
                    isFireSpreaded = 1;
                }
                // Checking for parent node to burn
                if( parentMap[front] && !isBurnt[parentMap[front]] ) {
                    q.push(parentMap[front]);
                    isBurnt[parentMap[front]] = 1;
                    isFireSpreaded = 1;
                }
            }
            if( isFireSpreaded )
                ++t;
        }
        return t;
    }
  public:
    int minTime(Node* root, int target) {
        // Your code goes here
        unordered_map<Node*, Node*> parentMap;
        
        Node* targetNode = makeNodeToParentMappingAndFindTargetNode(root,parentMap, target);
        
        return burnTheTree(targetNode, parentMap);
    }
};