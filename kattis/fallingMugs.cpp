#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int d; cin >> d;

    for (long long i = 0; i <= 200000; ++i) {
        double test = sqrt(d + pow(i, 2));
        if (floor(test) == test) {
            cout << i << " " << test << endl;
            return 0;
        }
    }

    cout << "impossible" << endl;
    return 0;
}