#include <iostream>

using namespace std;

bool number_check(const string& number) {
    for(int i=0; i<number.length(); i++) {
        if (!isdigit(number[i])) {
            cout << "Invalid card number." << endl;
            return false;
        }
    }
    return true;
}

unsigned int to_single(unsigned int twodigit) {
    unsigned int single = 0;
    while (twodigit != 0) {
        single += twodigit % 10;
        twodigit /= 10;
    }
    return single;
}

string identify(const string& chunk) {
    unsigned int two = stoi(chunk.substr(0,2));
    unsigned int three = stoi(chunk.substr(0,3));
    unsigned int four = stoi(chunk);

    if (chunk[0] == '4')
        return "Visa";
    else if (two >= 51 && two <= 55 || four >= 2221 && four <= 2720)
        return "Mastercard";
    else if (two == 34 || two == 37)
        return "American Express";
    else if (three >= 300 && three <= 305 || two == 36 || two == 38)
        return "Diners Club";
    else if (four == 6011 || two == 65)
        return "Discover";
    else if (four == 2131 || four == 1800 || two == 35)
        return "JCB";
    else
        return "Unknown";
}

int main(void) {
    string cc_number;
    unsigned int actual, sum=0;
    
    cout << "↓ Enter the card number ↓" << endl;
    cin >> cc_number;
    if (number_check(cc_number)) {
        for(int i=0;i<cc_number.length();i++) {
            actual = cc_number[i] - '0';
            if (i % 2 == 0) {
                actual *= 2;
                if (actual > 9)
                    actual = to_single(actual);
            }
            sum += actual;
        }
        if (sum % 10 == 0) {
            cout << "The card is valid." << endl;
            cout << "Type: " << identify(cc_number.substr(0,4)) << endl;
        } else
            cout << "The card is invalid" << endl;
    }
}