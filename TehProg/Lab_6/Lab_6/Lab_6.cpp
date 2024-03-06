#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

template<typename T>
vector<vector<T>> shift_matrix(const vector<vector<T>>& matrix) {
    int n = matrix.size();
    vector<vector<T>> rotated(n, vector<T>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            rotated[j][n - 1 - i] = matrix[i][j];
        }
    }

    cout << "\nСдвинутая матрица:" << endl;
    for (const auto& row : rotated) {
        for (const T& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return rotated;
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<vector<int>> intMatrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<vector<double>> doubleMatrix = {
        {1.1, 2.2, 3.3},
        {4.4, 5.5, 6.6},
        {7.7, 8.8, 9.9}
    };

    cout << "Исходная int матрица:" << endl;
    for (const auto& row : intMatrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    auto intMatrix_shift = shift_matrix(intMatrix);

    cout << "Исходная double матрица:" << endl;
    for (const auto& row : doubleMatrix) {
        for (double val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    auto doubleMatrix_shift = shift_matrix(doubleMatrix);

    return 0;
}
