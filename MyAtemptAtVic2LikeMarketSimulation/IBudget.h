#ifndef IBUDGET_H
#define IBUDGET_H
#include <exception>
#include <string>
#include<sstream>
class IBudget
{

protected:
	double myBudget;

public:

	class BudgetExc : public std::exception
	{
		std::string msg;

	public:
		BudgetExc()
		{
			msg = "Exception inside IBudget interface";
		}

		BudgetExc(double originalAmount, double changedBy, bool isDecrase)
		{
			std::stringstream stream;
			if (isDecrase)
			{
				stream << "Exception inside IBudget interface on Decrase " << originalAmount << " by " << changedBy;
			}
			else
			{
				stream << "Exception inside IBudget interface on Incrase " << originalAmount << " by " << changedBy;
			}
			msg = stream.str();
		}

		const char* what() const noexcept override
		{
			return msg.c_str();
		}
	};

	IBudget(double startCash) :myBudget(startCash)
	{

	}

	void Expense(double ammount)
	{
		if (myBudget - ammount < 0)throw BudgetExc(myBudget, ammount, true);
		myBudget -= ammount;
	}
	void Income(double ammount)
	{
		myBudget += ammount;
	}
	double GetBudget()const
	{
		return myBudget;
	}
};


#endif