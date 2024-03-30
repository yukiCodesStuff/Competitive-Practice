#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <math.h>
#include <limits>

using namespace std;

typedef vector<pair<double, double>> vpff;

double calcTime(double x, vpff &houses) {
    double maxTime = 0;
    for (pair<double, double> &coord : houses) {
        double dist = sqrt(pow(x - coord.first, 2) + pow(coord.second, 2));
        maxTime = max(maxTime, dist);
    }
    return maxTime;
}

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;

        vpff houses(n);
        for (int i = 0; i < n; ++i) {
            double x, y; cin >> x >> y;
            houses[i] = make_pair(x, y);
        }

        double left = -200000, right = 200000;
        int itrCt = 0;
        double epsilon = 1e-7;
        while (abs(right - left) > epsilon) {
            double mid1 = left + ((right - left) / 3);
            double mid2 = right - ((right - left) / 3);

            double mid1Dist = calcTime(mid1, houses);
            double mid2Dist = calcTime(mid2, houses);
            if (mid1Dist < mid2Dist) {
                right = mid2;
            } else {
                left = mid1;
            }

            itrCt++;
        }

        cout << (left + right) / 2 << " " << calcTime((left + right) / 2, houses) << endl;;
    }
    return 0;
}