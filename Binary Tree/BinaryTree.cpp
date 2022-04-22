#include <iostream>
#include<queue>
using namespace std;
int diff(int a, int b) {
    if(a>b) return a-b;
    return b-a;
}

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

int search(int inorder[], int start, int end, int curr) {
    for(int i=start; i<=end; i++) {
        if(inorder[i] == curr) return i;
    }
    return -1;
}

// Builds the tree from PreOrder array, requires Inorder array too
Node* buildTree_preorder(int *preorder, int *inorder, int start, int end) {
    if(start > end) return NULL;

    static int i = start;
    int curr = preorder[i];
    i++;
    Node *node = new Node(curr);
    if(start == end){
        return node;
    }
    int pos = search(inorder, start, end, curr);
    node->left = buildTree_preorder(preorder, inorder, start, pos-1);
    node->right = buildTree_preorder(preorder, inorder, pos+1, end);
    return node;
     
}

Node* buildTree_postorder(int postorder[], int inorder[], int start, int end){
    if(start>end) return NULL;
    static int i=end;
    int val = postorder[i];
    i--;

    Node* curr = new Node(val);
    if(start==end) return curr;

    int pos = search(inorder, start, end, val);
    curr->right = buildTree_postorder(postorder, inorder, pos+1, end);
    curr->left = buildTree_postorder(postorder, inorder, start, pos-1);

    return curr;
}

// Prints the tree Level by Level starting from Level 0(aka root node)
void print_levelOrder(Node* root) {
    if(root==NULL) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* tmp = q.front();
        q.pop();
        if(tmp!=NULL) {
            cout<<tmp->data<<" ";
            if(tmp->left != NULL)
                q.push(tmp->left);
            if(tmp->right != NULL)
                q.push(tmp->right);
        } else if(!q.empty()) {
            cout<<endl;
            q.push(NULL);
        }
    }
}
// Returns the Sum of Nodes at (K)th Level of the Tree
int sumAt_K(Node* root, int k) {
    if(root==NULL) return -1;
    queue<Node*> q;
    int level =0, sum=0;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()) {
        Node* tmp = q.front();
        q.pop();

        if(tmp!=NULL) {
            if(level==k)
                sum += tmp->data;
            if(tmp->left != NULL)
                q.push(tmp->left);
            if(tmp->right != NULL)
                q.push(tmp->right);
        } else if(!q.empty()) {
            level++;
            q.push(NULL);
        }
    }
    return sum;
}

int countNodes(Node* root) {
    if(root==NULL) return 0;
    return countNodes(root->left) + countNodes(root->right) +1;
}
int sumNodes(Node* root) {
    if(root==NULL) return 0;
    return sumNodes(root->left) + sumNodes(root->right) + root->data;
}

int height(Node* root) {
    if(root==NULL) return 0;
    int left_height = height(root->left);
    int right_height = height(root->right);
    return max(left_height, right_height) + 1;   //We do +1 to include the current node
}

// Calculates size of Diameter. Diameter is the longest possible path in a tree.
int cal_diameter(Node* root) {
    if(root==NULL) return 0;
    int left_h = height(root->left);
    int right_h = height(root->right);
    int total = left_h + right_h +1;  //We do +1 to include the current node

    int lDiameter = cal_diameter(root->left);
    int rDiameter = cal_diameter(root->right);

    return max(total, max(lDiameter, rDiameter));
}

// Checks if the tree is balanced. If the difference of Left and Right child nodes is <= 1, then
// the tree IS BALANCED
bool isBalanced(Node* root) {
    if(root==NULL) return true;
    if(isBalanced(root->left)==false) return false;
    if(isBalanced(root->right)==false) return false;
    
    int lh = height(root->left);
    int rh = height(root->right);
    if(diff(lh, rh)<=1) {
        return true;
    }
    return false;

}

// Adds all the children nodes to the parent node. Leaf nodes remain the same as they have 
// no children. So every node = node +left children + right children
void sumReplace(Node* root) {
    if(root==NULL) return;
    sumReplace(root->left);
    sumReplace(root->right);

    if(root->left != NULL) {
        root->data += root->left->data;
    }
    if(root->right != NULL) {
        root->data += root->right->data;
    }
}

