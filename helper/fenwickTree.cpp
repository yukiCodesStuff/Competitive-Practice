#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;

class FenwickTree { // OOP style
private:
    ll treeSize;
    vll ft, arr;

    ll getNext(ll num) {
        ll twosComplement = ~num + 1;
        ll andResult = num & twosComplement;
        return num + andResult;
    }

    ll getParent(ll num) {
        ll twosComplement = ~num + 1;
        ll andResult = twosComplement & num;
        return num - andResult;
    }

public:

    FenwickTree(ll size) : treeSize(size), ft(vll(size + 1, 0)), arr(vll(size, 0)) {};

    FenwickTree(vll inputArr) {
        treeSize = inputArr.size() + 1;
        ft.resize(treeSize, 0);
        arr = inputArr;
        for (long unsigned int i = 0; i < inputArr.size(); ++i) {
            updateFtHelper(i, inputArr[i]);
        }
    }

    void updateFtHelper(int index, ll val) {
        long unsigned int curr = index + 1; // curr node
        // cout << curr << endl;
        while (curr <= ft.size()) {
            ft[curr] += val;
            curr = getNext(curr);
            // cout << curr << endl;
        }
    }

    void updateFT(int index, ll val) {
        ll diff = val - arr[index - 1];
        arr[index - 1] = val;
        updateFtHelper(index - 1, diff);
    }

    void printElements() {
        for (auto x : ft) {
            cout << x << " ";
        }
        cout << endl;
    }

    ll rangeSumQuery(int left, int right) {
        return partialQuery(right) - partialQuery(left - 1);
    }

    ll partialQuery(int num) {
        ll result = ft[num];
        while (num != 0) {
            num = getParent(num);
            result += ft[num];
        }
        return result;
    }
};

int main() {

    int n, q;
    cin >> n >> q;

    vll inputArr(n);
    for (int i = 0; i < n; ++i) {
        ll num;
        cin >> num;
        inputArr[i] = num;
    }

    FenwickTree ft(inputArr);
    // ft.printElements();
    for (int i = 0; i < q; ++i) {
        int command;
        cin >> command;
        if (command == 1) {
            int k;
            ll u;
            cin >> k >> u;
            ft.updateFT(k, u);
            // ft.printElements();
        } else if (command == 2) {
            int a, b;
            cin >> a >> b;
            cout << ft.rangeSumQuery(a, b) << endl;
        }
    }

    return 0;
}