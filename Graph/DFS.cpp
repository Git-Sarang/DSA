#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Graph {
    public:
    map<int, bool> visited;
    map<int, vector<int>> vert;

    void addEdge(int v, int point) {
        vert[v].push_back(point);
    }

    void DFS(int v) {
        cout<<v<<" ";
        visited[v] = true;
//      This is iteration of the "vector" in the "vert" map without using "auto"
        // vector<int>:: iterator i;
        // for(i = vert[v].begin(); i != vert[v].end(); i++) {
        //     if(!visited[*i]) {
        //         DFS(*i);
        //     }
        // }
        for(auto x: vert[v]) {
            if(!visited[x]) DFS(x);
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
    
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.DFS(2);
    return 0;
}