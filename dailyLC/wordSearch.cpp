#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool dfs(vector<vector<char>> &grid, int row, int col, string word, int currIndex) {
        if (
            row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() ||
            word[currIndex] != grid[row][col] || grid[row][col] == '#'
        ) {
            return false;
        } else if (currIndex == word.size() - 1) {
            return true;
        }

        currIndex++;
        char ogChar = grid[row][col];
        grid[row][col] = '#';
        bool res = dfs(grid, row + 1, col, word, currIndex) ||
        dfs(grid, row - 1, col, word, currIndex) ||
        dfs(grid, row, col + 1, word, currIndex) ||
        dfs(grid, row, col - 1, word, currIndex);
        grid[row][col] = ogChar;
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, i, j, word, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};