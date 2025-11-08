#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;


vector<int> adj[1000];
bool visited[1000];
int n, x, y, z;

// BFS đếm số đỉnh trong thành phần liên thông
void BFS(int start, bool removedVertex[], int rmX = -1, int rmY = -1) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            // bỏ qua đỉnh đã bị xóa
            if (removedVertex[v]) continue;

            // bỏ qua cạnh bị xóa
            if ((u == rmX && v == rmY) || (u == rmY && v == rmX)) continue;

            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

// Đếm số thành phần liên thông
int countCC(bool removedVertex[], int rmX = -1, int rmY = -1) {
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && !removedVertex[i]) {
            BFS(i, removedVertex, rmX, rmY);
            cnt++;
        }
    }
    return cnt;
}

int main() {

    cin >> n >> x >> y >> z;
    for (int i = 1; i <= n; i++) {
        int v;
        while (cin >> v && v != -1) {
            adj[i].push_back(v);
        }
    }

    // ban đầu không xóa gì
    bool removedVertex[1000];
    memset(removedVertex, false, sizeof(removedVertex));

    int k1 = countCC(removedVertex);

    // ---- Kiểm tra cạnh cầu ----
    int k2 = countCC(removedVertex, x, y);
    if (k2 > k1) cout << "canh cau\n";
    else cout << "khong la canh cau\n";

    // ---- Kiểm tra đỉnh khớp ----
    memset(removedVertex, false, sizeof(removedVertex));
    removedVertex[z] = true;  // xóa đỉnh z
    int k3 = countCC(removedVertex);
    if (k3 > k1) cout << "dinh khop\n";
    else cout << "khong la dinh khop\n";

    return 0;
}
