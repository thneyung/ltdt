#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 1000;
vector<int> adj[MAXN + 1];
vector<pair<int, int>> tree;
vector<bool> visited;
int n, m;

void BFS(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                tree.push_back({u, v}); // thêm cạnh vào cây khung
                q.push(v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Đọc/ghi file theo đề bài
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
    BFS(1); // Bắt đầu từ đỉnh 1

    cout << tree.size() << "\n";
    for (auto &e : tree)
        cout << e.first << " " << e.second << "\n";

    return 0;
}
