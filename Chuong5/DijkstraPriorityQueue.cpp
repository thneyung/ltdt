
#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;
const int maxn = 10000;
int oo = 100000;
vector <int> dist, parent;
vector<pair<int, int >> adj[maxn];
vector<bool> label;

int n, m, s, t;
void DijkstraPriorityQueue(int n,int s, int t) {
    dist.assign(n + 1, oo);
    label.assign(n + 1, false);
    parent.assign(n + 1, -1);

    priority_queue<pair<int, int >, vector<pair<int, int >>, greater<pair<int, int>>> q;

    dist[s] = 0;
    q.push({ 0,s });

    while (!q.empty()) {
        int u = q.top().second;
        int du = q.top().first;
        q.pop();

        if (label[u]) continue;
        label[u] = true;

        for (auto e : adj[u]) {
            int v = e.first;
            int w = e.second;
            if (!label[v] && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;
               q.push({ dist[v],v });
            }
        }
    }

    //truy vet duong di tu s->t

    vector <int >path;
    for (int v = t; v != -1; v = parent[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    
    cout << path.size() << " " << dist[t] << "\n";
    for (int i = 0; i < path.size(); i++) {
        if (i) cout << " ";
        cout << path[i];
    }
    cout << "\n";
}

int main()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >>u>> v>> w;
        adj[u].push_back({ v,w });
    }
    DijkstraPriorityQueue(n, s, t);
    return 0;
}

