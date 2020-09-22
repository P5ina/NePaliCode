#include <iostream>
#include <vector>
#include <string>

using namespace std;

istream &operator>>(istream &in, vector<int> &data) {
    string temp;
    in >> temp;
    while (temp != "#") {
        try {
            data.push_back(stoi(temp));
        }
        catch (invalid_argument const &e) {
            cerr << "Bad input: invalid_argument thrown" << endl;
        }
        catch (out_of_range const &e) {
            cerr << "Integer overflow: out_of_range thrown" << endl;
        }
        in >> temp;
    }
    return in;
}

ostream &operator<<(ostream &out, const vector<int> &data) {
    for (int i = 0; i < data.size(); ++i) {
        if (i) {
            out << ' ';
        }
        out << data[i];
    }
    return out;
}

int main() {
    vector<int> nums = vector<int>(0);
    cin >> nums;
    cout << nums << endl;

    return 0;
}
