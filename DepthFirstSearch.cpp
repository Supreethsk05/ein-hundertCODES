#include <iostream>
#include <vector>

using namespace std;

void dfsHelper(vector<int> graph[], bool visited[], int node) {
    visited[node] = true;
    cout << node << " ";
    for(int i = 0; i < graph[node].size(); i++) {
        int neighbor = graph[node][i];
        if(!visited[neighbor]) {
            dfsHelper(graph, visited, neighbor);
        }
    }
}

void dfs(vector<int> graph[], int start, int n) {
    bool visited[n + 1];
    for(int i = 0; i <= n; i++) {
        visited[i] = false;
    }
    dfsHelper(graph, visited, start);
}

int main() {
    int n = 7;
    vector<int> graph[n + 1];
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(4);
    graph[2].push_back(5);
    graph[3].push_back(5);
    graph[4].push_back(6);
    graph[5].push_back(6);
    graph[6].push_back(7);
    dfs(graph, 1, n); // Output: 1 2 4 6 7 5 3
    return 0;
}
