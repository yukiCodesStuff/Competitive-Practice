#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n;

    while (cin >> n) {
        int m; cin >> m;
        vector<int> moves(m);

        for (int i = 0; i < m; ++i) {
            cin >> moves[i];
        }

        vector<bool> table(n + 1, false);
        // table[0] = false;
        for (int i = 1; i < n + 1; ++i) {
            for (int move : moves) {
                if (i - move > -1 && !table[i - move]) {
                    table[i] = !table[i - move];
                    break;
                }
            }
        }

        if (table[n]) cout << "Stan wins" << endl;
        else cout << "Ollie wins" << endl;
    }

    return 0;
}