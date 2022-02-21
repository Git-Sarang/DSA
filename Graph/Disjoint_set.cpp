#include <iostream>
#include <vector>
using namespace std;

vector<int> parent(10, -1);
int find(int vertex) {
    while(parent[vertex] != -1) {
        vertex = parent[vertex];
    }
    return vertex;
}
void union_set(int fromPoint, int toPoint) {
    fromPoint = find(fromPoint);
    toPoint = find(toPoint);
    parent[fromPoint] = toPoint;
}
bool hasCycle(vector<pair<int, int>> &edgeList) {
    ;
    for(auto edge: edgeList) {
        int fromPoint = find(edge.first);
        int toPoint = find(edge.second);
        if(fromPoint == toPoint) {
            return true;
        }
        union_set(fromPoint, toPoint);
    }
    return false;
}

int main() {
    // Keep vertices less than 10
    vector<pair<int, int>> test_edgeList1 = {{0,1}, {1,2}, {2,3}, {3,0}};  //Cyclic
    cout<<hasCycle(test_edgeList1)<<endl;
    parent.clear();
    parent.resize(10, -1);

    vector<pair<int, int>> test_edgeList2 = {{0,1}, {1,2}, {2,3}, {0,0}};  //Cyclic
    cout<<hasCycle(test_edgeList2)<<endl;
    parent.clear();
    parent.resize(10, -1);

    vector<pair<int, int>> test_edgeList3 = {{0,1}, {1,2}, {2,3}, {3,4}};  //Non-Cyclic
    cout<<hasCycle(test_edgeList3)<<endl;
    parent.clear();
    parent.resize(10, -1);

    return 0;
}
