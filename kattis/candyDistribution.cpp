#include <iostream>
#include <math.h>

using namespace std;

int extendedEuclidean(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int gcd = extendedEuclidean(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}

int main() {
    // kids == 1 and candy == 1 retunr 2
    //else if candy == 1 
    int t; cin >> t;
    while (t--) {
        int k, c; cin >> k >> c;
        int x, y;
        int gcd = extendedEuclidean(k, c, x, y);

        if (k == 1 && c <= 1) cout << 2 << endl;
        else if (k == 1 && c > 1) cout << 1 << endl;
        else if (c == 1) cout << (k + 1) << endl;
        else {
            if (gcd == 1) cout << ((y + k) % k) << endl;
            else cout << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}