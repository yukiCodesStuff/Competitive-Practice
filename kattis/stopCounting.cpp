#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n; cin >> n;
    vector<int> cards(n);
    for (int i = 0; i < n; ++i) {
        cin >> cards[i];
    }

    float leftRunningAvg = 0;
    float rightRunningAvg = 0;

    int left = 0, right = n - 1;
    int leftSum = 0, rightSum = 0;
    int leftCt = 0, rightCt = 0;
    while (left < n) {
        leftCt++;
        leftSum += cards[left];
        float newAvg = (float)leftSum / leftCt;
        if (newAvg < leftRunningAvg) {
            leftCt--;
            leftSum -= cards[left];
            break;
        }
        else leftRunningAvg = newAvg;

        left++;
    }

    while (right >= 0) {
        rightCt++;
        rightSum += cards[right];
        float newAvg = (float)rightSum / rightCt;
        if (newAvg < rightRunningAvg) {
            rightCt--;
            rightSum -= cards[right];
            break;
        }
        else rightRunningAvg = newAvg;

        right--;
    }

    // cout << leftRunningAvg << endl;
    // cout << rightRunningAvg << endl;

    if (!leftCt && !rightCt) cout << 0 << endl;
    else cout << (float)(leftSum + rightSum) / (float)(leftCt + rightCt) << endl;

    return 0;
}