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