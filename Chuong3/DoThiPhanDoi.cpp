#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> adj[1000];
bool visited[1000];
int color[1000];
bool isBipartite = true;

void DFS(int u, int c) {
    color[u] = c;
    for (int v : adj[u]) {   // duyệt các đỉnh v kề với u, nếu chưa tô màu thì tô bằng màu đối lập
        if (color[v] == -1) {
            DFS(v, 1 - c);
        }
        else if (color[v] == c) { // nếu trùng màu thì vi phạm điều kiện
            isBipartite = false;
            return;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int v;
        while (cin >> v && v != -1) {
            adj[i].push_back(v);
        }
    }
    memset(color, -1, sizeof(color));

    //kiem tra tat ca cac diem dc tham hay chua
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            DFS(i, 0);
        }
    }

    if (isBipartite) cout << "Do thi phan doi\n";
    else cout << "Do thi khong phan doi\n";

    return 0;
}

