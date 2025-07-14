#include <iostream>
#include <getopt.h>
#include <vector>
#include <fstream>
#include <ExpenseTracker/expense.hpp>

const std::string data_file_path = DATA_FILE_PATH;

bool non_empty_file_exists(const std::string& filename) {
    std::ifstream f(filename, std::ios::ate);
    if (!f.good()) {
        std::ofstream file(filename);
        // file is automatically closed when ofstream goes out of scope
        return false;
    }
    return f.tellg() != 0;
}

std::vector<Expense> load_from_json(const std::string& filename) {
    std::vector<Expense> expenses;
    if (!non_empty_file_exists(filename)) {
        return expenses;
    }
    std::ifstream file(filename);
    json json_expenses;
    file >> json_expenses; //  probably need to add exception handling

    for (const auto& item : json_expenses) {
        expenses.push_back(Expense::from_json(item));
    }

    return expenses;
}

void save_to_json(const std::vector<Expense>& expenses, const std::string& filename) {
    json json_expenses;
    for (const auto& item : expenses) {
        json_expenses.push_back(item.to_json());
    }

    std::ofstream file(filename);
    file << json_expenses.dump(4); // 4 spaces for pretty printing
}

int main () {
    std::vector<Expense> expenses = load_from_json(data_file_path);
    
	Expense exp1(1, "2025-07-10", "Test description1", 2000);
    Expense exp2(2, "2025-07-10", "Test description2", 3000);

    json json_expenses;
    for (const auto& item : expenses) {
        json_expenses.push_back(item.to_json());
    }
    std::cout << json_expenses.dump(4) << std::endl; // 4 spaces for pretty printing

    save_to_json(expenses, data_file_path);

	std::cout << exp1.to_json().dump(4) << std::endl << exp2.to_json().dump(4) << std::endl;
	return 0;
}
