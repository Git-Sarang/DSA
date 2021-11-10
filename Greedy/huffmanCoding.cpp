#include <iostream>
#include <queue>
using namespace std;
struct Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        left=NULL;
        right=NULL;
    }
};
void preorder(Node* root, vector<string> &res, string st) {
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL) res.push_back(st);
    preorder(root->left, res, st+"0");
    preorder(root->right, res, st+"1");
}
struct compare {
    bool operator()(Node* a, Node* b) {
       return (a->data > b->data);
    }
};
vector<string> huffmanCodes(string s,vector<int> v,int n) {
	priority_queue<Node*, vector<Node*>, compare> q;
	for(int i=0; i<n; i++) q.push(new Node(v[i]));
		    
	while(q.size()!=1) {
	    Node* leftNode = q.top();
	    q.pop();
	    Node* rightNode = q.top();
	    q.pop();
	    Node* parent = new Node(leftNode->data + rightNode->data);
	    parent->left = leftNode;
	    parent->right = rightNode;
	    q.push(parent);
	}
	Node* root = q.top();
	q.pop();
	vector<string> res;
	preorder(root, res, "");
	return res;
}
int main() {
    vector<string> huffman;
    vector<int> frequency = {5, 9, 12, 13, 16, 45};
    huffman = huffmanCodes("abcdef", frequency, frequency.size());

    for(auto x: huffman) {
        cout<<x<<endl;
    }
    return 0;
}