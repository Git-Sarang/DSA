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

    int prims_MST() {
        vector<bool> visited(vertices, false);
        visited[0] = true;
        int curr_vert = 0, ans = 0;
        multiset<pair<int, int>> q;
        for(int i=0; i<vertices-1; i++) {
            for(auto x: adj[curr_vert]) {
                if(visited[x.second] == false)
                    q.insert({x.first, x.second});
            }
            pair<int, int> selected = *(q.begin());
            while(!q.empty() && visited[selected.second]==true) {
                q.erase(q.begin());
                selected = *(q.begin());
            }
            q.erase(q.begin());
            visited[selected.second] = true;
            curr_vert = selected.second;
            ans += selected.first;
        }
        return ans;
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
    // MST: 21
    cout<<g.prims_MST()<<endl;
    
    Graph g2(3);
    g2.addEdge(0, 5, 1);
    g2.addEdge(0, 1, 2);
    g2.addEdge(1, 3, 2);
    // MST: 4
    cout<<g2.prims_MST()<<endl;
    return 0;
}