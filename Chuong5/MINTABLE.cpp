#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
const ll INF = (1LL << 60);

int N, M;
int SX, SY, TX, TY;
vector<vector<int>> A;

// 4 hướng: up, right, down, left
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

bool inside(int r, int c) {
    return r >= 1 && r <= N && c >= 1 && c <= M;
}

struct Node {
    ll d;
    int r, c;
    bool operator<(Node const& other) const {
        return d > other.d; // cho priority_queue min-heap
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Input: N M XI YI XJ YJ
    if (!(cin >> N >> M >> SX >> SY >> TX >> TY)) return 0;
    A.assign(N + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> A[i][j];
        }
    }

    // Nếu start hoặc target nằm ngoài hoặc start==target xử lý:
    if (!inside(SX, SY) || !inside(TX, TY)) {
        cout << "0\n";
        return 0;
    }
    // Nếu start == target: đường rỗng chi phí 0, số ô = 1
    if (SX == TX && SY == TY) {
        cout << "1\n0 1\n" << SX << " " << SY << "\n";
        return 0;
    }

    // dist, prev
    vector<vector<ll>> dist(N + 1, vector<ll>(M + 1, INF));
    vector<vector<pii>> pre(N + 1, vector<pii>(M + 1, { -1,-1 }));

    priority_queue<Node> pq;
    dist[SX][SY] = 0; // không cộng ô bắt đầu
    pq.push({ 0, SX, SY });

    while (!pq.empty()) {
        Node cur = pq.top(); pq.pop();
        ll d = cur.d; int r = cur.r, c = cur.c;
        if (d != dist[r][c]) continue;
        if (r == TX && c == TY) break; // có thể dừng sớm

        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k], nc = c + dc[k];
            if (!inside(nr, nc)) continue;
            // chỉ được đi vào ô trung gian nếu A[nr][nc] != 0
            // nhưng cho phép vào ô đích TX,TY dù A[TX][TY]==0
            if (nr == TX && nc == TY) {
                // luôn cho phép tới đích
            }
            else {
                if (A[nr][nc] == 0) continue;
            }
            // chi phí thêm khi bước vào ô (không cộng giá trị ô đích)
            ll add = (nr == TX && nc == TY) ? 0 : (ll)A[nr][nc];
            if (dist[nr][nc] > dist[r][c] + add) {
                dist[nr][nc] = dist[r][c] + add;
                pre[nr][nc] = { r,c };
                pq.push({ dist[nr][nc], nr, nc });
            }
        }
    }

    if (dist[TX][TY] == INF) {
        cout << "0\n";
        return 0;
    }

    // reconstruct path
    vector<pii> path;
    int cr = TX, cc = TY;
    while (!(cr == -1 && cc == -1)) {
        path.push_back({ cr, cc });
        pii p = pre[cr][cc];
        cr = p.first; cc = p.second;
        if (cr == -1 && cc == -1) break;
    }
    reverse(path.begin(), path.end());

    cout << "1\n";
    cout << dist[TX][TY] << " " << path.size() << "\n";
    for (auto& p : path) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}
