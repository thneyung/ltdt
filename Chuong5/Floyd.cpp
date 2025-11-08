
#include <iostream>
#include <vector>
using namespace std;

const int oo = 1e9;
const int maxn = 1000;

int n, m;
vector<vector<int>> dist;

void floyd(int n) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

int main() {
    cin >> n >> m;

    dist.assign(n + 1, vector<int>(n + 1, oo));

    // Đường chéo chính = 0
    for (int i = 1; i <= n; i++)
        dist[i][i] = 0;

    // Nhập cạnh (vô hướng)
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (w < dist[u][v]) {
            dist[u][v] = w;
            dist[v][u] = w;
        }
    }

    floyd(n);

    // In kết quả
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == oo) cout << 0 << " ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

