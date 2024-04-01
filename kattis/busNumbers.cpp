#include <vector>
#include <iostream>
#include <math.h>
#include <unordered_map>

using namespace std;

int main() {
    int m; cin >> m;
    vector<long long> cubes;
    for (long long i = 0; i < 74; ++i) {
        cubes.push_back(pow(i, 3));
    }

    unordered_map<long long, int> busNums;
    for (int i = 0; i < cubes.size(); ++i) {
        for (int j = i + 1; j < cubes.size(); ++j) {
            busNums[cubes[i] + cubes[j]]++;
        }
    }

    long long busNum = 0;
    for (auto n : busNums) {
        if (n.second > 1 && n.first <= m) {
            busNum = max(busNum, n.first);
        }
    }

    if (busNum) cout << busNum << endl;
    else cout << "none" << endl;

    return 0;
}