void rightView(Node* root) {
    if(root==NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int n = q.size();
        for(int i=0; i<n; i++) {
            Node* curr = q.front();
            q.pop();
            if(i == n-1) {
                cout<<curr->data<<" ";
            }
            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }
        }
    }
    cout<<endl;
}
void leftView(Node* root) {
    if(root==NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int n = q.size();
        for(int i=0; i<n; i++) {
            Node* curr = q.front();
            q.pop();
            if(i==0){
                cout<<curr->data<<" ";
            }
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
    }
    cout<<endl;
}

/* The below 3 functions are used to find the Distance between 2 Nodes in BT*/
// This finds Least Common Ancester of 2 Nodes
Node* LCA(Node* root, int n1, int n2) {
    if(root==NULL) return NULL;
    if(root->data==n1 || root->data==n2) return root;

    Node* left = LCA(root->left, n1, n2);
    Node* right = LCA(root->right, n1, n2);

    if(left!=NULL && right!=NULL) {
        return root;
    }

    if(left!=NULL) return left;
    return right;
}
// Finds the distance from a Node to a data element
int findDist(Node* root, int k, int dist) {
    if(root==NULL) return -1;
    if(root->data == k) return dist;

    int left = findDist(root->left, k, dist+1);
    int right = findDist(root->right, k, dist+1);
    if(left!=-1) return left;
    return right;
}
// Finds the Distance between two Nodes (by providing their data elements)
int dist_btw2Nodes(Node* root, int n1, int n2) {
    Node* lca = LCA(root, n1, n2);
    int d1 = findDist(lca, n1, 0);
    int d2 = findDist(lca, n2, 0);
    return d1 + d2;
}

void print_preorder(Node* root) {
    if(root==NULL) return;
    cout<<root->data<<endl;
    print_preorder(root->left);
    print_preorder(root->right);
}
void print_inorder(Node* root) {
    if(root==NULL) return;
    print_inorder(root->left);
    cout<<root->data<<endl;
    print_inorder(root->right);
}
void print_postorder(Node* root) {
    if(root==NULL) return;
    print_postorder(root->left);
    print_postorder(root->right);
    cout<<root->data<<endl;
}

int main() {
    int preorder[] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[] = {4, 2, 5, 1, 6, 3, 7};
    int postorder[] = {4, 5, 2, 6, 7, 3, 1};

    // Build Tree
    // Node *myRoot = buildTree_preorder(preorder, inorder, 0, 6);
    Node *myRoot = buildTree_postorder(postorder, inorder, 0, 6);
    print_preorder(myRoot);

    cout<<"Level Order is:\n";
    print_levelOrder(myRoot);
    cout<<endl;

    cout<<"Height of Tree is:  "<< height(myRoot) <<endl;

    cout<<"Sum at level 2 is:  "<< sumAt_K(myRoot, 2) <<endl;

    cout<<"Number of Nodes are:  "<< countNodes(myRoot) <<endl;

    cout<<"Sum of all Nodes is:  "<< sumNodes(myRoot) <<endl;

    cout<<"Diameter of Tree is:  "<< cal_diameter(myRoot)  <<endl;

    cout<<"After calling the sumReplace() function, tree is:\n";
    sumReplace(myRoot);
    print_levelOrder(myRoot);
    cout<<endl;

    // To again make the tree as in the begining 
    //       1
    //     2     3
    //   4  5   6  7
    myRoot = buildTree_preorder(preorder, inorder, 0, 6);
    
    cout<<"Is the balanced?  "<< isBalanced(myRoot) <<endl;

    cout<<"Right View:  ";
    rightView(myRoot);

    cout<<"Left View:  ";
    leftView(myRoot);

    cout<<"Distance between 4 and 7 is "<< dist_btw2Nodes(myRoot, 4, 7) <<endl;

    
    return 0;
}