#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int shortest_path(int V, vector<pair<int, int>>& edges, int start, int end) {
    vector<vector<int>> graph(V);
    for (auto& edge : edges) {
        graph[edge.first].push_back(edge.second);
        graph[edge.second].push_back(edge.first);
    }

    if (start == end) return 0;

    queue<pair<int, int>> q;
    unordered_set<int> visited;
    q.push({start, 0});
    visited.insert(start);

    while (!q.empty()) {
        int node = q.front().first;
        int dist = q.front().second;
        q.pop();

        for (int neighbor : graph[node]) {
            if (neighbor == end) return dist + 1;
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push({neighbor, dist + 1});
            }
        }
    }

    return -1;
}

int main() {
    int V = 5;
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}};
    int start = 0, end = 4;
    cout << shortest_path(V, edges, start, end) << endl;
    return 0;
}
