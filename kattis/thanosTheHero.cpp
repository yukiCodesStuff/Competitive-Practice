#include <iostream>
#include <vector>

using namespace std;

int main() {

    long long n; cin >> n;
    vector<long long> planets(n);
    for (long long i = 0; i < n; ++i) {
        cin >> planets[i];
    }

    long long kills = 0;
    for (long long i = n - 1; i > 0; --i) {
        long long x = planets[i];
        long long y = planets[i - 1];
        long long zero = 0;
        long long potentialKills = max(zero, y - (x - 1));
        planets[i - 1] -= potentialKills;
        // cout << potentialKills << endl;
        if (planets[i - 1] < 0) {
            cout << 1 << endl;
            return 0;
        }
        kills += potentialKills;
    }

    // if (!kills) cout << 1 << endl;
    // else cout << kills << endl;

    cout << kills << endl;

    return 0;
}