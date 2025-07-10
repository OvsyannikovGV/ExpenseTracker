#include <iostream>
#include <chrono>
#include <ExpenseTracker/expense.hpp>

int main () {
	Expense exp1(1, {2025y / July / 1d}, "Test description", 2000);
	std::cout << exp1.to_json().dump(4) << std::endl;
	return 0;
}
