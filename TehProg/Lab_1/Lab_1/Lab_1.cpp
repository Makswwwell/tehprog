#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;
int N;

// Функция для генерации случайной матрицы
int** generateMatrix() {
    int** A = new int* [N]; 
    for (int i = 0; i < N; i++) {
        A[i] = new int[N]; 
    }

    srand(time(0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 100;
        }
    }

    return A;
}

// Функция для зеркального отражения матрицы относительно главной диагонали
void mirrorMatrix(int** A) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            swap(A[i][j], A[j][i]);
        }
    }
}

// Функция для вывода матрицы
void printMatrix(int** A) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Введите размерность матрицы: ";
    cin >> N;
    int** A = generateMatrix();

    cout << "Исходная матрица:" << endl;
    printMatrix(A);

    mirrorMatrix(A);

    cout << "\nМатрица после зеркального отражения:" << endl;
    printMatrix(A);

    // Освобождение памяти
    for (int i = 0; i < N; ++i) {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}
