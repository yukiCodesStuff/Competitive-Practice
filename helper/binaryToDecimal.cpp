#include <iostream>
#include <string>

using namespace std;

int binToDec(string num) {
    int res = 0;
    int base = 1;
    for (int i = num.size() - 1; i > -1; --i) {
        res += (num[i] - '0') * base;
        base *= 2;
    }
    return res;
}