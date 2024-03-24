#include <iostream>
#include <unordered_set>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj_list;
vector<bool> visited;
queue<int> ordering;

bool dfs(int s, unordered_set<int> &seen) {
    if (seen.find(s) != seen.end()) return false; // cycle detected
    if (visited[s]) return true;
    visited[s] = true;
    seen.insert(s);
    for (int x : adj_list[s]) {
        if (!dfs(x, seen)) {
            return false;
        } 
    }

    seen.erase(s);
    ordering.push(s);
    return true;
}

int main() {
    int n;
    vector<vector<int>> c(n, vector<int>(0));
    vector<int> indeg(n, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < c[i].size(); j++){
            indeg[c[i][j]] ++;
        }
    }
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }
    vector<int> a(0);
    while(q.size() != 0){
        int cur = q.front();
        q.pop();
        a.push_back(cur);
        for(int i = 0; i < c[cur].size(); i++){
            int next = c[cur][i];
            indeg[next] --;
            if(indeg[next] == 0){
                q.push(next);
            }
        }
    }
    if(a.size() != n){
        cout << "CYCLE DETECTED" << "\n";
    }
}