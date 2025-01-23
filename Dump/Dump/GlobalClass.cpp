#include "Pch.h"
#include "GlobalClass.h"
#include "ThreadManager.h"
#include "Knight.h"

JobManager* gJobManager = nullptr;
ThreadManager* gThreadManager = nullptr;

class GlobalManager
{
public:
	GlobalManager()
	{
		gThreadManager = new ThreadManager();
		gJobManager = new JobManager();
	}
	~GlobalManager()
	{
		delete gJobManager;
		delete gThreadManager;
	}
}gGlobalManager;