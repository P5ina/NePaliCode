#include <iostream>
#include <vector>

using namespace std;

istream& operator >> (istream& in, vector<int>& data) {
    for (int & i : data) {
        in >> i;
    }
    return in;
}

ostream& operator << (ostream& out, const vector<int>& data) {
    for (int i = 0; i < data.size(); ++i) {
        if (i) {
            out << ' ';
        }
        out << data[i];
    }
    return out;
}

int main() {
    vector<int> nums(10);
    cin >> nums;
    cout << nums << endl;

    return 0;
}
