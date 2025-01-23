#pragma once
#include "Pch.h"

// multithread 소수구하기
	//INT64 PrimeNumber; cin >> PrimeNumber;
	//INT32 iCount = thread::hardware_concurrency();
	//for (INT32 i = 0; i < 4; ++i)
	//{
	//	ThreadManager.push_back(thread([=]()
	//		{Prime(PrimeNumber / i, PrimeNumber / (i + 1)); }
	//	));
	//}
	//for (thread& n : ThreadManager)
	//{
	//	if (n.joinable())
	//		n.join();
	//}
	//ThreadManager.clear();
	//Prime(1, PrimeNumber);
	//cout << Count.load() << endl;


mt19937 gen;
uniform_int_distribution<int> dist(1, 9);

atomic<INT32> Count;
void __stdcall Prime(INT32 start, INT32 end)
{
	// 에라토스테네스
	vector<bool> arr(end + 1);

	arr[0] = arr[1] = true; // 1은 소수가 아니므로 true

	for (int i = 2; i <= sqrt(end); i++) {
		if (arr[i]) continue; // 이미 체크 됐으면 continue;
		for (int j = i + i; j <= end; j += i) // i를 제외한 i의 배수들은 소수가 아니다.
			arr[j] = true;
	}

	for (auto n : arr)
	{
		if (n == false)
			Count.fetch_add(1);
	}
}