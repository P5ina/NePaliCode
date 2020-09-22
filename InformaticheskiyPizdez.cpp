#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> kek;
    int twosCount = 0;

    int n;
    while (n != 0) {
        cin >> n;

        if (n != 0) {
            if (n == 2) {
                twosCount++;
            }
            kek.push_back(n);
        }
    }

    if (twosCount < 2) {
        cout << -1; return 0;
    }


    bool flag = false;
    int sum = 0;

    for (int i = kek.size() - 1; i >= 0; i--) {
        if (!flag && kek[i] == 2) {
            flag = true;
            continue;
        }

        if (flag) {
            if (kek[i] == 2) { break; }
            sum += kek[i];
        }
    }

    cout << sum << endl;

    return 0;
}
