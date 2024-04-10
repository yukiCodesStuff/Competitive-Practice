#include <vector>

using namespace std;

class Edge
{
public:
    int from;
    int to;
    Edge* residual;
    double flow;
    double cost;
    double capacity;
    double originalCost;

    Edge(int from, int to, double capacity)
        : from(from), to(to), capacity(capacity), originalCost(0) {
            this->residual = nullptr;
        }
    Edge(int from, int to, double capacity, double cost) 
        : from(from), to(to), capacity(capacity) {
            this->originalCost = this->cost = cost;
            this->residual = nullptr;
        }

    bool isResidual() {
        return this->capacity == 0;
    }

    double remainingCapacity() {
        return this->capacity - this->flow;
    }

    void augment(double bottleNeck) {
        this->flow += bottleNeck;
        if (residual != NULL) {
            residual->flow -= bottleNeck;
        }
    }
};

class NetFlowBase
{
private:
    int visitedToekn = 1;
    vector<int> visited;
public:
    int n, s, t;

    double maxFlow;
    
    vector<vector<Edge>> graph;

};