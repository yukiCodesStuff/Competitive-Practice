#include <iostream>
#include <vector>
#include <utility>
#include <sstream>
#include <string>
#include <unordered_map>
#include <stack>

using namespace std;

unordered_map<string, vector<string>> adj_list;
unordered_map<string, vector<string>> adj_list_t; // transpose
unordered_map<string, int> visited;
stack<string> visitStack;

void dfsFirstPass(string person) {
    if (visited[person] == 1) return;
    visited[person] = 1;
    for (auto p : adj_list[person]) {
        dfsFirstPass(p);
    }
    visitStack.push(person);
}

int dfsSecondPass(string person) {
    if (visited[person] == 2) return 0;
    visited[person] = 2;
    int componentSize = 1;
    for (auto p : adj_list_t[person]) {
        componentSize += dfsSecondPass(p);
    }
    return componentSize;
}

int kosaraju() {
    // int numComponents = 0;
    int maxSizeComponent = 0;
    for (auto it : adj_list) {
        string name = it.first;
        if (visited[name] != 1) {
            dfsFirstPass(name);
        }
    }

    while (!visitStack.empty()) {
        string currName = visitStack.top(); visitStack.pop();
        if (visited[currName] != 2) {
            // numComponents++;
            maxSizeComponent = max(dfsSecondPass(currName), maxSizeComponent);
        }
    }

    return maxSizeComponent;
}