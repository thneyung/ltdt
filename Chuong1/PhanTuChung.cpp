#include <iostream>
#include <set>
using namespace std;

int main() {
	int nx, ny, nz;
	set<int> x, y, z, ans;
	cin >> nx;
	for (int i = 0; i < nx; i++) {
		int val; cin >> val;
		x.insert(val);
	}
	cin >> ny;
	for (int i = 0; i < ny; i++) {
		int val; cin >> val;
		y.insert(val);
	}
	cin >> nz;
	for (int i = 0; i < nz; i++) {
		int val; cin >> val;
		z.insert(val);
	}
	// tìm giao của ba tập hợp rồi đưa vào ans 
	for (int i : x) {
		if (y.find(i) != y.end() && z.find(i) != z.end()) {
			ans.insert(i);
		}
	}
	cout << ans.size() << endl;
	for (int val : ans)
		cout << val << " ";
	cout << endl;

	return 0;
}
