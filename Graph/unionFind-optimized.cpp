#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, int> parent;

int groups = 10;
int find_source(int n) {
    int root = n;
    // Finding the supreme parent
    while(root != parent[root]) {
        root = parent[root];
    }

//  Path compression
    while(n != root) {
        int next = parent[n];
        parent[n] = root;
        n = next;
    }

    return root;
}

void makeUnion(int fromPoint, int toPoint, vector<int> &rank) {
    int a = find_source(fromPoint);
    int b = find_source(toPoint);

    // Rank optimising
    // Rank is just the size of the group
    if(rank[a] > rank[b]) {
        parent[b] = a;
        rank[a] += rank[b];
    } else {
        parent[a] = b;
        rank[b] += rank[a];
    }
}

void addEdge(int a, int b) {
    if(parent.find(b)==parent.end()) parent[b] = b;
    parent[a] = b;
}

int main() {
    for(int i=1; i<=10; i++) addEdge(i, i);
    vector<int> r(11, 0);
    makeUnion(1,2, r);
    makeUnion(3,4, r);
    makeUnion(5,6, r);
    makeUnion(7,8, r);
    makeUnion(9,10, r);
    makeUnion(10,7, r);
    makeUnion(8,6, r);
    makeUnion(1,3, r);
    makeUnion(4,5, r);
    makeUnion(7,2, r);
    makeUnion(9,10, r);

    for(auto x: parent) {
        cout<<x.first<<" "<<x.second<<endl;        
    }
    return 0;
}

// 3lectro-B3ar _[TB1]_ 