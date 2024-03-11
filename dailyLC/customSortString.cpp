#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        
        unordered_map<int, char> orderMap;
        unordered_map<char, int> charCt;
        for (int i = 0; i < order.size(); ++i) {
            orderMap[i] = order[i];
        }
        for (char c : s) {
            if (charCt.find(c) == charCt.end()) {
                charCt[c] = 0;
            }
            charCt[c]++;
        }

        vector<char> arr(s.size());
        int currIndex;
        for (int i = 0; i < order.size(); ++i) {
            char currChar = orderMap[i];
            while (charCt[currChar]--) {
                arr[currIndex] = currChar;
                ++currIndex;
            }
        }
        for (auto it : charCt) {
            while (it.second > 0) {
                it.second--;
                arr[currIndex] = it.first;
                currIndex++;
            }
        }

        string res(arr.begin(), arr.end());
        return res;
    }
};