#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>

using namespace std;
struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
void print_inorder(TreeNode *root) {
    stack<TreeNode*> s;
    TreeNode *curr = root;
    while(curr!=NULL || !s.empty()) {
        if(curr!=NULL) {
            s.push(curr);
            curr = curr->left;
        } else {
            curr = s.top();
            s.pop();
            cout<<curr->data<<" ";
            curr = curr->right;
        }
        
    }
    cout<<endl;
}
void print_preorder(TreeNode *root) {
    if(root==NULL) return;
    stack<TreeNode*> s;
    TreeNode *curr = root;
    while(curr!=NULL || !s.empty()) {
        if(curr!=NULL) {
            s.push(curr);
            cout<<curr->data<<" ";
            curr = curr->left;
        } else {
            curr = s.top();
            s.pop();
            curr = curr->right;
        }
    }
    cout<<endl;
}
void print_postorder(TreeNode *root) {
    if(root==NULL) return;
    stack<TreeNode*> s1, s2;
    TreeNode *curr = root;
    s1.push(curr);
    while(!s1.empty()) {
        curr = s1.top();
        s2.push(s1.top());
        s1.pop();
        if(curr->left != NULL) {
            s1.push(curr->left);
        }
        if(curr->right != NULL) {
            s1.push(curr->right);
        }
    }
    while(!s2.empty()){
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
    cout<<endl;
}

vector<int> topView(TreeNode *root) {
    map<int, int> m;
    queue<pair<TreeNode*, int>> q;
    vector<int> res;
    if(root==NULL) return res;
    q.push({root, 0});
    while(!q.empty()) {
        pair<TreeNode*, int> curr = q.front();
        q.pop();
        if(m.find(curr.second)==m.end()) {
            m[curr.second] = curr.first->data;
        }
        if(curr.first->left != NULL)
            q.push({curr.first->left, curr.second-1});
        if(curr.first->right !=NULL)
            q.push({curr.first->right, curr.second+1});
    }
    map<int, int>::iterator it = m.begin();
    while(it != m.end()) {
        res.push_back(it->second);
        it++;
    }
    return res;
}

void print_bottomView(TreeNode *root) {
    map<int, int> m;
    queue<pair<TreeNode*, int>> q;
    if(root==NULL) return;
    q.push({root, 0});
    while(!q.empty()) {
        pair<TreeNode*, int> curr = q.front();
        q.pop();
        m[curr.second] = curr.first->data;
        if(curr.first->left != NULL)
            q.push({curr.first->left, curr.second-1});
        if(curr.first->right != NULL)
            q.push({curr.first->right, curr.second+1});
    }
    map<int, int>::iterator it = m.begin();
    while(it != m.end()) {
        cout<<it->second<<" ";
        it++;
    }
    cout<<endl;  
}
int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
        //         1
        //     2       3
        //  4     5
    print_inorder(root);
    print_preorder(root);
    print_postorder(root);

    vector<int> top_view = topView(root);
    for(auto x: top_view) cout<<x<<" ";
    cout<<endl;

    print_bottomView(root);

    return 0;
}