#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[1000];
bool visited[1000];
int parent[1000];

void DFS(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            parent[v] = u;
            DFS(v);
        }
    }
}


//truy vet duong di bang mang parent. tu dinh bat dau 
void Path(int x, int y) {

    DFS(x);
    if (!visited[y]) {
        cout << "khong co duong di tu x toi y \n";
    }
    else {
        vector<int> path;
        while (y != x) {
            path.push_back(y);
            y = parent[y];
        }
        path.push_back(x);
        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        for (int t : path) {
            cout << t << " ";
        }
    }
}

int main(){
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    int n, x, y;
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        int v;
        while (cin >> v && v != -1) {
            adj[i].push_back(v);
        }
    }
    Path(x, y);
    return 0;
}

