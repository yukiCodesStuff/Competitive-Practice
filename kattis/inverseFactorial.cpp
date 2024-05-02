#include <iostream>
#include <string>

using namespace std;

int main() {
	string n; cin >> n;
	long long y = 0;
	for (auto c : n) {
        y = (y * 10 + c - '0') % 1000000007;
    }
    long long f = 1;
	for (int i = 1;; i++) {
		f = 1 * f * i % 1000000007;
		if (f == y) {
			cout << i << '\n';
			return 0;
		}
	}
}