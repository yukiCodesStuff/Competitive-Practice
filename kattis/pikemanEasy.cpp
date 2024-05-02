#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    
    int a, b, c;
    cin >> a >> b >> c;
    
    vector<int> times(n);
    cin >> times[0];
    
    for (int i = 1; i < n; i++) {
        times[i] = ((long long)a * times[i - 1] + b) % c + 1;
    }
    
    sort(times.begin(), times.end());
    
    int numSolved = 0;
    long long currPenalty = 0;
    long long totalPenalty = 0;
    long long currTime = 0;
    
    for (int i = 0; i < n; i++) {
        if (currTime + times[i] <= t) {
            currTime += times[i];
            numSolved++;
            totalPenalty = (totalPenalty + currTime) % 1000000007;
        } else {
            break;
        }
    }
    
    cout << numSolved << " " << totalPenalty << endl;
    
    return 0;
}
