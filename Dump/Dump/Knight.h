#pragma once
#include <mutex>

class Knight
{
public:
	Knight() :
		_HP(0), _Attack(0)
	{

	}
	Knight(int hp, int attack) :
		_HP(hp), _Attack(attack)
	{
		_IDUtil++;
		_ID = _IDUtil;
	}
	~Knight()
	{
		cout << "Kngiht auf!!!!...." << endl;
	}

public:
	void Clear();
	void InfoPrint();

public:
	int _HP;
	int _Attack;
	int _ID;
	static int _IDUtil;
};

class JobManager
{
public:
	JobManager()
	{
		_KnightVector.clear();
		_KnightVector.reserve(10);
	}
	void Open();
	void Push(KnightRef job);
	KnightRef Pop();

	static void RecyclePush(Knight* rhs);

public:
	shared_mutex _SMX;
	vector<KnightRef> _KnightVector;

	int32 Test2 = 0;
};