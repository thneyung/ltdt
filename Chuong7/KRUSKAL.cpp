#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Cấu trúc lưu cạnh
struct Edge {
    int u, v, w;
    bool operator<(const Edge &other) const {
        return w < other.w; // Sắp xếp theo trọng số tăng dần
    }
};

vector<int> parent, rnk;
vector<Edge> edges, mst;

// Hàm tìm gốc của đỉnh (có nén đường đi)
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

// Hàm hợp nhất hai tập (theo rank)
bool union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b)
        return false; // cùng tập → bỏ qua (tạo chu trình)
    if (rnk[a] < rnk[b])
        swap(a, b);
    parent[b] = a;
    if (rnk[a] == rnk[b])
        rnk[a]++;
    return true;
}

// Thuật toán Kruskal chính
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    edges.resize(m);
    for (int i = 0; i < m; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    sort(edges.begin(), edges.end()); // Sắp xếp các cạnh

    parent.resize(n + 1);
    rnk.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    int totalWeight = 0;
    for (auto &e : edges) {
        if (union_sets(e.u, e.v)) {
            mst.push_back(e);
            totalWeight += e.w;
        }
    }

    // In kết quả theo yêu cầu
    cout << mst.size() << " " << totalWeight << "\n";
    for (auto &e : mst)
        cout << e.u << " " << e.v << " " << e.w << "\n";

    return 0;
}
