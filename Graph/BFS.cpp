#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;

class Graph{
    public:
    map<int, vector<int>> vert;
    map<int, bool> visited;

    void addEdge(int v, int point) {
        vert[v].push_back(point);
    }
    // Main function
    
    void BFS(int v) {
        queue<int> q;
        q.push(v);
        visited[v] = true;

        while(!q.empty()) {
            v = q.front();
            cout<<v<<" ";
            q.pop();
            for(auto x: vert[v]) {
                if(!visited[x]) {
                    q.push(x);
                    visited[x] = true;
                }
            }
        }
    }
};

int main() {
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    
    cout << "Following is Breadth First Traversal"
            " (starting from vertex 2) \n";
    g.BFS(2);
    return 0;
}