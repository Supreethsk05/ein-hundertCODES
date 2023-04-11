#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1e9;

void dijkstra(vector<pair<int, int>> graph[], int start, int n) {
    int dist[n + 1];
    for(int i = 0; i <= n; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));
    while(!pq.empty()) {
        pair<int, int> front = pq.top();
        pq.pop();
        int u = front.second;
        int d = front.first;
        if(d > dist[u]) {
            continue;
        }
        for(int i = 0; i < graph[u].size(); i++) {
            pair<int, int> v = graph[u][i];
            if(dist[u] + v.second < dist[v.first]) {
                dist[v.first] = dist[u] + v.second;
                pq.push(make_pair(dist[v.first], v.first));
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
}

int main() {
    int n = 6;
    vector<pair<int, int>> graph[n + 1];
    graph[1].push_back(make_pair(2, 3));
    graph[1].push_back(make_pair(3, 4));
    graph[1].push_back(make_pair(4, 2));
    graph[2].push_back(make_pair(4, 1));
    graph[2].push_back(make_pair(5, 2));
    graph[3].push_back(make_pair(4, 3));
    graph[3].push_back(make_pair(6, 5));
    graph[4].push_back(make_pair(5, 3));
    graph[5].push_back(make_pair(6, 2));
    dijkstra(graph, 1, n); // Output: 0 3 4 2 4 6
    return 0;
}
