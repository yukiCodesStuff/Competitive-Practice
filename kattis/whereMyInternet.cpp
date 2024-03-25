#include <iostream>
#include <vector>

using namespace std;

vector<int> parents;

int findParent(int x) {
    if (parents[x] != x) {
        parents[x] = findParent(parents[x]);
    }

    return parents[x];
}

void makeUnion(int x, int y) {
    int xParent = findParent(x);
    int yParent = findParent(y);

    if (xParent == yParent) return;
    parents[yParent] = xParent;
}

int main() {

    // implement union find
    int n, m; cin >> n >> m;
    parents.resize(n + 1);

    // set parent self
    for (int i = 1; i < n + 1; ++i) {
        parents[i] = i;
    }

    // make unions
    while (m--) {
        int x, y; cin >> x >> y;
        makeUnion(x, y);
    }

    vector<int> notConnected;
    for (int i = 1; i < parents.size(); ++i) {
        if (findParent(i) != findParent(1)) {
            notConnected.push_back(i);
        }
    }

    if (!notConnected.size()) {
        cout << "Connected" << endl;
    } else {
        for (int house : notConnected) {
            cout << house << endl;
        }
    }

    return 0;
}