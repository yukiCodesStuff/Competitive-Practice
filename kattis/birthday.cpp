#include <iostream>
#include <vector>

using namespace std;

int main() {
    int p, c;
    while (cin >> p) {
        cin >> c;
        if (p == 0 && c == 0) break;
        vector<int> indegrees(p, 0);
        while (c--) {
            int x, y; cin >> x >> y;
            indegrees[x]++;
            indegrees[y]++;
        }

        bool canLose = true;
        for (int &p : indegrees) {
            if (p < 2) canLose = false;
        }

        if (!canLose) cout << "Yes" << endl;
        else cout << "No" << endl; 
    }
    return 0;
}