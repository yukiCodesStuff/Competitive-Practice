#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n; cin >> n;
    vector<long long> favNums(n);
    for (long long i = 0; i < n; ++i) {
        cin >> favNums[i];
        favNums[i]--;
    }

    // long long low = 0, high = n;
    long long leftRem = 0, rightRem = 0;
    long long leftElim = 0, rightElim = 0;
    long long skips = 0;
    for (long long i = 0; i < n; ++i) {
        long long currNum = favNums[i];
        leftRem = currNum - leftElim; // remaining on left
        rightRem = n - currNum - rightElim - 1; // remaining on right
        if (currNum < leftElim || (currNum > n - rightElim)) {
            skips++;
            continue;
        }
        if (leftRem > rightRem) {
            rightElim += rightRem + 1;
        } else if (leftRem < rightRem) {
            leftElim += leftRem + 1;
        } else {
            if (i < n - 1) {
                // cout << "Hit else on " << currNum << endl;
                long long next = favNums[i + 1];
                if (next < currNum) {
                    rightElim += rightRem + 1;
                } else {
                    leftElim += leftRem + 1;
                }
            }
        }
    }

    cout << n - skips << endl;
    return 0;
}