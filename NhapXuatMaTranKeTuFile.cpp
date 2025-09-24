#include <iostream>
#include <fstream>
using namespace std;

#define FI "D:\\LEARN\\LyThuyetDoThi\\Graph.INP.txt"
#define FO "D:\\LEARN\\LyThuyetDoThi\\Graph.OUT.txt"

ifstream fi;
ofstream fo;

int n;                // số đỉnh
int a[100][100];      // ma trận kề

// Đọc dữ liệu từ file
void Nhap() {
    fi.open(FI);
    if (!fi) {
        cout << "Khong mo duoc file input!\n";
        return;
    }
    fi >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fi >> a[i][j];
        }
    }
    fi.close();
}

// Xuất dữ liệu ra màn hình và file
void Xuat() {
    fo.open(FO);
    if (!fo) {
        cout << "Khong mo duoc file output!\n";
        return;
    }

    cout << "So dinh cua do thi: " << n << endl;
    fo << "So dinh cua do thi: " << n << endl;

    cout << "Ma tran ke:" << endl;
    fo << "Ma tran ke:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
            fo << a[i][j] << " ";
        }
        cout << endl;
        fo << endl;
    }

    fo.close();
}

// Kiểm tra hợp lệ và loại đồ thị
void XuLy() {
    // Kiểm tra ma trận kề hợp lệ (chỉ chứa 0 hoặc 1)
    bool hopLe = true;
    for (int i = 0; i < n && hopLe; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != 0 && a[i][j] != 1) {
                hopLe = false;
                break;
            }
        }
    }

    if (!hopLe) {
        cout << "Do thi khong hop le!\n";
        return;
    }
    else {
        cout << "Do thi hop le!\n";
    }

    // Kiểm tra có hướng hay vô hướng
    bool coHuong = false;
    for (int i = 0; i < n && !coHuong; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != a[j][i]) {
                coHuong = true;
                break;
            }
        }
    }

    if (coHuong)
        cout << "Do thi co huong.\n";
    else
        cout << "Do thi vo huong.\n";
}

int main() {
    Nhap();
    Xuat();
    XuLy();
    return 0;
}
