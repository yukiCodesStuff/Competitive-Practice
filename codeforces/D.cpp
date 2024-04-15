#include <iostream>
#include <vector>

using namespace std;

struct Point2D {
    int x;
    int y;
    Point2D(int x, int y) : x(x), y(y) {}
};

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; +i) {
        int x, y; cin >> x >> y;
        Point2D pt(x, y);
    }
    return 0;
}