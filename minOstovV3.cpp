#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int to;
    int weight;

    Edge(int to, int weight) : to(to), weight(weight) {

    }

    Edge() {
        this->weight = 0;
        this->to = 0;
    }

    bool operator < (Edge e) const {
        return weight < e.weight;
    }
};

int main() {

    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> edges(m);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        edges[u].emplace_back(v, w);
        edges[v].emplace_back(u, w);
    }

    const int INF = 1e9;
    int result = 0;

    vector<int> dist(n, INF);
    vector<bool> used(n, 0);
    dist[0] = 0;

    for (int i = 0; i < n; ++i) {
        int v = -1;
        for (int u = 0; u < n; ++u) {
            if (!used[u] && (v == -1 || dist[u] < dist[v])) {
                v = u;
            }
        }
        if (v == -1) {
            break;
        }
        used[v] = true;
        result += dist[v];

        for (auto &e : edges[v]) {
            if (dist[e.to] > e.weight) {
                dist[e.to] = e.weight;
            }
        }
    }

    cout << result << endl;
    return 0;
}
