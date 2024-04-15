#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> shirts(n);
    int leadShirt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> shirts[i];
        leadShirt = max(leadShirt, shirts[i]);
    }


    int res = 0;
    for (int i = 0; i < n; ++i) {
        int currColor = shirts[i];
        if (currColor < (leadShirt - 1)) {
            res += (leadShirt - 1) - currColor;
            // cout << "adding " << (leadShirt - 1) - currColor << endl;
        }
    }

    cout << res << endl;
    return 0;
}