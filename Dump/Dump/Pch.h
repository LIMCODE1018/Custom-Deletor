#pragma once

#include "Macro.h"
#include "GlobalClass.h"
#include "TLS.h"

#include <iostream>
#include <windows.h>

#include <thread>
#include <mutex>
#include <atomic>
#include <shared_mutex>

#include <vector>
#include <stack>
#include <array>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <unordered_map>
#include <unordered_set>

#include <string>
#include <math.h>
#include <algorithm>
#include <chrono>
#include <random>
#include <functional>

#include <utility>
#include <assert.h>

#include <syncstream>

using namespace std;
using namespace chrono;

#include "ThreadManager.h"
#include "Knight.h"

#define CRASH(cause)						\
{											\
	INT32* crash = nullptr;					\
	__analysis_assume(crash != nullptr);	\
	*crash = 0xDEADBEEF;					\
}

#define ASSERT_CRASH(expr)			\
{									\
	if (!(expr))					\
	{								\
		CRASH("ASSERT_CRASH");		\
		__analysis_assume(expr);	\
	}								\
}