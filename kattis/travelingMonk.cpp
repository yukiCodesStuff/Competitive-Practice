#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

typedef pair<int, int> pii;

double calcDist(double time, vector<pii>& path) {
    double totalDistance = 0;
    double totalTime = 0;
    for (pii step : path) {
        if (time <= totalTime + step.first) {
            double slope = (double)step.second / step.first;
            totalDistance += slope * (time - totalTime);
            return totalDistance;
        }
        totalTime += step.first;
        totalDistance += step.second;
    }
    return totalDistance; 
}

int main() {
    int a, d; cin >> a >> d;
    double epsilon = pow(10, -5);
    vector<pii> ascent(a);
    vector<pii> descent(d);
    // remember to calculate the total time taken on ascent and descent for upper bound
    int totalDist = 0, totalTime = 0;
    for (int i = 0; i < a; ++i) {
        int t, h; cin >> h >> t;
        ascent[i] = make_pair(t, h);
        totalTime += t;
        totalDist += h;
    }
    for (int i = 0; i < d; ++i) {
        int t, h; cin >> h >> t;
        descent[i] = make_pair(t, h);
    }

    // cout << calcAscent(3.5, ascent) << endl;
    double lower = 0, upper = (double)totalTime;
    while (abs(upper - lower) > epsilon) {
        double middle = (upper + lower) / 2.0;
        // cout << "In calculating " << upper << " " << lower << " " << middle << endl;
        double ascentPos = calcDist(middle, ascent);
        double descentPos = totalDist - calcDist(middle, descent);
        // cout << ascentPos << " " << descentPos << endl;
        if (ascentPos >= descentPos) {
            // they passed each other
            upper = middle;
        } else {
            lower = middle;
        }
    }
    cout << (upper + lower) / 2.0 << endl;
    return 0;
}