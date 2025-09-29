#include <iostream>
using namespace std;

//đếm có bao nhiêu số 5(số lượng số 5 = số lượng số 0 trong N!)
long long countZeros(long long n) {
    long long temp = 0;
    while (n >= 5) {
        temp += n / 5;
        n = n/5;
    }
    return temp;
}

int main() {
    long long N;
    while (cin >> N) {
        cout << countZeros(N) << "\n";
    }
    return 0;
}
