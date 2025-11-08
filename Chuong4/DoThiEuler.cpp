#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n;
vector<vector<int>> adj;
vector<bool> visited;

void DFS(int u) {
    visited[u] = true;
    for (int v = 0; v < n; v++) {
        if (adj[u][v] == 1 && !visited[v])
            DFS(v);
    }
}

bool isConnected() {
    visited.assign(n, false);

    int start = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == 1) {
                start = i;
                break;
            }
        }
        if (start != -1) break;
    }

    if (start == -1) return true; // Không có cạnh nào → coi là liên thông

    DFS(start);

    for (int i = 0; i < n; i++) {
        bool hasEdge = false;
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == 1) {
                hasEdge = true;
                break;
            }
        }
        if (hasEdge && !visited[i])
            return false;
    }

    return true;
}

bool isEulerGraph() {
    if (!isConnected()) return false;

    for (int i = 0; i < n; i++) {
        int deg = 0;
        for (int j = 0; j < n; j++)
            deg += adj[i][j];
        if (deg % 2 != 0)
            return false; // bậc lẻ
    }

    return true;
}

void Euler(int u) {
    stack<int> st;
    vector<int> cycle;
    st.push(u);

    while (!st.empty()) {
        int x = st.top();
        int v = -1;

        for (int i = 0; i < n; i++) {
            if (adj[x][i] > 0) { // có ít nhất 1 cạnh
                v = i;
                st.push(v);
                adj[x][i]--;   // xóa 1 cạnh giữa x và i
                adj[i][x]--;   // xóa 1 cạnh đối xứng
                break;
            }
        }

        if (v == -1) { // không còn cạnh nào từ x
            st.pop();
            cycle.push_back(x);
        }
    }

    // In chu trình Euler
    for (int i = cycle.size() - 1; i >= 0; i--)
        cout << cycle[i] + 1 << " "; // +1 nếu bạn đánh số đỉnh từ 1
}


int main() {

    cin >> n;
    adj.assign(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];

    if (isEulerGraph()) {
        cout << 1 << "\n";

        int start = 0;
        for (int i = 0; i < n; i++) {
            int deg = 0;
            for (int j = 0; j < n; j++) deg += adj[i][j];
            if (deg > 0) { start = i; break; } // chọn đỉnh có cạnh thật
        }

        Euler(start);
    } else cout << 0;
}
