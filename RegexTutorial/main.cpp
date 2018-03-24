/*
Basic project for learning how to use regular expressions in C++11
*/
#include<iostream>
#include<regex>
#include<string>
#include<fstream>

// For Numbers like 42
void IntegerValidation() {

	std::string Input;

	// A digit is identified with [:digit:] or with [:d:]
	// This will match any input from 0 to 9.
	std::regex SingleDigit("[[:digit:]]");
	
	// To match a number larger than one digit, use the plus sign (+) at the end.
	std::regex StringOfDigits("[[:digit:]]+");

	// To match signed numbers (-x or +x), use "-?" in front of the regular expression to verify if the first position in the input is minus (-) or not.
	std::regex SignedStringOfDigits("-?[[:digit:]]+");

	// To inform the compiler to treat plus as the character "+" and not as a repetition operator, we need to escape "+"
	std::regex EscapingPlusSign("\\+?[[:digit:]]+");

	// Combining every expression so far. Use the or operator "|" and parentheses to combine the "+" and "-" operator.
	std::regex Integer("(\\+|-)?[[:digit:]]+");

	while (true) {
		std::cout << "Input Integer: ";
		std::cin >> Input;

		if (!std::cin) {
			throw std::invalid_argument("Input of invalid type");
		}
		else if (Input=="q") {
			// Quit
			break;
		}
		else if (std::regex_match(Input, Integer)) {
			std::cout << "Success!\n";
		}
		else {
			std::cout << "Failure!\n";
		}
	}
}

// For numbers like 42.42
void RealNumberValidation() {

	std::string Input;

	// Fractional part is optional -> use (([[:digit:]]+)?)
	// Decimal separator is optional -> use (\\.?)
	std::regex RealNumber("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?");

	while (true) {
		std::cout << "Input Real Number: ";
		std::cin >> Input;

		if (!std::cin) {
			throw std::invalid_argument("Input of invalid type");
		}
		else if (Input == "q") {
			// Quit
			break;
		}
		else if (std::regex_match(Input, RealNumber)) {
			std::cout << "Success!\n";
		}
		else {
			std::cout << "Failure!\n";
		}
	}
}

// For number like -1.23e+06
void ScientificFormatNumberValidation() {
	
	std::string Input;

	// Fractional part is optional -> use ([[:digit:]]+)?
	// Decimal separator is optional -> use (\\.?)
	// Exponential part is optional -> use ((e|E)?)
	// Sign of the exponential part is optional -> ((\\+|-)?)
	std::regex ScientificFormatNumber("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?((e|E)((\\+|-)?)[[:digit:]]+)?");

	while (true) {
		std::cout << "Input Scientific Format Number: ";
		std::cin >> Input;

		if (!std::cin) {
			throw std::invalid_argument("Input of invalid type");
		}
		else if (Input == "q") {
			// Quit
			break;
		}
		else if (std::regex_match(Input, ScientificFormatNumber)) {
			std::cout << "Success!\n";
		}
		else {
			std::cout << "Failure!\n";
		}
	}
}

void WordAndNumberExtractor() {

	// This should match any number
	std::regex Number("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?((e|E)((\\+|-)?)[[:digit:]]+)?");

	// This should match any number
	std::regex Word("[[:alpha:]]+");

	std::string Input, CleanNumbers, CleanWords;

	const std::string Format = "";
	std::getline(std::cin, Input);

	// Split the input string in numbers and words
	CleanNumbers = std::regex_replace(Input, Number, Format, std::regex_constants::format_default);
	CleanWords = std::regex_replace(Input, Word, Format, std::regex_constants::format_default);

	// Print results
	std::cout << CleanNumbers << std::endl;
	std::cout << CleanWords << std::endl;
}

int main() {

	std::cout << "\n**IntegerValidation**\n";
	IntegerValidation();
	
	std::cout << "\n**RealNumberValidation**\n";
	RealNumberValidation();

	std::cout << "\n**ScientificFormatNumberValidation**\n";
	ScientificFormatNumberValidation();
	
	std::cout << "\n**WordAndNumberExtractor**\n";
	WordAndNumberExtractor();

	return 0;
}