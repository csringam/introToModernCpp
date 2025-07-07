#pragma once
#include <string>
class account {
	std::string m_Name;
	int m_AccNo;
	static int s_ANGenerator;
protected:
	float m_Balance;
public:
	account(const std::string& name, float balance);
	virtual ~account();
	const std::string GetName()const;
	float GetBalance()const;
	int GetAccountNo()const;

	virtual void AccumulateInterest();
	virtual void Withdraw(float amount);
	void Deposit(float amount);
	virtual float GetInterestRate()const;
};
