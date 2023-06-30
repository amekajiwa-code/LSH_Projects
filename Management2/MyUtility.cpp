#include "MyUtility.h"

string Utility::IntToString(int num) {
	string result = "";
	if (num == 0) {
		result = "0";
	}
	else {
		while (num > 0) {
			char digitChar = (num % 10) + '0';
			result.insert(0, 1, digitChar);
			num /= 10;
		}
	}
	return result;
};

int Utility::StringToInt(const string& num) {
    int result = 0;
    bool is_negative = false;
    size_t start = 0;

    if (num[0] == '-') {
        is_negative = true;
        start = 1;
    }

    for (size_t i = start; i < num.length(); ++i) {
        char digit_char = num[i];
        int digit = digit_char - '0';

        result = result * 10 + digit;
    }

    if (is_negative) {
        result *= -1;
    }

    return result;
}