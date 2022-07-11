#include <iostream>
#include <string>


namespace CreditCardValidator {
    bool CheckNumber(const std::string& number) {
        for(int i = 0; i < number.length(); i++) {
            if (!isdigit(number[i])) {
                std::cout << "Invalid card number." << std::endl;
                return false;
            }
        }

        return true;
    }

    std::string Identify(const std::string& chunk) {
        unsigned int two   = std::stoi(chunk.substr(0, 2));
        unsigned int three = std::stoi(chunk.substr(0, 3));
        unsigned int four  = std::stoi(chunk);

        if      (chunk[0] == '4')                                         return "Visa"             ;
        else if (two >= 51 && two <= 55 || four >= 2221 && four <= 2720)  return "Mastercard"       ;
        else if (two == 34 || two == 37)                                  return "American Express" ;
        else if (three >= 300 && three <= 305 || two == 36 || two == 38)  return "Diners Club"      ;
        else if (four == 6011 || two == 65)                               return "Discover"         ;
        else if (four == 2131 || four == 1800 || two == 35)               return "JCB"              ;
        else                                                              return "Unknown"          ;
    }

    // Greedy by ReNero
    void ToSingle(unsigned int *n) {
        *n = 1 + 2 * (*n - 5);
    }
}


int main() {
    std::string  cc_number;
    unsigned int actual, sum = 0;
    
    std::cout << "↓ Enter the card number ↓" << std::endl;
    std::cin >> cc_number;

    if (CreditCardValidator::CheckNumber(cc_number)) {
        for(int i = 0;i < cc_number.length(); i++) {
            actual = cc_number[i] - '0';
            if (i % 2 == 0) {
                if (actual >= 5)
                    CreditCardValidator::ToSingle(&actual);
                else
                    actual *= 2;
            }

            sum += actual;
        }

        if (sum % 10 == 0) {
            std::cout << "The card is valid." << std::endl;
            std::cout << "Type: " << CreditCardValidator::Identify(cc_number.substr(0, 4)) << std::endl;
        } else
            std::cout << "The card is invalid" << std::endl;
    }

    return 0;
}
