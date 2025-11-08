#include <iostream>
using namespace std;

int n;
int a[105][105];     // ma trận kề
int x[105];          // lưu đường đi
bool visited[105];   // đánh dấu đỉnh đã đi
bool found = false;  // kiểm tra có chu trình Hamilton hay chưa

void FindHamiltonCycle(int i) {
    if (found) return; // nếu đã tìm thấy thì dừng
    if (i == n) {
        if (a[x[i - 1]][x[0]] == 1) {
            cout << 1 << "\n";
            for (int k = 0; k < n; k++)
                cout << x[k] + 1 << " ";
            cout << x[0] + 1 << "\n";
            found = true;
        }
        return;
    }

    for (int j = 0; j < n; j++) {
        if (a[x[i - 1]][j] == 1 && !visited[j]) {
            x[i] = j;
            visited[j] = true;
            FindHamiltonCycle(i + 1);
            visited[j] = false; // quay lui
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    // khởi tạo
    memset(visited, false, sizeof(visited));
    x[0] = 0;          // bắt đầu từ đỉnh 1 (chỉ số 0)
    visited[0] = true;

    FindHamiltonCycle(1);

    if (!found)
        cout << 0 << "\n";
}
