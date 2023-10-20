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


string revers_string(string str) {
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


// __________________________________________________________________________

// Работа дял cstring
char* reverse(const char* str) {
    int length = strlen(str);
    char* reversedStr = new char[length + 1]; // +1 для нулевого символа

    int wordEnd = length - 1;  // Индекс конца текущего слова
    int reversedIndex = 0;    // Индекс, куда будем записывать обратное слово

    // Обходим строку справа налево
    for (int i = length - 1; i >= 0; i--) {
        if (str[i] == ' ' || i == 0) {
            // Если найден разделитель или достигнут конец строки, скопируем слово в обратном порядке
            int wordStart = (i == 0) ? 0 : i + 1;

            for (int j = wordStart; j <= wordEnd; j++) {
                reversedStr[reversedIndex++] = str[j];
            }

            if (i > 0) {
                // Если это не конец строки, добавим пробел после слова
                reversedStr[reversedIndex++] = ' ';
            }

            // Установим индекс конца текущего слова
            wordEnd = i - 1;
        }
    }

    reversedStr[reversedIndex] = '\0'; // Завершаем строку нулевым символом

    return reversedStr;
}

// Освобождение памяти для перевернутой строки
void free_cstring(const char* str) {
    delete[] str;
}

const char* revers_cstring(const char* input) {
    int index = -1;
    if (strlen(input) % 2 == 1)
    {
        for (size_t i = 0; i < strlen(input); i++)
        {
            if (isdigit(input[i]))
            {
                index = i;
                break;
            }
        }

        if (index == -1) {
            return "В строке нет чисел";
        }

        const char* substr = input + index;

        return reverse(substr);
    }

    else {
        return "Строка имеет четное количество символов";
    }
}

int main()
{
	setlocale(LC_ALL, "Russian");

	string a = "Мама купила 33 апельсина"; // четное
	string b = "Мама купила 3 апельсина";  // нечетное
    string c = "Мама не купила апельсинов";  // нет чисел 

    cout << "Реализация дял string" << endl;
    cout << revers_string(a) << endl;
	cout << revers_string(b) << endl;
    cout << revers_string(c) << endl;
	cout << endl;

    const char* ca = "Мама купила 33 апельсина"; // четное
    const char* cb = "Мама купила 3 апельсина";  // нечетное
    const char* cc = "Мама не купила апельсинов";  // нет чисел


    cout << "Реализация дял cstring" << endl;
    cout << revers_cstring(ca) << endl;
    cout << revers_cstring(cb) << endl;
    cout << revers_cstring(cc) << endl;
    cout << endl;

	return 0;
}


