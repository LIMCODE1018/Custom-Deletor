#include "Pch.h"
#include "ThreadManager.h"


ThreadManager::ThreadManager()
{
	InitTLS();
}

ThreadManager::~ThreadManager()
{
}

void ThreadManager::Launch(function<void(void)> callback)
{
	lock_guard guard(_Lock);

	_ThreadVector.push_back(jthread([=]()
		{
			InitTLS();
			callback();
		}));

}

void ThreadManager::InitTLS()
{
	static atomic<uint32> SThreadId = 0;
	LThreadID = SThreadId.fetch_add(1);
}

void ThreadManager::DestroyTLS()
{

}