#include <iostream>
#include <map>
#include <vector>
#define NIL -1
using namespace std;

class Graph{
    public:
        int V;
        map<int, vector<int>> adj;
        Graph(int vertices) {
            V = vertices;
        }
        void addEdge(int v, int point, bool bidir=true) {
            adj[v].push_back(point);
            if(bidir)
                adj[point].push_back(v);
        }

        void bridge() {
            bool *visited = new bool[V];
            int *ids = new int[V];
            int *lows = new int[V];
            int *parent = new int[V];
            for(int i=0; i<V; i++){
                visited[i] = false;
                parent[i] = NIL;
            }
            for(int i=0; i<V; i++) {
                if(!visited[i])
                    bridgeUtilDFS(i, visited, ids, lows, parent);
            }
        }

        void bridgeUtilDFS(int i, bool visited[], int ids[], int lows[], int parent[]) {
            static int id = 0;
            visited[i] = true;
            ids[i] = lows[i] = ++id;

            for(auto x: adj[i]) {
                if(!visited[x]) {
                    parent[x] = i;
                    bridgeUtilDFS(x, visited, ids, lows, parent);

                    lows[i] = min(lows[i], lows[x]);

                    if(ids[i] < lows[x]) {
                        cout<< i <<" ---- "<< x <<endl;
                    }

                }
                else if(x != parent[i]){
                    lows[i] = min(lows[i], ids[x]);
                }
            }
        }
};

int main() {

    Graph g1(9);
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(2, 0);
    g1.addEdge(2, 3);
    g1.addEdge(2, 5);
    g1.addEdge(3, 4);
    g1.addEdge(5, 6);
    g1.addEdge(6, 7);
    g1.addEdge(8, 5);
    g1.addEdge(8, 7);
    g1.bridge();
    /* 
    Ans should be the following edges for the given graph g1
    3---4
    2---3
    2---5
    */
    return 0;
}