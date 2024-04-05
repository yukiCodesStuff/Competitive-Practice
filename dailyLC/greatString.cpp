#include <string>

using namespace std;

class Solution {
public:
    string makeGood(string s) {
        string res = s;
        int ct = 0;
        bool fail = true;
        while (fail) {
            string newStr = "";
            for (int i = 0; i < res.size(); ++i) {
                if (
                    i < res.size() - 1 && 
                    ((isupper(res[i]) ^ isupper(res[i + 1])) && tolower(res[i]) == tolower(res[i + 1]))
                ) {
                    i += 1;
                }
                else if (i < res.size()) {
                    newStr += res[i];
                }
            }
            fail = false;
            for (int i = 0; i < newStr.size(); ++i) {
                if (
                    i < newStr.size() - 1 && 
                    ((isupper(newStr[i]) ^ isupper(newStr[i + 1])) && tolower(newStr[i]) == tolower(newStr[i + 1]))
                ) {
                    fail = true;
                }
            }
            if (!fail) {
                return newStr;
            }
            res = newStr;
        }
        return "";
    }
};