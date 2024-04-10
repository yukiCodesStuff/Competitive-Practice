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

void printAdjacencyList() {
    cout << endl << "Adjacency List" << endl;
    for (auto it : adj_list) {
        cout << it.first << ": ";
        for (auto p : it.second) {
            cout << p << " ";
        }
        cout << endl;
    }
}

void printAdjacencyListTranspose() {
    cout << endl << "Adjacency List Transpose" << endl;
    for (auto it : adj_list_t) {
        cout << it.first << ": ";
        for (auto p : it.second) {
            cout << p << " ";
        }
        cout << endl;
    }
}

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

int main() {
    int n; cin >> n; 
    int ogN = n; n++;

    
    unordered_map<string, vector<string>> translate;
    unordered_map<string, vector<string>> spokenLangs; // character : languages

    // pre processing
    while (n--) {
        string line; getline(cin, line);
        if (line.empty()) continue;

        stringstream ss(line);
        string name, spokenLanguage; ss >> name >> spokenLanguage;
        vector<string> understands = {spokenLanguage};
        translate[spokenLanguage].push_back(name);
        string lang;
        while (ss >> lang) {
            understands.push_back(lang);
            translate[lang].push_back(name);
        }

        spokenLangs[name] = understands;
    }

    for (auto it : spokenLangs) {
        string name = it.first;
        string spokenLanguage = it.second[0];
        visited[name] = 0;
        for (auto p : translate[spokenLanguage]) {
            if (p != name) {
                adj_list[name].push_back(p);
                adj_list_t[p].push_back(name);
            }
        }
    }

    // printAdjacencyList();
    // printAdjacencyListTranspose();

    cout << ogN - kosaraju() << endl;

    return 0;
}