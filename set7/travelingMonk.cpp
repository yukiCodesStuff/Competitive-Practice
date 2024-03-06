#include <iostream>
#include <vector>

using namespace std;

int main() {

    int a, d; // num segments
    cin >> a >> d;
    
    // pre processing
    vector<double> ascendingSegments(a);
    vector<double> ascendingRates(a);
    vector<double> descendingSegments(d);
    vector<double> descendingRates(d);

    for (int i = 0; i < a; ++i) {
        double dist, time;
        cin >> dist >> time;
        ascendingSegments[i] = time;
        ascendingRates[i] = dist / time;
    }

    for (int i = 0; i < d; ++i) {
        double dist, time;
        cin >> dist >> time;
        descendingSegments[i] = time;
        descendingRates[i] = dist / time;
    }

    return 0;
}