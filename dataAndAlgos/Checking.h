#pragma once
#include "account.h"
class Checking :
	public account {
	float m_MinimumBalance;
public:
	using account::account;
	Checking(const std::string& name, float balance, float minbalance);
	~Checking();
	void Withdraw(float amount)override;
	float GetMinimumBalance()const;
};