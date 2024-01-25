// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/?envType=daily-question&envId=2024-01-25
#include"62_binary_tree.cpp"
class Solution {
private:
    int result;
    vector<int> digit;

    bool isPalindrome() {
        int odd = 0;
        for (int i = 1; i <= 9; i++) {
            if (digit[i] % 2 != 0) {
                odd++;
            }
        }

        return (odd <= 1);
    }

    void dfs(Node* root) {
        if (root == nullptr) {
            return;
        }

        digit[root->data]++;

        if (root->left == nullptr && root->right == nullptr) {
            if (isPalindrome()) {
                result++;
            }
        } else {
            dfs(root->left);
            dfs(root->right);
        }

        digit[root->data]--;
    }

    public:
    int pseudoPalindromicPaths(Node* root) {
        result = 0;
        digit.resize(10, 0);
        dfs(root);
        return result;
    }

};