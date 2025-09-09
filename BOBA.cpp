#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    vector<string> tests(T);
    for (int i = 0; i < T; i++) {  //nhập lần lượt các sâu 1 đến T vào
        cin >> tests[i]; 
    }
    for (int t = 0; t < T; t++) {
        string str = tests[t];
        map<string, int> temp;
        for (int i = 0; i + 2 < (int)str.size(); i++) {
            string sub = str.substr(i, 3);      // đếm số bộ ba trùng nhau trong chuỗi
            temp[sub]++;
        }
        int ans = 0;
        for (auto& p : temp) {
            ans = max(ans, p.second); // tìm max
        }
        cout << ans << "\n"; 
    }
    return 0;
}
