#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;

class SegmentTree {
private:
    long long treeSize;
    vll SegTree;

    long long rangeQueryHelper(int qlow, int qhigh, int low, int high, int pos) {
        if (qlow <= low && qhigh >= high) {
            return SegTree[pos];
        }
        if (qlow > high || qhigh < low) {
            return 0;
        }
        int mid = (low + high) / 2;
        return
            rangeQueryHelper(qlow, qhigh, low, mid, 2*pos) +
            rangeQueryHelper(qlow, qhigh, mid + 1, high, 2*pos + 1);
    }

public:

    SegmentTree(long unsigned int size) : SegTree(4*size, 0) {
        long unsigned int treeSz = 2;
        while (treeSz < size) {
            treeSz *= 2;
        }
        treeSize = treeSz;
    }

    SegmentTree(vll inputArr) : SegTree(4*inputArr.size(), 0) {
        long unsigned int treeSz = 2;
        while (treeSz < inputArr.size()) {
            treeSz *= 2;
        }
        treeSize = treeSz;
        for (long unsigned int i = 0; i < inputArr.size(); ++i) {
            update(inputArr[i], i);
        }
    }

    long long conquer(long long a, long long b) {
        return a + b;
    }

    void update(long long updateVal, int updatePos) {
        int pos = updatePos + treeSize;
        SegTree[pos] = updateVal;
        pos /= 2;

        while (pos != 0) {
            SegTree[pos] = conquer(SegTree[pos * 2], SegTree[pos * 2 + 1]);
            pos /= 2;
        }
    }

    long long rangeQuery(int qlow, int qhigh) {
        return rangeQueryHelper(qlow, qhigh, 1, treeSize, 1);
    }

    void printElements() {
        for (auto el : SegTree) {
            cout << el << " ";
        }
        cout << endl;
    }
};

int main() {

    // vi vals = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int n, q;
    cin >> n >> q;

    vll inputArr;
    for (int i = 0; i < n; ++i) {
        long long num; cin >> num;
        inputArr.push_back(num);
    }

    SegmentTree segTree(inputArr);
    // segTree.printElements();

    for (int i = 0; i < q; ++i) {
        int command;
        cin >> command;
        if (command == 1) {
            int k, u;
            cin >> k >> u;
            segTree.update(u, k - 1);
            // segTree.printElements();
        } else if (command == 2) {
            int a, b;
            cin >> a >> b;
            cout << segTree.rangeQuery(a, b) << endl;
        }
    }

    return 0;
}