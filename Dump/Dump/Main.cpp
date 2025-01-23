#include "Pch.h"

void Func()
{
	while (true)
	{
		this_thread::sleep_for(2s);
		
		KnightRef knight = gJobManager->Pop();
	}
}

class UItem
{
public:
	UItem() { _Numbers = 10; };
	UItem(int32 number)
	{
		_Numbers = number;
	}

	void Print()
	{
		cout << _Numbers << endl;
	}

public:
	int32 _Numbers;
};

int main()
{
	 int32 CPUCount = thread::hardware_concurrency() / 4;
	
	 for (int i = 0; i < 3; ++i)
	 {
	 	gThreadManager->Launch([=]()
	 		{
	 			Func();
	 		});
	 }
	
	 while (true)
	 {
	
	 }
}