#include <iostream>
#include <vector>
#include <unordered_map>
#define vi vector<int>
using namespace std;
unordered_map<int, int> in_index;
class TreeNode{
    public:
    int data;
    TreeNode *left = NULL;
    TreeNode *right = NULL;
    
    TreeNode(int data) {
        this->data = data;
        TreeNode *left = NULL;
        TreeNode *right = NULL;
    }
};
TreeNode* buildTree(vi &in, vi &pre, int start, int end, int &i) {
    if(start > end) return NULL;
    int curr = pre[i];
    i++;
    TreeNode *node = new TreeNode(curr);
    if(start==end) return node;
    int pos = in_index[curr];
    node->left = buildTree(in, pre, start, pos-1, i);
    node->right = buildTree(in, pre, pos+1, end, i);
    return node;
}

void printPreorder(TreeNode *root) {
    if(root==NULL) return;
    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    // inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> preorder = {9, 15, 7, 20, 3};
    int n = inorder.size();
    for(int i=0; i<n; i++) in_index[inorder[i]] = i;
    int i=0;

    TreeNode *myTree = buildTree(inorder, preorder, 0, n-1, i);

    printPreorder(myTree);

    return 0;
}