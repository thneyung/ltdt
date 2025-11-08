
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int oo = 100000;
const int maxn = 10001;
vector <pair <int, int >> adj[maxn];
vector <int> dist, truoc;
vector <bool> label;

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
}
    // Hàm truy vết đường đi từ s đến t
    vector<int> truyVet(int s, int t) {
        vector<int> path;
        for (int v = t; v != -1; v = truoc[v])
            path.push_back(v);
        reverse(path.begin(), path.end());
        // Nếu không đi được
        if (path.front() != s) path.clear();
        return path;
    }

    int main() {
        int n, m, s, t, d;
        cin >> n>> m>> s>> t>> d;
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({ v,w });
        }
        dijkstra(s, d, n);
        int dist_1 = dist[d];
        vector<int> path_1 = truyVet(s, d);
        dijkstra(d, t, n);
        int dist_2 = dist[t];
        vector<int> path_2 = truyVet(d,t );

        if (path_1.empty() || path_2.empty()) {
            cout << "Khong co duong di\n";
            return 0;
        }

        int tong = dist_1 + dist_2;

        // Ghép hai đường đi (bỏ trùng x)
        vector<int> full = path_1;
        for (int i = 1; i < path_2.size(); i++)
            full.push_back(path_2[i]);

        // 4️⃣ In kết quả
        cout << full.size() << " " << tong << "\n";
        for (int i = 0; i < full.size(); i++) {
            if (i) cout << " ";
            cout << full[i];
        }
        cout << "\n";
        return 0;

    }