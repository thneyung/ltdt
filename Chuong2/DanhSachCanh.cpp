#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#define FI "D:\\LEARN\\LyThuyetDoThi\\DanhSachCanh.inp"
#define FO "D:\\LEARN\\LyThuyetDoThi\\DanhSachCanh.out"

int main() {
    ifstream fi(FI);
    ofstream fo(FO);

    if (!fi) {
        cout << "Khong the mo file input!" << endl;
        return 0;
    }

    int n, m;
    fi >> n >> m;

    vector<int> degree(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        fi >> u >> v;
        degree[u]++;
        degree[v]++;
    }

    // Xuất kết quả
    fo << n << endl;
    cout << n << endl;

    for (int i = 1; i <= n; i++) {
        fo << degree[i] << endl;
        cout << degree[i] << endl;
    }

    fi.close();
    fo.close();
    return 0;
}
