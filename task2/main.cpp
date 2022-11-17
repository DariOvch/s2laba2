#include "stdio.h"
#include "fstream"
#include "iostream"
#include <string>
/*
 Файловые и строковые потоки
С использованием файловых и строковых потоков написать программу,
которая считывает текст из файла и выводит на экран только цитаты, то есть
предложения, заключенные в кавычки
*/

using namespace std;

int main()
{
	ifstream in;
	in.open("file.txt");
	if (!in.is_open())
	{
		cout << "file not found, exiting programm" << endl;
		return 0;
	}

	char c;
	int metPairFlag = 1;

	while (!in.eof())
	{
		in.get(c);

		if (c == '\'')
		{
			metPairFlag = 0;
			in.get(c);
			while (c != '\'' && !in.eof())
			{
				cout << c;			
				in.get(c);
				if (c == '\'')
					metPairFlag = 1;
			}	
			in.get(c);
			cout << endl;
		}

		if (c == '\"')
		{
			metPairFlag = 0;
			in.get(c);
			while (c != '\"' && !in.eof())
			{
				cout << c;
				in.get(c);
				if (c == '\"')
					metPairFlag = 1;
			}
			in.get(c);
			cout << endl;
		}
		
	}

	in.close();
	if (metPairFlag == 0)
		cout <<endl<< "\tATTENTION: second quotation mark was not met!"<<endl;


}