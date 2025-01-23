#pragma once


class ThreadManager
{
public:
	ThreadManager();
	~ThreadManager();

	void	Launch(function<void(void)> callback);

	static void InitTLS();
	static void DestroyTLS();

private:
	mutex					_Lock;
	vector<jthread>			_ThreadVector;
};