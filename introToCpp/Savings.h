#pragma once
#include "account.h"
class Savings :
	public account {
	float m_Rate;
public:
	Savings(const std::string& name, float balance, float rate);
	~Savings();
	float GetInterestRate()const override;
	void AccumulateInterest() override;
};