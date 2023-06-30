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