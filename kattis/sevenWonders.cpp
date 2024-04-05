#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

int main() {
    string cards; cin >> cards;
    vector<int> score(3, 0);
    for (char c : cards) {
        if (c == 'T') score[0]++;
        else if (c == 'C') score[1]++;
        else if (c == 'G') score[2]++;
    }

    int finalScore = pow(score[0], 2) + pow(score[1], 2) + pow(score[2], 2);
    finalScore += 7 * min(min(score[0], score[1]), min(score[1], score[2]));
    cout << finalScore << endl;
    return 0;
}