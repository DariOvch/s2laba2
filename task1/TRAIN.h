#include "stdio.h"
#include "iostream"

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

};

class TRAIN
{


};