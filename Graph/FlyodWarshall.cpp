#include <iostream>
#include <vector>
#define INF INT_MAX/2
using namespace std;
class Graph{
    public:
    vector<vector<int>> adj;
    int v;
    Graph(vector<vector<int>> l) {
        adj = l;
        v = l.size();
    }
    // Tells the paths with weights of a adj matrix
    void printAdj() {
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++) {
                cout<<i<<" to "<<j<<" path is ";
                if(adj[i][j]>=INF) cout<<"None(INF)"<<endl;
                else cout<<adj[i][j]<<endl;
            }
        }
    }

    void FlyodWarshall(){
        for(int k=0; k<v; k++){
            for(int i=0; i<v; i++){
                for(int j=0; j<v; j++){

                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                
                }
            }
        }

        printAdj();
    }

};
int main() {

    // adj matrix has the weigth of vertix i to vertix j.
    // Zero means no self loop
    // INF means not connected
    vector<vector<int>> adj= {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}
    };

    Graph g(adj);

    g.FlyodWarshall();

    return 0;
}