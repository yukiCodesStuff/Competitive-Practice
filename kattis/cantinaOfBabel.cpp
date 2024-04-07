#include <iostream>
#include <vector>
#include <utility>
#include <sstream>
#include <string>

using namespace std;

int Time = 0;

void dfsBridges(
    int node, int parent, vector<int> &visited,
    vector<int> &d, vector<int> &low, vector<pair<int, int>> &bridges, vector<vector<int>> &adj
) {
    visited[node] = 1;
    d[node] = low[node] = Time;
    Time++;
    for (auto &it : adj[node]) {
        if (it == parent) continue;
        if (visited[it] == 0) { // not visited
            dfsBridges(it, node, visited, d, low, bridges, adj);
            low[node] = min(low[node], low[it]); // look through adjacent node's EXCEPT PARENT
            if (low[it] > d[node]) {
                bridges.push_back({it, node});
            }
        } else { // adjacent node already visited, see if we can update the current low
            low[node] = min(low[node], low[it]);
        }
    }
}

int main() {
    int n; cin >> n; n++;
    while (n--) {
        string line; getline(cin, line);
        if (line.empty()) continue;
        stringstream ss(line);
        string name, spokenLanguage; ss >> name >> spokenLanguage;
        vector<string> understands = {spokenLanguage};
        string lang;
        while (ss >> lang) {
            understands.push_back(lang);
        }

        cout << name << ", " << spokenLanguage << ": ";
        for (auto l : understands) {
            cout << l << " ";
        }
        cout << endl;
    }
    return 0;
}