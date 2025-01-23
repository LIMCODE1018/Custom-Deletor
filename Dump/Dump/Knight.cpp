#include "Pch.h"
#include "Knight.h"
#include "Macro.h"
int Knight::_IDUtil = 0;

void Knight::Clear()
{
	int _HP = 0;
	int _Attack = 0;
}

void Knight::InfoPrint()
{
	std::osyncstream{ std::cout } << "This ThreadID :" << LThreadID << " // ReCycle Knight... - ID : " << _ID << " // HP : " << _HP << " // Attack : " << _Attack << '\n';
}

void JobManager::Open()
{
	if (LKnight == nullptr)
	{
		LKnight = Pop();
		LKnight->Clear();
	}
}

void JobManager::Push(KnightRef job)
{
	lock_guard<shared_mutex> lg(_SMX);

	_KnightVector.push_back(job);
}

KnightRef JobManager::Pop()
{
	lock_guard<shared_mutex> lg(_SMX);

	if (_KnightVector.empty() == false)
	{
		KnightRef knight = _KnightVector.back();
		_KnightVector.pop_back();

		return knight;
	}

	// 맨 처음 채우기 위한 용도...
	return KnightRef( new Knight(100, 10), RecyclePush);
}

void JobManager::RecyclePush(Knight* rhs)
{
	rhs->_Attack += 20;
	rhs->_HP += 100;

	rhs->InfoPrint();

	gJobManager->Push(KnightRef(rhs, RecyclePush));
}