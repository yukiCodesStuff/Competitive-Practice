#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int> res(deck.size(), 0);
        queue<int> q;
        sort(deck.begin(), deck.end());
        for (int i = 0; i < deck.size(); ++i) {
            q.push(i);
        }

        int sortIndex = 0;
        bool sendToBack = false;
        while (!q.empty()) {
            int currIndex = q.front(); q.pop();
            if (sendToBack) {
                q.push(currIndex);
                sendToBack = false;
            } else {
                res[currIndex] = deck[sortIndex++];
                sendToBack = true;
            }
        }
        
        return res;
    }
};