#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

class Graph{
    public:
    map<int, bool> visited;
    map<int, vector<int>> adj;

    void addEdge(int v, int point) {
        adj[v].push_back(point);
        visited[v] = false;
        visited[point] = false;
    }
    
    void topologicalSort() {
        stack<int> st;
        for(auto x: adj) {
            if(!visited[x.first])
                topologicalSortUtil(x.first, visited, st);
        }

        while(!st.empty()) {
            cout<<st.top()<<" ";
            st.pop();
        }
    }

    // THIS JUST A DFS
    void topologicalSortUtil(int v, map<int, bool> &visited, stack<int> &st) {
        visited[v] = true;

        for(auto x: adj[v]) {
            if(!visited[x]) topologicalSortUtil(x, visited, st);
        }

        st.push(v);
    }
};

int main() {

    Graph g;
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    
    cout << "Following is a Topological Sort of the given "
            "graph \n";
 
    g.topologicalSort();

    return 0;
}