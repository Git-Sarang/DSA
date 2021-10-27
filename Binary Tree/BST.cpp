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
Node* maxValNode(Node* root) {
    Node* curr = root;
    while(curr!=NULL && curr->right!=NULL) curr=curr->right;
    return curr;
}
// Returns the node with the min Value in the BST.
Node* minValNode(Node* root) {
    Node* curr = root;
    while (curr!=NULL && curr->left!=NULL) {
        curr = curr->left;
    }
    return curr;
    
}
Node* deleteNode(Node* root, int key) {

    if(root==NULL) return NULL;
    // Finding key
    else if(key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    // Finding Key
    else if(key < root->data) {
        root->left = deleteNode(root->left, key);
    } else {
        // case 1 and 2
        if(root->left==NULL) {
            Node* tmp = root->right;
            delete root;
            return tmp;
        }
        // case 1 and 2
        else if(root->right==NULL) {
            Node* tmp = root->left;
            delete root;
            return tmp;
        }
        // case 3
        Node* tmp = minValNode(root->right);
        root->data = tmp->data;
        root->right = deleteNode(root->right, tmp->data);
    }
    return root;
}
int main() {
    Node* myRoot = new Node(5);
    insert(myRoot, 3);
    insert(myRoot, 7);
    insert(myRoot, 6);
    insert(myRoot, 1);

    printInorder(myRoot);
    cout<<endl;
    
    deleteNode(myRoot, 1);
    printInorder(myRoot);
    cout<<endl;

    cout<<"Min value of BST: "<<minValNode(myRoot)->data <<endl;
    cout<<"Max value of BST: "<<maxValNode(myRoot)->data <<endl;
    return 0;
}