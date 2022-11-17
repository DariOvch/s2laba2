#include <iostream>
#include "KEEPER.h"

/*
1. Стандартные потоки
Определить класс с именем TRAIN, содержащий следующие поля:
● название пункта назначения;
● номер поезда;
● время отправления.
Определить методы доступа к этим полям и перегруженные операции
извлечения и вставки для объектов типа TRAIN.
Заранее число объектов не известно.
Написать программу, выполняющую следующие действия:
● записи должны быть упорядочены по времени отправления поезда;
● вывод на экран информации о поездах, направляющихся в пункт,
название которого введено с клавиатуры;
● если таких поездов нет, выдать на дисплей соответствующее
сообщение.
*/

#define EXIT -1
#define CLEAR 0
#define SEEALL 1
#define ADD 2
#define DEL 3
#define EDIT 4
#define SEARCH_DEST 5
#define SEARCH_NUM 6
#define SEARCH_TIME 7


void msg()
{
	system("cls");
	printf("menu\n");
	printf("%d exit\n", EXIT);
	printf("%d clear\n", CLEAR);
	printf("%d see all\n", SEEALL);

	printf("%d add\n", ADD);
	printf("%d edit\n", EDIT);
	printf("%d delete\n", DEL);
	printf("%d search by destination\n", SEARCH_DEST);
	printf("%d search by train\n", SEARCH_NUM);
	printf("%d search by time\n", SEARCH_TIME);


}

int main()
{
	KEEPER cnt;
	msg();



	int t = 0;
	while (true)
	{
		printf("\nmain menu\n");
		scan("%d", &t);
		switch (t)
		{

		case EXIT:
			return 0;

		case CLEAR:
			msg();
			break;

		case SEEALL:
			try {
				cnt.seeall();
			}
			catch (int e) {
				if (e == -1)
					cout << "EXEPTION: no item added" << endl;
			}
			break;


		case ADD:
			try	{
				cnt.add();
			}
			catch (char* m)	{
				printf("%s\n", m);
			};
			
			break;

		case EDIT:
			try {
				cnt.edit();
			}
			catch (int e) {
				if (e == -1)
					cout << "EXEPTION: no item added" << endl;
			}
			break;

		case DEL:
			try {
				cnt.delet();
			}
			catch (int e) {
				if (e == -1)
					cout << "EXEPTION: no item added" << endl;
			}
			break;

		case SEARCH_DEST:
			try {
				cnt.seeWithDestination();
			}
			catch (int e) {
				if (e == -1)
					cout << "EXEPTION: no item added" << endl;
			}
			
			break;

		case SEARCH_NUM:
			try {
				cnt.seeWithNumber();
			}
			catch (int e) {
				if (e == -1)
					cout << "EXEPTION: no item added" << endl;
			}
			
			break;

		case SEARCH_TIME:
			try {
				cnt.seeWithTime();
			}
			catch (int e) {
				if (e == -1)
					cout << "EXEPTION: no item added" << endl;
			}
			
			break;

		default:

			printf("unknown\n");
			break;

		}
	}

	return 0;
}