#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs(vector<int> graph[], int start, int n) {
    queue<int> q;
    bool visited[n + 1];
    for(int i = 0; i <= n; i++) {
        visited[i] = false;
    }
    visited[start] = true;
    q.push(start);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(int i = 0; i < graph[node].size(); i++) {
            int neighbor = graph[node][i];
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
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
    bfs(graph, 1, n); // Output: 1 2 3 4 5 6 7
    return 0;
}
