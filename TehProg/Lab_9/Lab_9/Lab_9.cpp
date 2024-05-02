#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <windows.h>

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::stack<float> stack_1;
    std::vector<float> myVector;

    for (float i = 1.0f; i <= 5.0f; ++i) {
        stack_1.push(i); 
        myVector.push_back(i); 
    }


    std::cout << "Элементы стека:";
    while (!stack_1.empty()) {
        std::cout << ' ' << stack_1.top();
        stack_1.pop(); 
    }
    std::cout << std::endl;

    std::cout << "Элементы вектора:";
    for (auto& element : myVector) {
        std::cout << ' ' << element;
    }
    std::cout << std::endl;

    std::vector<float> vector_2;
    for (float i = 6.0f; i <= 10.0f; ++i) {
        vector_2.push_back(i);
    }


    int p = 2; 
    auto iterator = myVector.begin() + p; 
    myVector.erase(iterator, iterator + 2); 
    std::cout << "Измененные элементы вектора после удаления:";
    for (auto& element : myVector) {
        std::cout << ' ' << element;
    }
    std::cout << std::endl;

    myVector.insert(myVector.end(), vector_2.begin(), vector_2.end());
    std::cout << "Измененные элементы вектора после добавления:";
    for (auto& element : myVector) {
        std::cout << ' ' << element;
    }
    std::cout << std::endl;

    return 0;
}
