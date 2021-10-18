#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int x){
        data = x;
        left=NULL;
        right=NULL;
    }
};

Node* insert(Node* root, int val) {
    if(root==NULL) {
        return new Node(val);
    }
    if(val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

Node* search(Node* root, int val) {
    if(root==NULL) return NULL;
    
    if(root->data==val) return root;
    if(val < root->data) {
        return search(root->left, val);
    }
    return search(root->right, val);
}

void printInorder(Node* root) {
    if(root==NULL) return;
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}
int main() {
    Node* myRoot = new Node(5);
    insert(myRoot, 3);
    insert(myRoot, 7);
    insert(myRoot, 6);

    
    return 0;
}