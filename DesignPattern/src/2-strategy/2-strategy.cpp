#include "2-strategy.h"
#include <iostream>
#include <sstream>

//class CashNormal
double CashNormal::AcceptCash(double money) {
	return money;
}

//class CashRebate
CashRebate::CashRebate(double money_rebate): money_rebate_(money_rebate) {}

double CashRebate::AcceptCash(double money){
	return money * money_rebate_;
}

//class CashReturn
CashReturn::CashReturn(double money_condition, double money_return):
	money_condition_(money_condition),
	money_return_(money_return)
	{}

double CashReturn::AcceptCash(double money){
	return money - (int)(money/money_condition_) * money_return_;
}

//class CashContext
CashContext::CashContext(std::string type, std::string number) {
	if (type == "normal") {
		cs_ptr = new CashNormal();
	}
	else if (type == "rebate") {
		double money_rebate;
		std::stringstream ss;
		ss << number;
		ss >> money_rebate;
		cs_ptr = new CashRebate(money_rebate);
	}
	else if (type == "return") {
		double money_condition, money_return;
		std::stringstream ss;
		ss << number;
		ss >> money_condition >> money_return;
		cs_ptr = new CashReturn(money_condition, money_return);
	}
}

CashContext::~CashContext() {
	delete cs_ptr;
}

double CashContext::GetResult(double money) {
	double result = cs_ptr->AcceptCash(money);
	std::cout << result << std::endl;
	return result;
}
