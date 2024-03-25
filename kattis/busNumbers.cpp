#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {

    int m; cin >> m;
    if (m < 102) {
        cout << "none" << endl;
        return 0;
    }

    vector<long long int> busNumbers;
    for (int i = 1; i <= 73; ++i) {
        for (int j = i; j <= 73; ++j) {
            long long int cubeI = pow(i, 3);
            long long int cubeJ = pow(j, 3);
            busNumbers.push_back(cubeI + cubeJ);
        }
    }
    sort(busNumbers.begin(), busNumbers.end());
    int index = busNumbers.size() - 1;
    while (busNumbers[index] > m) {
        index--;
    }

    cout << busNumbers[index] << endl;

    return 0;
}