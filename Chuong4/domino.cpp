#include <iostream>
#include <vector>
using namespace std;

int n;
int deg[10];           
int adj[10][10];       // ma trận kề (số cạnh giữa 2 đỉnh)
vector<pair<int, int>> path;  // lưu kết quả chu trình

// DFS để kiểm tra liên thông
void dfs(int u, bool visited[]) {
    visited[u] = true;
    for (int v = 0; v <= n; v++) {
        if (adj[u][v] > 0 && !visited[v]) {
            dfs(v, visited);
        }
    }
}


void euler(int u) {
    for (int v = 0; v <= n; v++) {
        while (adj[u][v] > 0) {
            adj[u][v]--;
            adj[v][u]--;
            euler(v);
            path.push_back({ u, v });
        }
    }
}

int main() {
    cin >> n;
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        adj[x][y]++;
        adj[y][x]++;
        deg[x]++;
        deg[y]++;
    }

    // tìm 1 đỉnh có bậc > 0 để bắt đầu kiểm tra liên thông
    int start = -1;
    for (int i = 0; i <= 6; i++)
        if (deg[i] > 0) {
            start = i;
            break;
        }

    // kiểm tra liên thông
    bool visited[10] = { false };
    if (start != -1) dfs(start, visited);

    for (int i = 0; i <= 6; i++) {
        if (deg[i] > 0 && !visited[i]) {
            cout << 0;
            return 0; // không liên thông
        }
    }

    // kiểm tra bậc chẵn
    for (int i = 0; i <= 6; i++) {
        if (deg[i] % 2 != 0) {
            cout << 0;
            return 0; // có bậc lẻ → không có chu trình Euler
        }
    }

    // có thể tạo vòng tròn domino
    cout << 1 << "\n";
    euler(start);

    // in ra theo thứ tự
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i].first << " " << path[i].second << "\n";
    }

    return 0;
}
