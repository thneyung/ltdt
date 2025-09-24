#include <iostream>
#include <fstream>
using namespace std;

#define FI "D:\\LEARN\\LyThuyetDoThi\\BacVaoBacRa.inp.txt"
#define FO "D:\\LEARN\\LyThuyetDoThi\\BacVaoBacRa.out"

const int MAX = 1000;
int a[MAX][MAX];

int main() {
    ifstream fi(FI);
    ofstream fo(FO);

    if (!fi) {
        cout << "Khong the mo file input!" << endl;
        return 0;
    }

    int n;
    fi >> n;

    // đọc ma trận kề
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fi >> a[i][j];
        }
    }

    // xuất số đỉnh
    fo << n << endl;
    cout << n << endl;

    // tính bậc vào, bậc ra
    for (int i = 0; i < n; i++) {
        int inDeg = 0, outDeg = 0;
        for (int j = 0; j < n; j++) {
            outDeg += a[i][j]; // bậc ra = tổng hàng i
            inDeg += a[j][i];  // bậc vào = tổng cột i
        }
        fo << inDeg << " " << outDeg << endl;
        cout << inDeg << " " << outDeg << endl;
    }

    fi.close();
    fo.close();
    return 0;
}
