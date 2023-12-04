#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

class Vector {
public:  Vector(int x_, int y_, int z_):x(x_), y(y_), z(z_){}
         Vector(){}

Vector operator + (Vector a) {
    Vector res(this->x + a.getX(), this->y + a.getY(),this->z + a.getZ());
    return res;
}

Vector operator - (Vector a) {
    Vector res(a.getX() - this->x , a.getY() -  this->y,a.getZ() - this->z);
    return res;
}

int operator ^ (Vector a) {
    return (this->x * a.getX() + this->y * a.getY() + this->z * a.getZ());
}

Vector operator * (Vector a) {
    Vector res((this->y * a.getZ()) - (this->z * a.getY()), (this->x * a.getZ()) - (this->z * a.getX()), (this->x * a.getY()) - (this->y * a.getX()));
    return res;
}

bool operator || (Vector a) {
    const double epsilon = 0;
    return fabs(this->x * a.getY() - this->y * a.getX()) == epsilon &&
        fabs(this->y * a.getZ() - this->z * a.getY()) == epsilon &&
        fabs(this->x * a.getZ() - this->z * a.getX()) == epsilon;
}

void setX(int x_){
    x = x_;
}

void setY(int y_) {
    y = y_;
}

void setZ(int z_) {
    z = z_;
}


int getX() {
    return x;
}

int getY() {
    return y;
}

int getZ() {
    return z;
}

void show() {

    cout << x << ' ' << y << ' ' << z << ' ' << endl;
}

private:
    int x = 0, y = 0, z = 0;
};

void write_in_file(Vector a, string name_file = "output.txt") {
    ofstream file(name_file, ios::app);

    if (!file)
    {
        cout << "Нет такого файла" << endl;
        exit(0);
    }

    file << a.getX() << ' ' << a.getY() << ' ' << a.getZ() << '\n';

    file.close();
}

void write_in_file(int a, string name_file = "output.txt") {
    ofstream file(name_file, ios::app);

    if (!file)
    {
        cout << "Нет такого файла" << endl;
        exit(0);
    }

    file << "Скалярное произведение: " << a << '\n';

    file.close();
}

void write_in_file(bool a, string name_file = "output.txt") {
    ofstream file(name_file, ios::app);

    if (!file)
    {
        cout << "Нет такого файла" << endl;
        exit(0);
    }

    file << "Колинеарность векторов: " << (a ? "true" : "false") << '\n';

    file.close();
}


Vector* read_from_file(string name_file) {
    Vector* arr = new Vector[100];

    ifstream file(name_file);

    if (!file)
    {
        cout << "Нет такого файла" << endl;
        exit(0);
    }

    string buf = "";
    int check = 0;
    int n = 0;

    while (file)
    {
        string strInput;
        getline(file, strInput);
        if (strInput == "")
        {
            break;
        }
        for (size_t i = 0; i < strInput.size(); i++)
        {
            if (strInput[i] == ' ')
            {
                switch (check)
                {
                case 0:
                    arr[n].setX(stoi(buf));
                    break;
                case 1:
                    arr[n].setY(stoi(buf));
                    break;
                default:
                    break;
                }

                buf = "";
                check++;
            }
            buf += strInput[i];
        }
        arr[n].setZ(stoi(buf));
        buf = "";
        n++;
        check = 0;
    }

    file.close();

    return arr;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Vector* arr = read_from_file("input.txt");

    Vector a = arr[0];
    Vector b = arr[1];

    a.show();
    b.show();

    write_in_file(a + b);
    write_in_file(a - b);
    write_in_file(a ^ b);
    write_in_file(a * b);
    write_in_file(a || b);

    delete[] arr;

}