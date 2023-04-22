#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class UnionFind {
    vector<int> parent, rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

struct Edge {
    int u, v, weight;
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

vector<Edge> kruskal(vector<Edge>& edges, int n) {
    vector<Edge> result;
    UnionFind uf(n);

    sort(edges.begin(), edges.end(), compareEdges);

    for (auto& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int weight = edge.weight;
        if (uf.find(u) != uf.find(v)) {
            uf.merge(u, v);
            result.push_back(edge);
        }
    }

    return result;
}

int main() {
    int n = 5;
    vector<Edge> edges = {{0, 1, 2}, {0, 4, 4}, {1, 2, 3}, {2, 3, 6}, {3, 4, 1}, {1, 4, 4}, {3, 1, 1}};
    vector<Edge> result = kruskal(edges, n);

    for (auto& edge : result) {
        cout << edge.u << " - " << edge.v << " : " << edge.weight << endl;
    }

    return 0;
}
