#include <iostream>
#include <ExpenseTracker/expense.hpp>

int main () {
	Expense exp1(1, "2025-07-10", "Test description", 2000);
	std::cout << exp1.to_json().dump(4) << std::endl;
	return 0;
}
