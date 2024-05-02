#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> heights(n);
    vector<int> arrows(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    int numArrows = 0;
    for (int i = 0; i < n; ++i) {
        int currHeight = heights[i];
        if (arrows[currHeight] == 0) {
            numArrows++;
            arrows[currHeight - 1]++;
        } else if (arrows[currHeight] > 0) {
            arrows[currHeight]--;
            arrows[currHeight - 1]++;
        }
    }
    cout << numArrows << endl;
    return 0;
}