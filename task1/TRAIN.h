#include "stdio.h"
#include "iostream"
#include <string>
#include "io.h"

using namespace std;

class TIME
{
	int hour;
	int min;

	bool isCorrect()
	{
		if (hour < 0 || hour > 24)
			return false;
		if (min < 0 || min > 59)
			return false;
		return true;
	}

	void setDefault()
	{
		hour = 0; min = 0;
		printf("default time set\n");
	}
	
public:

	int getHour()
	{
		return hour;
	}

	int getMin()
	{
		return min;
	}

	void set(int h, int m)
	{
		hour = h;
		min = m;
		if (!isCorrect())
		{
			printf("invalid time set\n");
			setDefault();
		}
	}

	friend std::ostream& operator<<(std::ostream& out, const TIME& ptr)
	{ 
		(ptr.hour < 10) ? (out << "0" << ptr.hour) : (out << ptr.hour);
		out << ":";
		(ptr.min < 10) ? (out << "0" << ptr.min) : (out << ptr.min);

		return out<<endl;
	}


	friend std::istream& operator>>(std::istream& in, TIME& time)
	{
		int h = -1;
		int m = -1;
		while (h < 0 || h > 23)
		{
			std::cout << "hour: ";
			scan("%d", &h);
		}

		while (m < 0 || m > 59)
		{
			std::cout << "hour: ";
			scan("%d", &m);
		}

		return in;
	}


	bool operator>(TIME& p2)
	{
		if (this->hour * 100 + this->min > p2.getHour() * 100 + p2.getMin())
		{
			return true;
		}
		return false;
	}
};

class TRAIN
{
	string destination;
	string number;
	TIME departure;

public:

	TRAIN()
	{
		cout << "called TRAIN constructor" << endl;
		destination = "unknown";
		number = "unknown";
		departure.set(12,0);
	}

	~TRAIN()
	{
		cout << "called TRAIN destructor" << endl;
	}

	friend std::istream& operator>>(std::istream& in, TRAIN& train)
	{
		std::cout << "destitation: ";
		getline(in, train.destination);

		std::cout << "number: ";
		in.clear();
		getline(in, train.number);

		std::cout << "time: ";
		in.clear();
		in >> train.departure;
		in.sync();
		return in;
	}



	friend std::ostream& operator<<(std::ostream& out, const TRAIN& train)
	{
		out << "train number " << train.number << " to " << train.destination << " departs at " << train.departure << endl;
		return out;
	}

	TIME* getDeparture()
	{
		return &departure;
	}

	string getDestination()
	{
		return destination;
	}

	string getNumber()
	{
		return number;
	}

};