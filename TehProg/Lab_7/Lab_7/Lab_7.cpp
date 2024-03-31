#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_max(const vector<int>& a) {
    return *max_element(a.begin(), a.end());
}

int main() {
    vector<int> input = { 2, 3, -7, 3, -4, 8, -5, 3 };

    int max_val = find_max(input);

    for (int num : input) {
        cout << num << ' ';
    }
    cout << endl;

    vector<size_t> ind;
    for (size_t i = 0; i < input.size(); i++) {
        if (input[i] < 0 && i % 2 == 0) {
            ind.push_back(i);
        }
    }

    for (auto it = ind.rbegin(); it != ind.rend(); ++it) {
        input.insert(input.begin() + *it + 1, max_val);
    }

    for (int num : input) {
        cout << num << ' ';
    }
    cout << endl;

    return 0;
}
