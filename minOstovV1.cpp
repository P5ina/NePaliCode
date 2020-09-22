#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int from;
    int to;
    int weight;

    Edge(int from, int to, int weight) : from(from), to(to), weight(weight) {

    }

    Edge() {
        this->weight = 0;
        this->to = 0;
        this->from = 0;
    }

    bool operator < (Edge e) const {
        return weight < e.weight;
    }
};

struct dsu {
    vector<vector<int>> graph;
    vector<bool> used;

    void addEdge(int from, int to, int color, bool isTwoSided = false) {
        graph[from].push_back(to);

        if (isTwoSided) {
            graph[to].push_back(from);
        }
    }

    void union_(int u, int v) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bool check(int u, int v) {
        used.assign(graph.size(), 0);
        dfs(u);
        return used[v];
    }

    void dfs(int v) {
        used[v] = true;
        for (auto &u : graph[v]) {
            if (!used[u]) {
                dfs(u);
            }
        }
    }

    explicit dsu(int size) {
        graph.resize(size);
    }

    dsu() = default;
};

int main() {

    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);

    for (auto &e : edges) {
        cin >> e.from >> e.to >> e.weight;
        --e.from;
        --e.to;
    }

    sort(edges.begin(), edges.end());

    int result = 0;

    dsu g(n);

    for (auto &e : edges) {
        if (!g.check(e.from, e.to)) {
            g.union_(e.from, e.to);
            result += e.weight;
        }
    }

    cout << result << endl;
    return 0;
}
