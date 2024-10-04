#include<iostream>
#include<vector>
using namespace std;

bool isCycle(int node, int parent, vector<vector<int>>& adjList, vector<bool>& visited) {
    visited[node] = true;

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            if (isCycle(neighbor, parent, adjList, visited)) {
                return true;
            }
        } 
        else if (neighbor != parent) {
            return true;
        }
    }
    return false;
}

bool hasCycle(int vertices, vector<vector<int>>& edges) {
    vector<vector<int>> adjList(vertices);
    for (const auto& edge : edges) {
        adjList[edge[0]].push_back(edge[1]);
        adjList[edge[1]].push_back(edge[0]);
    }

    vector<bool> visited(vertices, false);

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            if (isCycle(i, -1, adjList, visited)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int V = 5;
    vector<vector<int>> E = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}};
    cout << "This graph "<<(hasCycle(V, E) ? "contains" : "dont contains")<<" cycle"<<endl;
}