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

// Greedy by ReNero
void to_single(unsigned int *n) {
    *n = 1+2*(*n-5);
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
                if (actual >= 5)
                    to_single(&actual);
                else
                    actual *= 2;
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