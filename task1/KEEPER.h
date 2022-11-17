#include "TRAIN.h"

class KEEPER
{
	TRAIN** arr;
	int size;

public:
	KEEPER(){
		printf("keeper created\n");
		size = 0;
		arr = nullptr;
	}

	~KEEPER() {
		for (int i = 0; i < size; i++)
			delete arr[i];
		printf("keeper deleted\n");
	}

	void add();
	void edit();
	void delet();
	void sorting();
	void seeall();

	void seeWithDestination()
	{
		string dest;
		cout << "input destination name: ";
		cin >> dest;

		cout << "search for " << dest << endl;
		int count = 0;
		for (int i = 0; i < size; i++)
		{
			if (arr[i]->getDestination() == dest)
				count++;
		}
		if (count == 0)
			cout << "no items found!" << endl;
		else
			cout << "found: "<< count << "items" <<endl;

		for (int i = 0; i < size; i++)
		{
			if (arr[i]->getDestination() == dest)
				cout << arr[i]->getDestination() << endl;
		}
	}


};
