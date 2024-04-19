#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool dfsSearch(vector<vector<char>> &grid, vector<vector<int>> &visited, int row, int col, string &currWord, int wordIndex) {
    if (wordIndex == currWord.size()) return true;
    else if (
        row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() ||
        visited[row][col] || grid[row][col] != currWord[wordIndex]
    ) {
        return false;
    }

    visited[row][col] = 1;
    wordIndex++;
    bool found = 
        dfsSearch(grid, visited, row + 1, col, currWord, wordIndex) || 
        dfsSearch(grid, visited, row - 1, col, currWord, wordIndex) ||
        dfsSearch(grid, visited, row, col - 1, currWord, wordIndex) || 
        dfsSearch(grid, visited, row, col + 1, currWord, wordIndex) || 
        dfsSearch(grid, visited, row + 1, col + 1, currWord, wordIndex) || 
        dfsSearch(grid, visited, row - 1, col - 1, currWord, wordIndex) || 
        dfsSearch(grid, visited, row + 1, col - 1, currWord, wordIndex) || 
        dfsSearch(grid, visited, row - 1, col + 1, currWord, wordIndex);

    visited[row][col] = 0;
    return found;
}

int main() {
    int w; cin >> w;
    vector<string> words(w);
    for (int i = 0; i < w; ++i) cin >> words[i];
    sort(words.begin(), words.end());

    int b; cin >> b;
    while (b--) {
        vector<vector<char>> grid(4, vector<char>(4));
        vector<vector<int>> visited(4, vector<int>(4, 0));
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) cin >> grid[i][j];
        }

        vector<string> foundWords;
        int totalScore = 0;
        string longestWord = "";
        for (string word : words) {
            bool found = false;
            for (int i = 0; i < 4 && !found; ++i) {
                for (int j = 0; j < 4 && !found; ++j) {
                    if (word[0] == grid[i][j] && dfsSearch(grid, visited, i, j, word, 0)) {
                        foundWords.push_back(word);
                        if (word.size() == 3 || word.size() == 4) totalScore += 1;
                        else if (word.size() == 5) totalScore += 2;
                        else if (word.size() == 6) totalScore += 3;
                        else if (word.size() == 7) totalScore += 5;
                        else if (word.size() == 8) totalScore += 11;

                        if (word.size() > longestWord.size()) longestWord = word;
                        found = true;
                    }
                }
            }
        }

        cout << totalScore << " " << longestWord << " " << foundWords.size() << endl;
    }
    return 0;
}