#include <iostream>
#include <string>
using namespace std;

class MyString {
public:
	MyString() {
		mBuffer = nullptr;
		mSize = 0;
	}
	~MyString() {

	}
private:
	char* mBuffer;
	int mSize;
	string asd;
};

int main() {
	MyString text;
}