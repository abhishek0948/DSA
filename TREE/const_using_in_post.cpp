// https://www.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1
#include"62_binary_tree.cpp"
// TC : O(n^2) , if map is used then TC becomes O(nlogn)
int Findposition(int in[], int inorderStart, int inorderEnd, int element, int n)
{
    for (int i = inorderStart; i <= inorderEnd; i++)
    {
        if (in[i] == element)
        {
            return i;
        }
    }
    return -1;
}
Node *solve(int in[], int post[], int &index, int inorderStart, int inorderEnd, int n)
{
    if (index < 0 || inorderStart > inorderEnd)
    {
        return NULL;
    }

    int element = post[index--]; // At every interation index is increasing
    Node *root = new Node(element);
    int position = Findposition(in, inorderStart, inorderEnd, element, n);

    root->right = solve(in, post, index, position + 1, inorderEnd, n);
    root->left = solve(in, post, index, inorderStart, position - 1, n);

    return root;
}
Node *buildTree(int in[], int post[], int n)
{
    int postorderindex = n - 1; // Pre order is NLR so First element is root .

    Node *ans = solve(in, post, postorderindex, 0, n - 1, n);
    return ans;
}