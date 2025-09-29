#include <iostream>
#include <vector>
using namespace std;

//tìm dãy tất cả các số nguyên tố bé hơn n
vector<int> SNT(int n) {
    vector<int> primes;
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    return primes;
}
int main() {
    int N;
    while (cin >> N) {
        vector<int> primes = SNT(N);
        vector<int> primeCount(N + 1, 0); // đếm số mũ
        // phân tích từng số từ 2..N
        for (int i = 2; i <= N; i++) {
            int x = i;
            for (int p : primes) {
                while (x % p == 0) {
                    primeCount[p]++;
                    x /= p;
                }
                if (x == 1) break;
            }
        }
        // in kết quả
        bool first = true;
        for (int p : primes) {
            if (primeCount[p] > 0) {
                if (!first) cout << " ";
                cout << primeCount[p];
                first = false;
            }
        }
        cout << endl;
    }
    return 0;
}
