#include <iostream>

using namespace std;

int main()
{
    int q, m, s, l;
    cin >> q >> m >> s >> l;

    int totalTime = (l / m) * q;

    int remainingTasks = l % m;
    if (remainingTasks)
        totalTime += q;

    // handling remaining machines
    int remainingMachines = m - remainingTasks; // left over free machines
    s -= remainingMachines * q;

    if (s > 0)
    {
        totalTime += (s / m) + (s % m);
    }

    cout << totalTime << endl;

    return 0;
}