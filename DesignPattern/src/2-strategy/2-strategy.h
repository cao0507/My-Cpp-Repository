#ifndef DESIGN_PATTEN_STRATEGY_H
#define DESIGN_PATTEN_STRATEGY_H

#include <string>

class CashSuper{
public:
	virtual ~CashSuper() {}
	virtual double AcceptCash(double) = 0;
};

class CashNormal: public CashSuper{
public:
	double AcceptCash(double);
};

class CashRebate: public CashSuper{
public:
	CashRebate() {}
	CashRebate(double);
	double AcceptCash(double);

private:
	double money_rebate_;
};

class CashReturn: public CashSuper{
public:
	CashReturn() {}
	CashReturn(double, double);
	double AcceptCash(double);

private:
	double money_condition_;
	double money_return_;
};

class CashContext{
public:
	CashContext() {}
	CashContext(std::string, std::string);
	~CashContext();
	double GetResult(double);

private:
	CashSuper* cs_ptr;
};

#endif //DESIGN_PATTEN_STRATEGY_H
