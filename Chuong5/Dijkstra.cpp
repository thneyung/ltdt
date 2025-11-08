

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int oo = 1e9;
const int maxn = 100001;
vector<pair<int, int>> adj[maxn];
vector<int> dist, truoc;
vector<bool> label;

void dijkstra(int s, int t, int n) {
    dist.assign(n + 1, oo);
    label.assign(n + 1, false);
    truoc.assign(n + 1, -1);

    dist[s] = 0;

    for (int k = 1; k <= n; k++) {
        int u = -1;
        int mindist = oo;
        for (int v = 1; v <= n; v++)
            if (!label[v] && dist[v] < mindist) {
                mindist = dist[v];
                u = v;
            }
        if (u == -1) break;
        label[u] = true;

        for (auto e : adj[u]) {
            int v = e.first;
            int w = e.second;
            if (!label[v] && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                truoc[v] = u;
            }
        }
    }

    // Truy vết đường đi
    vector<int> path;
    for (int v = t; v != -1; v = truoc[v])
        path.push_back(v);
    reverse(path.begin(), path.end());

    cout << path.size() << " " << dist[t] << "\n";
    for (int i = 0; i < path.size(); i++) {
        if (i) cout << " ";
        cout << path[i];
    }
    cout << "\n";
}

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
  
    }

    dijkstra(s, t, n);
    return 0;
}
