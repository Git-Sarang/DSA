#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
class Graph{
    public:
    int vertices;
    map<int, vector<pair<int, int>>> adj;
    Graph(int v) {
        vertices = v;
    }
    void addEdge(int vert, int point, int weight) {
        adj[vert].push_back({weight, point});

        adj[point].push_back({weight, vert}); //graph is non-directed so both vertices point to each other
    }
    // prints edges of the adj
    void printAdj() {
        for(auto x: adj) {
            int a = x.first;
            for(auto y:x.second){
                cout<<a<<" --"<<y.first<<"--> "<<y.second<<endl;
            }
        }
    }

    void dijstra(int src) {
        vector<int> dist(vertices, INT_MAX);
        vector<bool> visited(vertices, false);
        priority_queue<pair<int,int>> q;
        q.push({0, src});
        dist[src] = 0;

        while(!q.empty()) {
            int curr = q.top().second;
            q.pop();
            if(!visited[curr]){
                visited[curr] = true;
                for(auto x: adj[curr]) {
                    int w = x.first;
                    int p = x.second;
                    dist[p] = min(dist[p], dist[curr]+w);
                    q.push({-dist[p], p});
                }
            }
        }
        // Print the min dist
        for(int i=0; i<dist.size(); i++) {
            cout<< i <<" has min distance of "<<dist[i]<<" from "<< src <<endl;
        }
    }
};
//This Algo is by Taking weight as first and point as second in pair. Also q.push({-dist[p], p}) line44.

int main() {
    Graph g(5);  //TAKES NUMBER OF VERTICES
    g.addEdge(0,1,4);
    g.addEdge(0,2,1);
    g.addEdge(2,1,2);
    g.addEdge(1,3,1);
    g.addEdge(2,3,5);
    g.addEdge(3,4,3);

    // g.printAdj();
    g.dijstra(0);
    return 0;
}