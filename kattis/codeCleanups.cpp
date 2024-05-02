#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
    }

    int curr = 0;
    int cleanups = 0;
    int penaltyAddon = 0;
    int currPenalty = 0;
    for (int i = 0; i < 365; ++i) {
        if (i == a[curr]) {
            penaltyAddon++;
            curr++;
        }

        currPenalty += penaltyAddon;
    }

    cout << cleanups << endl;
    return 0;
}