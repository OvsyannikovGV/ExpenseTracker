#include <nlohmann/json.hpp>
using json = nlohmann::json;

class Expense {
private:
	int id;
	std::string date;
	std::string desc;
	long amount;
public:
	Expense(
		int arg_id,
		std::string arg_date,
		std::string arg_desc,
		long arg_amount
	) :	id(arg_id),
		date(arg_date),
		desc(arg_desc),
		amount(arg_amount)
	{}

	json to_json() const {
		return {
			{"ID", id},
			{"Date", date},
			{"Description", desc},
			{"Amount", amount}
		};
	}
	static Expense from_json(const json& json_expense) {
		return {
			json_expense.at("ID").get<int>(),
			json_expense.at("Date").get<std::string>(),
			json_expense.at("Description").get<std::string>(),
			json_expense.at("Amount").get<long>()
		};
	}
};
