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
// Prints All the paths to nodes in a BT
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
// Prints all the paths to leaf nodes in a BT
void print_paths(Node *root) {
    int *path = new int;
    int total = 0;
    pathsRecursive(root, path, 0, &total);
    cout<<total<<endl;
}
// Gets Sum of all the nodes
int getSum(Node *root) {
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL) return root->data;
    return(root->data + getSum(root->left) + getSum(root->right));
}

Node* lca(Node *root, int a, int b) {
    if(root==NULL) return NULL;
    if(root->data==a || root->data==b) return root;
    Node* l = lca(root->left, a, b);
    Node* r = lca(root->right, a, b);
    if(l==NULL) return r;
    if(r==NULL) return l;
    return root;
}
// Builds a Complete tree from an Array in Level order.
Node* buildLevelOrder(int arr[], int size, Node* root, int i) {
    if(i<size) {
        Node *tmp = new Node(arr[i]);
        root = tmp;
        root->left = buildLevelOrder(arr, size, root->left, 2*i+1);
        root->right = buildLevelOrder(arr, size, root->right, 2*i+2);
    }
    return root;
}
// Converts a BT to DLL(Using the same Tree Node)
void tree_to_DLL(Node* root, Node* &head, Node* &prev) {
    if(root==NULL) return;
    tree_to_DLL(root->left, head, prev);
    if(prev==NULL) {
        head=root;
        prev=root;
    } else {
        root->left = prev;
        prev->right = root;
        prev = root;
    }
    tree_to_DLL(root->right, head, prev);
}
// This is to print a DLL of type Node(Tree). Made to check 'tree_to_DLL()'.
void printDLL(Node *head) {
    Node* tmp = head;
    while(tmp!=NULL) {
        cout<<tmp->data<<" ";
        tmp = tmp->right;
    }
    cout<<endl;
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

    //Converting BT to DLL and storing it's head in DLLhead.
    Node *DLLhead = NULL;
    Node *DLLprev = NULL;
    tree_to_DLL(root, DLLhead, DLLprev);
    cout<<"This is a DLL-> ";
    printDLL(DLLhead);

    
    
    return 0;
}