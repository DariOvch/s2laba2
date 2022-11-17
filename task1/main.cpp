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




int main()
{
	KEEPER cnt;

	printf("main menu\n");
	printf("exit %d\n", EXIT);
	printf("clear %d\n", CLEAR);
	printf("see all %d\n", SEEALL);

	printf("add %d\n", ADD);
	printf("delete %d\n", DEL);
	printf("SEARCH_DEST %d\n", SEARCH_DEST);
	printf("SEARCH_TRAIN %d\n", SEARCH_NUM);



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
		{
			system("cls");
			printf("menu\n");
			printf("exit %d\n", EXIT);
			printf("clear %d\n", CLEAR);
			printf("see all %d\n", SEEALL);

			printf("add %d\n", ADD);
			printf("edit %d\n", EDIT);
			printf("delete %d\n", DEL);

		}
		break;

		case SEEALL:
			cnt.seeall();
			break;


		case ADD:
			try
			{
				cnt.add();
			}
			catch (char* m)
			{
				printf("%s\n", m);
			};
			
			break;

		case EDIT:
			cnt.edit();
			break;

		case DEL:
			cnt.delet();
			break;

		case SEARCH_DEST:
			break;

		case SEARCH_NUM:

			break;

		default:
			printf("unknown\n");
			break;

		}
	}

	return 0;
}