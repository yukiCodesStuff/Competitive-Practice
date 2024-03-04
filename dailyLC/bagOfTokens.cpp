#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {

        if (tokens.size() == 1) {
            return power > tokens[0];
        }

        sort(tokens.begin(), tokens.end());
        int start = 0, end = tokens.size() - 1, maxScore = 0, tempScore = 0;
        while (start < end) {
            bool moved = false;
            while (tokens[start] <= power) {
                moved = true;
                tempScore += 1;
                power -= tokens[start];
                start++; 
            }

            maxScore = max(maxScore, tempScore);
            
            if (tempScore > 0) {
                tempScore -= 1;
                power += tokens[end];
                end--;
            } else if (!moved) {
                break;
            }
        }

        return maxScore;
    }
};