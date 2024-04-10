#include <iostream>
#include <vector>
#include <utility>
#include <sstream>
#include <string>

using namespace std;



int main() {
    int n; cin >> n; n++;
    while (n--) {
        string line; getline(cin, line);
        if (line.empty()) continue;

        stringstream ss(line);
        string name, spokenLanguage; ss >> name >> spokenLanguage;
        vector<string> understands = {spokenLanguage};
        string lang;
        while (ss >> lang) {
            understands.push_back(lang);
        }

        // cout << name << ", " << spokenLanguage << ": ";
        // for (auto l : understands) {
        //     cout << l << " ";
        // }
        // cout << endl;
    }
    return 0;
}