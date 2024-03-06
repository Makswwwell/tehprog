#include <iostream>
#include <fstream>
#include <algorithm> 
#include <string>  
#include <windows.h>  

using namespace std;

void copy_no_a_lines() {

	ifstream inf1("T1.txt");
	ofstream inf2("T2.txt");

	
	if (!inf1)
	{
		cerr << "Нет такого файла" << endl;
		exit(0);
	}

	if (!inf2)
	{
		cerr << "Нет такого файла" << endl;
		exit(0);
	}


	while (inf1)
	{
		string strInput;
		getline(inf1, strInput);
		if (strInput.find('a') == string::npos)
		{
			inf2 << strInput + "\n";
			cout << strInput;
		}
	}

	inf1.close();
	inf2.close();

}

void numder_of_vowels() {

	ifstream inf1("T1.txt");


	if (!inf1)
	{
		cerr << "Нет такого файла" << endl;
		exit(0);
	}


	string vowels = "AEIOUYaeiouy";
	int num1 = 0;
	int num2 = 0;
	int number_of_line = 0;

	while (inf1)
	{
		string strInput;
		getline(inf1, strInput);
		num1 = 0;
		for (size_t i = 0; i < strInput.size(); i++)
		{
			for (size_t j = 0; j < vowels.size(); j++)
			{
				if (strInput[i] == vowels[j])
				{
					num1++;
				}
			}
			
		}


		if (num2 <= num1)
		{
			num2 = num1;
			number_of_line++;
		}
		
	}

	std::cout << number_of_line;

	inf1.close();
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	copy_no_a_lines();
	numder_of_vowels();
}

