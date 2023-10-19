#include <iostream>
#include <windows.h>
#include <string>
#include <cstring>

using namespace std;

// Функция для переворота массива строк
string* reverse_arr(string* arr, int n) {
    for (int i = 0; i < n / 2; i++) {
        string temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }

    return arr;
}


string task_using_string(string str) {
    int index = -1;
    int n = 0;
    string* str_arr = nullptr;

    if (str.size() % 2 == 1) {
        for (int i = 0; i < str.size(); i++) {
            if (isdigit(str[i])) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            return "В строке нет чисел";
        }

        // Выделяем память для массива строк
        n = str.size() - index;
        str_arr = new string[n];

        string words = "";
        int j = 0;

        for (size_t i = index; i < str.size(); i++) {
            words += str[i];
            if (str[i] == ' ' || i == str.size() - 1) {
                str_arr[j++] = words;
                words = "";
            }
        }

        // Переворачиваем массив строк
        str_arr = reverse_arr(str_arr, n);

        string result = "";

        for (int i = 0; i < n; i++) {
            if (str_arr[i] != "")
            {
                result += str_arr[i] + " ";
            }
        }

        // Освобождаем память, выделенную для str_arr
        delete[] str_arr;

        return result;
    } else {
        return "Строка имеет четное количество символов";
    }
}

int main()
{
	setlocale(LC_ALL, "Russian");

	string a = "Мама купила 33 апельсина"; // четное
	string b = "Мама купила 3 апельсина";  // нечетное
    string с = "Мама не купила апельсинов";  // нет цифр

	cout << task_using_string(a) << endl;
	cout << task_using_string(b) << endl;
    cout << task_using_string(с) << endl;
	cout << endl;


	return 0;
}


