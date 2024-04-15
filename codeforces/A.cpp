#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    string line;
    vector<string> lines;

    while (getline(cin, line)) {
        // cout << line << endl;
        lines.push_back(line);
    }

    for (int i = 1; i < n + 1; ++i) {
        if (i != n) {
            cout << lines[i] << endl;
        } else {
            cout << lines[i] << endl;
        }
    }
    return 0;
}