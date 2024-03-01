#include <iostream>
#include <string>

using namespace std;

string maximumOddBinaryNumber(string s) {
    int oneCount = 0;
    for (auto c : s) {
        if (c == '1') {
            oneCount++;
        }
    }

    string res = "";
    for (int i = 0; i < s.size(); ++i) {
        if (oneCount != 1) {
            res += '1';
            oneCount -= 1;
        } else if (oneCount == 1 && i == s.size() - 1) {
            res += '1';
        } else {
            res += '0';
        }
    }
    return res;
}

int main() {
    string s;
    cin >> s;
    cout << maximumOddBinaryNumber(s) << endl;
    return 0;
}