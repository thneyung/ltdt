#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    map<int, bool> check;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        int x = A[i];
        if (x < 1 || x > N) {  //kiểm tra có trong phạm vi 1 đến N
            cout << "NO" << endl;
            return 0;
        }
        // kiểm tra số trùng
        if (check[x]) { 
            cout << "NO" << endl;
            return 0;
        }
        check[x] = true;
    }
    cout << "YES" << endl;
    return 0;
}
