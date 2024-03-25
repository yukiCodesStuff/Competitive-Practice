#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <utility>

using namespace std;

int minPathVal = INT_MAX;
map<vector<int>, int> memo;

int backtrack(int i, int prevJump, int pathVal, vector<int> &board) {
    vector<int> key = {i, prevJump};
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }
    
    if (i < 0 || i >= board.size()) {
        return 0; // out of bounds
    } else if (i == board.size() - 1) {
        return pathVal;
    }

    int nextJump = prevJump + 1; // jump forward
    // return min(backtrack(i + nextJump, nextJump, pathVal + board[i + nextJump], board), 
    //     backtrack(i - prevJump, prevJump, pathVal + board[i - prevJump], board));
    int left = backtrack(i + nextJump, nextJump, pathVal + board[i + nextJump], board);
    int right = backtrack(i - prevJump, prevJump, pathVal + board[i - prevJump], board);

    // cout << "Index: " << i << endl; 
    // cout << left << endl;
    // cout << right << endl;
    // cout << endl;

    if (left && right) {
        minPathVal = min(left, right);
    } else if (left) {
        minPathVal = min(minPathVal, left);
    } else if (right) {
        minPathVal = min(minPathVal, right);
    }

    return 0;
}

int main() {
    int n; cin >> n;
    vector<int> board(n);
    while (n--) {
        cin >> board[board.size() - n - 1];
    }

    int throwAway = backtrack(1, 1, board[1], board);
    cout << minPathVal << endl;

    return 0;
}