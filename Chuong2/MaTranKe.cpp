#include <iostream>
#include <fstream>
using namespace std;

#define FI "D:\\LEARN\\LyThuyetDoThi\\MaTranKe.txt"
#define FO "D:\\LEARN\\LyThuyetDoThi\\MaTranKe.out"

const int MAX = 1000;
int a[MAX][MAX];   

int main() {
    ifstream fi(FI);
    ofstream fo(FO);

    if (!fi) {
        cout << " Khong the mo file input!" << endl;
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

    // ghi ra số đỉnh
    fo << n << endl;
    cout << n << endl;

    // tính bậc của từng đỉnh
    for (int i = 0; i < n; i++) {
        int degree = 0;
        for (int j = 0; j < n; j++) {
            degree += a[i][j];
        }
        fo << degree << endl;
        cout << degree << endl;
    }

    fi.close();
    fo.close();
    return 0;
}
