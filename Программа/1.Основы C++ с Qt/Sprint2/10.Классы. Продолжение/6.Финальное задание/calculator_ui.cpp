#include "calculator_ui.h"

#include <string>

using namespace std::literals;

CalculatorUI::CalculatorUI(Calculator& calc, std::ostream& out, std::ostream& err)
    : calc_(calc)
    , out_(out)
    , err_(err)
{}

bool CalculatorUI::Parse(std::istream& input) const {
    Number operand;
    if (!ReadNumber(input, operand)) {
        return false;
    }
    calc_.Set(operand);

    std::string token;
    while (input >> token) {
        Number right;
        if (token == "+"s) {
            if (!ReadNumber(input, right)) {
                return false;
            }
            calc_.Add(right);
        } else if (token == "-"s) {
            if (!ReadNumber(input, right)) {
                return false;
            }
            calc_.Sub(right);
        } else if (token == "*"s) {
            if (!ReadNumber(input, right)) {
                return false;
            }
            calc_.Mul(right);
        } else if (token == "/"s) {
            if (!ReadNumber(input, right)) {
                return false;
            }
            calc_.Div(right);
        } else if (token == "**"s) {
            if (!ReadNumber(input, right)) {
                return false;
            }
            calc_.Pow(right);
        } else if (token == "s"s) {
            calc_.Save();
        } else if (token == "l"s) {
            if (!calc_.HasMem()) {
                err_ << "Error: Memory is empty"s << std::endl;
                return false;
            }
            calc_.Load();
        } else if (token == "="s) {
            out_ << calc_.GetNumberRepr() << std::endl;
        } else if (token == "c"s) {
            calc_.Set(0);
        } else if (token == "n"s) {
            calc_.Set(-calc_.GetNumber());
        } else if (token == ":"s) {
            if (!ReadNumber(input, right)) {
                return false;
            }
            calc_.Set(right);
        } else if (token == "q"s) {
            return true;
        } else {
            err_ << "Error: Unknown token "s << token << std::endl;
            return false;
        }
    }
    return !input.fail();
}

bool CalculatorUI::ReadNumber(std::istream& input, Number& result) const {
    if (!(input >> result)) {
        err_ << "Error: Numeric operand expected"s << std::endl;
        return false;
    }
    return true;
}