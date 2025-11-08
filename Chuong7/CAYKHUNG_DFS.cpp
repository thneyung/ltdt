#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000;
vector<int> adj[MAXN + 1];
vector<pair<int, int>> tree;
vector<bool> visited;
int n, m;

void DFS(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            tree.push_back({u, v});
            DFS(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Đọc và ghi từ file
    freopen("caykhung.inp", "r", stdin);
    freopen("caykhung.out", "w", stdout);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    visited.assign(n + 1, false);
    DFS(1);

    cout << tree.size() << "\n";
    for (auto &e : tree) {
        cout << e.first << " " << e.second << "\n";
    }

    return 0;
}