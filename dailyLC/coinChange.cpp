#include <iostream>
#include <vector>

using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<long long> table(amount + 1, -1);
    table[0] = 0; // takes 0 coins to reach target amount 0
    for (unsigned int i = 0; i < amount + 1; ++i) {
        for (unsigned int j = 0; j < coins.size(); ++j) {
            int currCoin = coins[j];
            if (i + currCoin < amount + 1 && table[i] != -1) {
                if (table[i + currCoin] == -1) table[i + currCoin] = table[i] + 1;
                else table[i + currCoin]  = min(table[i + currCoin], table[i] + 1);
            }
        }
    }

    return table[amount];
}

int main() {
    // meh too lazy to handle input for this
    return 0;
}