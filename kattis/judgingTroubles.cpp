#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n; cin >> n;
    vector<string> kattis(n);
    vector<string> DOM(n);

    unordered_map<string, int> kattisCt;
    unordered_map<string, int> domCt;
    for (int i = 0; i < n; ++i) {
        cin >> kattis[i];
        kattisCt[kattis[i]]++;
    }

    for (int i = 0; i < n; ++i) {
        cin >> DOM[i];
        domCt[DOM[i]]++;
    }

    int res = 0;
    for (auto it : kattisCt) {
        if (domCt.find(it.first) != domCt.end()) {
            res += min(kattisCt[it.first], domCt[it.first]);
        }
    }

    cout << res << endl;
    return 0;
}