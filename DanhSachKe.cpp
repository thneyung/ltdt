#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#define FI "D:\\LEARN\\LyThuyetDoThi\\DanhSachKe.inp.txt"
#define FO "D:\\LEARN\\LyThuyetDoThi\\DanhSachKe.out"

int main() {
    ifstream fi(FI);
    ofstream fo(FO);

    if (!fi) {
        cout << " Khong the mo file input!" << endl;
        return 0;
    }

    int n;
    fi >> n;
    vector<vector<int>> adj(n + 1); // lưu danh sách kề, đánh số từ 1..n

    // đọc danh sách kề
    for (int i = 1; i <= n; i++) {
        int v;
        while (fi >> v && v != -1) {
            adj[i].push_back(v);
            
        }
    }

    // ghi ra số đỉnh
    fo << n << endl;
    cout << n << endl;

    // tính bậc các đỉnh
    for (int i = 1; i <= n; i++) {
        int degree = adj[i].size();
        fo << degree << endl;
        cout << degree << endl;
    }

    fi.close();
    fo.close();
    return 0;
}
