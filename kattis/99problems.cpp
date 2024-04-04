#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    int left = n, right = n;
    while (left % 100 != 99 || right % 100 != 99) {
        if (right % 100 == 99) {
            cout << right << endl;
            return 0;
        } else if (left % 100 == 99) {
            cout << left << endl;
            return 0;
        }
        left--;
        right++;
    }

    cout << right << endl;
    return 0;
}