#include <iostream>
#include <stack>
#include <queue>
using namespace std;
struct Node{
    public:
    int data;
    Node *left, *right;
    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
void inorder(Node *root) {
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void print_ZigZag(Node* root) {
    if(root==NULL) return;
    stack<Node*> curr_stack;
    stack<Node*> next_stack;
    bool l_to_r = true;
    curr_stack.push(root);
    while(!curr_stack.empty()) {
        Node* tmp = curr_stack.top();
        curr_stack.pop();
        cout<<tmp->data<<" ";
        if(l_to_r){
            if(tmp->left!=NULL)
                next_stack.push(tmp->left);
            if(tmp->right!=NULL)
                next_stack.push(tmp->right);
        } else {
            if(tmp->right!=NULL)
                next_stack.push(tmp->right);
            if(tmp->left!=NULL)
                next_stack.push(tmp->left);
        }
        
        if(curr_stack.empty()) {
            l_to_r = !l_to_r;
            swap(curr_stack, next_stack);
        }
    }
    cout<<endl;
}
void pathsRecursive(Node *root, int path[], int size, int *total) {
    if(root==NULL) return;
    path[size++] = root->data;
    if(root->left==NULL && root->right==NULL) {
        for(int i=0; i<size; i++) {
            cout<<path[i]<<" ";
        }
        cout<<size-1<<endl;
        (*total)++;
    } else {
        pathsRecursive(root->left, path, size, total);
        pathsRecursive(root->right, path, size, total);
    }
}
void print_paths(Node *root) {
    int *path = new int;
    int total = 0;
    pathsRecursive(root, path, 0, &total);
    cout<<total<<endl;
}
int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
        //         1
        //     2       3
        //  4     5

    print_ZigZag(root);

    print_paths(root);
    return 0;
}