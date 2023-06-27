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

void MyStudent::PrintStudent() {
	cout << mName << " "
		<< mID << " "
		<< mKor << " "
		<< mEng << " "
		<< mMat << " "
		<< mTot << " "
		<< mAvg << endl;
};