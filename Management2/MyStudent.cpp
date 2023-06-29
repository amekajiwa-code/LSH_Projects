#include "MyStudent.h"

MyStudent::MyStudent() {
	mName = "NoData"; mID = -1; mKor = -1; mEng = -1; mMat = -1;
	mTot = -1;
	mAvg = -1;
};

MyStudent::MyStudent(string name, int id, int kor, int eng, int mat) {
	mName = name; mID = id; mKor = kor;
	mEng = eng; mMat = mat;
	mTot = mKor + mEng + mMat;
	mAvg = mTot / 3.0f;
};

string MyStudent::IntToString(int num) {
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

string MyStudent::PrintStudent() {
	string output = "";
	output += mName + "  ";
	output += IntToString(mID) + "    ";
	output += IntToString(mKor) + "   ";
	output += IntToString(mEng) + "   ";
	output += IntToString(mMat) + "   ";
	output += IntToString(mTot) + "  ";
	output += IntToString(mAvg);
	return output;
};

int MyStudent::GetID() {
	return mID;
}