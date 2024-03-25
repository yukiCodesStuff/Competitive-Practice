#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <utility>

using namespace std;

map<vector<int>, int> memo;

// remove the pathval from the parameters
int backtrack(int i, int prevJump, int pathVal, vector<int> &board) {
    vector<int> key = {i, prevJump};
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }
    
    if (i < 0 || i >= board.size()) {
        return INT_MAX; // out of bounds
    } else if (i == board.size() - 1) {
        return pathVal;
    }

    int nextJump = prevJump + 1; // jump forward
    // memo[key] = pathVal;
    memo[key] = min(backtrack(i + nextJump, nextJump, pathVal + board[i + nextJump], board), 
        backtrack(i - prevJump, prevJump, pathVal + board[i - prevJump], board));
    return memo[key];

    // return  min(backtrack(i + nextJump, nextJump, pathVal + board[i + nextJump], board), 
    //     backtrack(i - prevJump, prevJump, pathVal + board[i - prevJump], board));
}

int main() {
    int n; cin >> n;
    vector<int> board(n);
    while (n--) {
        cin >> board[board.size() - n - 1];
    }

    int minVal = backtrack(1, 1, board[1], board);
    cout << minVal << endl;

    return 0;
}