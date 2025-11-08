#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

struct HinhTron {
    double x, y, r;
};

int n, s, t;
vector<vector<pair<int, int>>> adj;
vector<long long> dist;
vector<int> pred, loai;
vector<HinhTron> ds;

double dist_circle(const HinhTron& a, const HinhTron& b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy) - (a.r + b.r);
}

void build_graph() {
    adj.assign(n + 1, {});
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            double d = dist_circle(ds[i], ds[j]);
            if (d <= 50) {
                adj[i].push_back({ j, 0 });
                adj[j].push_back({ i, 0 });
            }
            else if (d <= 60) {
                adj[i].push_back({ j, 1 });
                adj[j].push_back({ i, 1 });
            }
        }
    }
}

void dijkstra() {
    dist.assign(n + 1, LLONG_MAX);
    pred.assign(n + 1, -1);
    loai.assign(n + 1, -1);
    vector<bool> vis(n + 1, false);

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    dist[s] = 0;
    pq.push({ 0, s });

    while (!pq.empty()) {
        int u = pq.top().second; pq.pop();
        if (vis[u]) continue;
        vis[u] = true;

        for (auto e : adj[u]) {
			int v = e.first;
			int c = e.second;

            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                pred[v] = u;
                loai[v] = c;
                pq.push({ dist[v], v });
            }
        }
    }
}

int main() {


    cin >> n >> s >> t;
    ds.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> ds[i].x >> ds[i].y >> ds[i].r;

    build_graph();
    dijkstra();

    if (dist[t] == LLONG_MAX) {
        cout << 0 << "\n";
        return 0;
    }

    vector<int> path, type;
    for (int v = t; v != -1; v = pred[v]) {
        path.push_back(v);
        type.push_back(loai[v]);
    }
    reverse(path.begin(), path.end());
    reverse(type.begin(), type.end());

    cout << 1 << "\n";
    cout << dist[t] - 1 << "\n"; // số bước nhảy (loại 1)
    for (size_t i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
        if (i == 0) cout << 0;
        else cout << type[i];
        cout << "\n";
    }

    return 0;
}