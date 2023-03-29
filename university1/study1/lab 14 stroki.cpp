// lab13.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//



#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

string repeatWords(string str) {
	string word;
	string newmassiv;

	str += ' ';
	bool flg = false;
	for (auto letter : str) {
	
		if (letter != ' ') {
			word += letter;
			cout << "word" << word << "//letter: " << letter << endl;
		}
		else {
			for (int i = 0; i < word.size() ; i++) {
				char tmp;
				cout << "word[i=]" << word[i] << endl;
				tmp = word[i];
				for (int j = 0; j < word.size(); j++) {
					if ((tmp == word[j]) && (i != j)) flg = true;
					
				}
			}
			if (flg)
			newmassiv = newmassiv + word + " ";
			word.clear();
			flg = false;
		}
	}
	return newmassiv;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string str;
	cout << "Введите строку:" << endl;
	getline(cin, str);

	cout << "Введенная строка: " << endl;
	cout << str << endl;
	cout << "Новая строка:" << endl;
	cout << repeatWords(str) << endl;

	system("pause");
	return 0;
}
