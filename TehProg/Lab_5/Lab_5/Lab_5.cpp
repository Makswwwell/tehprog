#include <iostream>
#include <windows.h>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

class Square {
protected:
    double side = 0;

public:
    Square(double side_) : side(side_) {}
    Square() {}

    void setSide(double side_) {
        side = side_;
    }

    double getSide() const {
        return side;
    }

    double getPerimeter() const {
        return 4 * side;
    }

    virtual double getArea() const {
        return side * side;
    }

    virtual double getDiagonal() const {
        return sqrt(2) * side;
    }

    void printInfoSquare() const {
        cout << "Информация о квадрате:" << endl;
        cout << "Длина стороны: " << side << endl;
        cout << "Периметр: " << getPerimeter() << endl;
        cout << "Площадь: " << getArea() << endl;
        cout << "Диагональ: " << getDiagonal() << endl;
    }
};

class Cube : public Square {
public:
    Cube(double s) : Square(s) {}
    Cube(){}

    double getVolume() const {
        return side * side * side;
    }

    double getArea() const override {
        return 6 * (Square::getArea()); 
    }

    double getDiagonal() const override {
        return sqrt(pow((Square::getDiagonal()),2) + pow(side, 2));
    }

    void printInfoCube() const {
        cout << "Информация о кубе:" << endl;
        cout << "Длина стороны: " << side << endl;
        cout << "Длина диагонали: " << getDiagonal() << endl;
        cout << "Площадь поверхности: " << getArea() << endl;
        cout << "Объем: " << getVolume() << endl;
    }
};


int countLinesInFile(string name_file = "input.txt") {
    ifstream file(name_file);
    if (!file) {
        cout << "Нет такого файла" << endl;
        exit(0);
    }

    int lineCount = 0;
    string line;
    while (getline(file, line)) {
        lineCount++;
    }

    file.close();

    return lineCount;
}


Square* read_from_fileSquare(string name_file = "input.txt") {
    ifstream file(name_file);
    if (!file) {
        cout << "Нет такого файла" << endl;
        exit(0);
    }

    Square* arr = new Square[countLinesInFile()];
    double side;
    int n = 0;

    while (file >> side) {
        arr[n].setSide(side);
        n++;
    }

    file.close();

    return arr;
}

Cube* read_from_fileCube(string name_file = "input.txt") {
    ifstream file(name_file);
    if (!file) {
        cout << "Нет такого файла" << endl;
        exit(0);
    }

    Cube* arr = new Cube[countLinesInFile()];
    double side;
    int n = 0;

    while (file >> side) {
        arr[n].setSide(side);
        n++;
    }

    file.close();

    return arr;
}

void write_in_file(Square a, string name_file = "output.txt") {
    ofstream file(name_file, ios::app);

    if (!file)
    {
        cout << "Нет такого файла" << endl;
        exit(0);
    }

   
    file << "Информация о квадрате:" << endl;
    file << "Длина стороны: " << a.getSide() << endl;
    file << "Периметр: " << a.getPerimeter() << endl;
    file << "Площадь: " << a.getArea() << endl;
    file << "Диагональ: " << a.getDiagonal() << endl;
    file << endl;

    file.close();
}
void write_in_file(Cube a, string name_file = "output.txt") {
    ofstream file(name_file, ios::app);

    if (!file)
    {
        cout << "Нет такого файла" << endl;
        exit(0);
    }


    file << "Информация о кубе:" << endl;
    file << "Длина стороны: " << a.getSide() << endl;
    file << "Длина диагонали: " << a.getDiagonal() << endl;
    file << "Площадь поверхности: " << a.getArea() << endl;
    file << "Объем: " << a.getVolume() << endl;
    file << endl;

    file.close();
}

double avarege_area(Square* arr) {
    double area = 0;
    for (size_t i = 0; i < countLinesInFile(); i++)
    {
        area += arr[i].getArea();
    }

    return area / countLinesInFile();
}

int count_max_volume_cubs(Cube* arr) {
    int counter = 0;
    double max_volume = -1;
    for (size_t i = 0; i < countLinesInFile(); i++)
    {
        if (max_volume < arr[i].getVolume())
        {
            max_volume = arr[i].getVolume();
        }
    }
    for (size_t i = 0; i < countLinesInFile(); i++)
    {
        if (arr[i].getVolume() == max_volume)
        {
            counter++;
        }
    }

    return counter;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Square* arrSquare = read_from_fileSquare();
    Cube* arrCube = read_from_fileCube();

    for (size_t i = 0; i < countLinesInFile(); i++)
    {
        arrSquare[i].printInfoSquare();
        write_in_file(arrSquare[i]);
        cout << endl;
        arrCube[i].printInfoCube();
        write_in_file(arrCube[i]);
        cout << endl;
    }
        
    cout << "Средняя площадь квабратов: " << avarege_area(arrSquare) << endl;
    cout << "Количество кубов с максимальной площади: " << count_max_volume_cubs(arrCube) << endl;

    delete[] arrSquare, arrCube;
    return 0;
}
