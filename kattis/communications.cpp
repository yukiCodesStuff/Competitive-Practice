#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
#include <math.h>

using namespace std;

typedef pair<double, double> point;
typedef pair<double, point> node;
typedef pair<int, node> idNode;
typedef pair<double, int> edge; // weight : node

vector<int> parents;

double calcDist(idNode a, idNode b) {
    double dist = sqrt(
        pow(a.second.second.first - b.second.second.first, 2) + 
        pow(a.second.second.second - b.second.second.second, 2)
    );

    dist -= (a.second.first + b.second.first);
    return dist;
}

int main() {
    int n; cin >> n;
    parents.resize(n);
    vector<idNode> idNodes;
    for (int i = 0; i < n; ++i) {
        double x, y, r; cin >> x >> y >> r;
        point pt = {x, y};
        node node = {r, pt};
        idNode idNode = {i, node};
        idNodes.push_back(idNode);
        parents[i] = i;
    }

    vector<edge> edges;
    for (auto a : idNodes) {
        for (auto b : idNodes) {
            if (a != b) {
                double dist = calcDist(a, b);
            }
        }
    }
    return 0;
}