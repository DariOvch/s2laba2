#include "KEEPER.h"
#include "io.h"


void KEEPER::add()
{

	TRAIN* item = new TRAIN;
	TRAIN** new_arr = new TRAIN * [size + 1];

	if (new_arr == nullptr)
		throw "memory allocation error";


	for (int i = 0; i < size; i++)
	{
		new_arr[i] = arr[i];
	}

	new_arr[size] = item;
	delete arr; 
	arr = new_arr;

	size++;

	sorting();
}

void KEEPER::seeall()
{
	if (size == 0)
		cout << "empty" << endl;
	else
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << endl;
		}
	}
}

void KEEPER::edit()
{
	int in = 0;
	while (true)
	{
		cout << "there are " << size << " items added" << endl;
		printf("-1 back\n1 choose number to edit\n");
		scan("%d", &in);

		switch (in)
		{
		case -1:
			return;

		case 1:
		{
			int num = -1;
			cout << "input number of item to edit: ";
			while (num < 1 || num > size)
				scan("%d", &in);
			cout << "input new field values:" << endl;
			cin >> *arr[num - 1];
			sorting();
		}

		break;

		default:
			printf("unknown\n");
		}
	}
}

void KEEPER::delet()
{
	if (size == 0)
		printf("empty\n");
	else
	{
		cout << "there are " << size << " items added" << endl;
		int num = -1;
		
		while (num < 1 || num > size)
		{
			cout << "input number of item to delete: " << endl;
			scan("%d", &num);
		}


		size--;
		for (int i = num - 1; i < size; i++)
			arr[i] = arr[i + 1];

		sorting();
	}
	
}

void KEEPER::sorting()
{
	if (size == 0)
		printf("empty\n");
	else
	{
		for (int i = 0; i < size-1; i++)
		{
			if (arr[i]->getDeparture() > arr[i+1]->getDeparture())
			{
				TRAIN* temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				i = 0;
			}

		}
	}
}
