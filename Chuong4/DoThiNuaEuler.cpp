#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n;
vector<vector<int>> adj;
vector<bool> visited;

//DFS để kiểm tra liên thông 
void DFS(int u) {
    visited[u] = true;
    for (int v = 0; v < n; v++) {
        if (adj[u][v] == 1 && !visited[v])
            DFS(v);
    }
}

// Kiểm tra liên thông (chỉ xét đỉnh có cạnh) 
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

    if (start == -1) return true; // đồ thị không có cạnh => coi như liên thông

    DFS(start);

    for (int i = 0; i < n; i++) {
        bool hasEdge = false;
        for (int j = 0; j < n; j++)
            if (adj[i][j] == 1) { hasEdge = true; break; }

        if (hasEdge && !visited[i]) return false;
    }

    return true;
}

//Kiểm tra đồ thị nửa Euler
// (liên thông và có đúng 2 đỉnh bậc lẻ)
bool isSemiEuler(vector<int>& oddVertices) {
    if (!isConnected()) return false;

    oddVertices.clear();
    for (int i = 0; i < n; i++) {
        int deg = 0;
        for (int j = 0; j < n; j++) deg += adj[i][j];
        if (deg % 2 != 0)
            oddVertices.push_back(i);
    }

    return (oddVertices.size() == 2);
}


void Euler(int u) {
    stack<int> st;
    vector<int> path;
    st.push(u);

    while (!st.empty()) {
        int x = st.top();
        int v = -1;

        for (int i = 0; i < n; i++) {
            if (adj[x][i] > 0) {
                v = i;
                st.push(v);
                adj[x][i]--;
                adj[i][x]--;
                break;
            }
        }

        if (v == -1) {
            st.pop();
            path.push_back(x);
        }
    }

    // In đường đi Euler
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] + 1 << " "; // +1 vì đỉnh đánh số từ 1
}

int main() {
    cin >> n;
    adj.assign(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];

    vector<int> oddVertices;

    if (isSemiEuler(oddVertices)) {
        cout << 1 << "\n";
        int start = oddVertices[0]; // bắt đầu từ một trong 2 đỉnh bậc lẻ
        Euler(start);
    }
    else {
        cout << 0;
    }
}
