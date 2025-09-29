#include <iostream>
#include <vector>
using namespace std;


vector<int> adj[1000];
vector<int> result;
bool visited[1000];

void  DFS(int u) {
    result.push_back(u);
    visited[u] = true;
    for (int v : adj [u]) {
        if (visited[v] == false) {
            DFS(v);
        }
    }   
}

int main()
{
    memset(visited, false, sizeof(visited));
    int n, start, v;
    cin >> n >> start;
    for (int i = 1; i <= n; i++){
        int v;
        while (cin >> v && v != -1) {
            adj[i].push_back(v);
        }
    }
    DFS(start);

    cout << result.size() -1 << "\n";
    for (int v = 1; v < result.size(); v++) cout << result[v] << " ";
    cout << "\n";

    return 0;
}

