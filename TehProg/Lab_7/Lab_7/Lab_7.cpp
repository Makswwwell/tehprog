#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_max(const vector<int>& a) {
    return *max_element(a.begin(), a.end());
}

vector<int> find_index(const vector<int>& a) {
    vector<int> res;
    int index = 0;
    for (int num : a) {
        if (num < 0 && index % 2 == 0) {
            res.push_back(index);
        }
        ++index;
    }
    return res;
}

vector<int> set_max(int max, const vector<int>& a, const vector<int>& res) {
    vector<int> modified(a);
    auto iter = modified.begin();
    for (int index : res) {
        iter += index;
        iter = modified.insert(iter, max);
        ++iter;
    }
    return modified;
}

int main() {
    vector<int> input = { 2, -2, 7, 3, -4, 8, -5 };

    int max_val = find_max(input);
    vector<int> indexes = find_index(input);
    vector<int> result = set_max(max_val, input, indexes);

    for (int num : result) {
        cout << num << ' ';
    }
    cout << endl;

    return 0;
}
