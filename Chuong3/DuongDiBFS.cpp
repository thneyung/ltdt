#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> adj[1000];
bool visited[1000];
int parent[1000];

void BFS(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, y;
    cin >> n >> x >> y;

    // Nhập danh sách kề
    for (int i = 1; i <= n; i++) {
        int v;
        while (cin >> v && v != -1) {
            adj[i].push_back(v);
        }
    }

    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));

    // BFS từ x
    BFS(x);

    if (!visited[y]) {
        cout << "0\n"; // không có đường đi
        return 0;
    }

    // Truy vết đường đi từ y -> x
    vector<int> path;
    for (int cur = y; cur != -1; cur = parent[cur]) {
        path.push_back(cur);
        if (cur == x) break;
    }
    reverse(path.begin(), path.end());

    // Xuất kết quả
    cout << path.size() << "\n";
    for (int v : path) cout << v << " ";
    cout << "\n";

    return 0;
}
