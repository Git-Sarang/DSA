#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;
class Graph{
    public:
    int vertices;
    unordered_map<int, vector<pair<int, int>>> adj;
    Graph(int v) {
        vertices = v;
    }
    void addEdge(int vert, int weight, int point) {
        adj[vert].push_back({weight, point});
    }

    int prims_MST(Graph g) {
        vector<bool> visited(g.vertices, false);
        visited[0] = true;
        int curr_vert = 0;
        multiset<pair<int, int>> q;
        for(int i=0; i<vertices-1; i++) {
            for(auto x: g.adj[curr_vert]) {
                q.insert({x.first, x.second});
            }
            
        }
    }
};

int main() {
    // 21
    Graph g(6);
    g.addEdge(0, 6, 3);
    g.addEdge(3, 6, 5);
    g.addEdge(3, 3, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 3, 4);
    g.addEdge(4, 3, 3);
    return 0;
}