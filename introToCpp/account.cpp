#include "account.h"
#include <iostream>
int account::s_ANGenerator = 1000;
account::account(const std::string& name, float balance) :
	m_Name(name), m_Balance(balance) {
	m_AccNo = ++s_ANGenerator;
	//std::cout << "Account(const std::string &, float)" << std::endl; 
}


account::~account() {
	//std::cout << "~Account()" << std::endl;

}

const std::string account::GetName() const {
	return m_Name;
}

float account::GetBalance() const {
	return m_Balance;
}

int account::GetAccountNo() const {
	return m_AccNo;
}

void account::AccumulateInterest() {
}

void account::Withdraw(float amount) {
	/*
	Balance should be greater than 0 & the amount
	to withdraw should be less than balance
	*/
	if (amount < m_Balance && m_Balance > 0)
		m_Balance -= amount;
	else {
		//Throw an exception instead of printing a message
		//std::cout << "Insufficient balance" << std::endl;
		throw std::runtime_error("Insufficient balance");
	}
}

void account::Deposit(float amount) {
	m_Balance += amount;
}

float account::GetInterestRate() const {
	return 0.0f;
}
