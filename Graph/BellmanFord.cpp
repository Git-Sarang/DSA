#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Graph{
    public:
    int vertices;
    map<int, vector<pair<int,int>>> adj;
    Graph(int x){
        vertices = x;
    }
    void addEdge(int v, int point, int weight) {
        adj[v].push_back({point, weight});
    }

    void printAdj() {
        for(auto x: adj) {
            int a = x.first;
            for(auto y:x.second){
                cout<<a<<" --"<<y.second<<"--> "<<y.first<<endl;
            }
        }
    }

    void BellmanFord(int src) {
        vector<int> dist(vertices, INT_MAX);
        dist[src] = 0;

        for(int i=0; i<vertices-1; i++) {
            for(auto x: adj) {
                int a = x.first;
                for(auto y: adj[a]) {
                    if(dist[a] + y.second < dist[y.first]) dist[y.first] = dist[a]+y.second;
                }
            }
        }
        // This detects negative cycle
        for(auto x: adj) {
                int a = x.first;
                for(auto y: adj[a]) {
                    if(dist[a] + y.second < dist[y.first]){
                        cout<<"Negative Cycle Detected!"<<endl;
                        return;
                    }
                }
        }
        // Prints the min distances if no negative cycle was found.
        for(int i=0; i<dist.size(); i++) {
            cout<<i<<" has min distance of "<< dist[i] <<" from "<< src <<endl;
        }
    }
};

int main() {

    Graph g(5);
    g.addEdge(0,1,-1);
    g.addEdge(0,2,4);
    g.addEdge(1,2,3);
    g.addEdge(1,3,2);
    g.addEdge(1,4,2);
    g.addEdge(3,2,5);
    g.addEdge(3,1,1);
    g.addEdge(4,3,-3);

    // g.printAdj();
    g.BellmanFord(0);
    return 0;
}