#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
// creates BST from preorder
Node* BSTfromPreorder_util(int preorder[], int n, int *preorderIdx, int key, int min, int max){
    if(*preorderIdx>=n) return NULL;
    Node* root = NULL;
    if(key>=min &&key<max) {
        root = new Node(key);
        *preorderIdx += 1;
        if(*preorderIdx<n) {
            root->left = BSTfromPreorder_util(preorder, n, preorderIdx, preorder[*preorderIdx], min, key);
        }
        if(*preorderIdx < n) {
            root->right = BSTfromPreorder_util(preorder, n, preorderIdx, preorder[*preorderIdx], key, max);
        }
    }
    return root;
}
// Function for easy input
Node* BSTfromPreorder(int preorder[], int size) {
    int preorderIdx = 0;
    return BSTfromPreorder_util(preorder, size, &preorderIdx, preorder[0], INT_MIN, INT_MAX);
}
// For Checking
void inorder(Node* root) {
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main() {
    int p[6] = {8,5,1,7,10,12};
    Node* root1 = BSTfromPreorder(p, 6);
    inorder(root1);
    return 0;
}