#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<int> adj[1000];
bool visited[1000];

void BFS(int start, vector<int>& result) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    int n, x;
    cin >> n >> x;

    // nhập danh sách kề
    for (int i = 1; i <= n; i++) {
        int v;
        while (cin >> v && v != -1) {
            adj[i].push_back(v);
        }
    }

    memset(visited, false, sizeof(visited));
    vector<int> result;

    BFS(x, result);

    cout << result.size()-1 << endl;
    for (int v = 1; v < result.size(); v++) cout << result[v] << " ";
    cout << "\n";


    return 0;
}
