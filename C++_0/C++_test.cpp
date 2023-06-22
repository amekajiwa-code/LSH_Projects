#include <iostream>

using namespace std;

class Vector {
public:
	Vector operator+(const Vector& other) const {
		Vector sum;
		sum.mX = this->mX + other.mX;
		sum.mY = this->mY + other.mY;
		return sum;
	}
	int mX;
	int mY;
};

int main() {
	Vector vector1;
	vector1.mX = 1, vector1.mY = 2;
	Vector vector2;
	vector2.mX = 3, vector2.mY = 4;
	Vector sum = vector1.operator+(vector2);
	cout << sum.mX << " " << sum.mY;
}