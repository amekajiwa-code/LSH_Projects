#include "MyStudent.h"
#include "MyUtility.h"

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

string MyStudent::PrintStudent() {
	Utility ut;
	string output = "";
	output += mName + " ";
	output += ut.IntToString(mID) + " ";
	output += ut.IntToString(mKor) + " ";
	output += ut.IntToString(mEng) + " ";
	output += ut.IntToString(mMat) + " ";
	output += ut.IntToString(mTot) + " ";
	output += ut.IntToString(mAvg);
	return output;
};

int MyStudent::GetID() const {
	return mID;
}

std::string MyStudent::GetName() const {
	return mName;
}

int MyStudent::GetKorScore() const {
	return mKor;
}

int MyStudent::GetEngScore() const {
	return mEng;
}

int MyStudent::GetMatScore() const {
	return mMat;
}

int MyStudent::GetTotalScore() const {
	return mTot;
}

float MyStudent::GetAverageScore() const {
	return mAvg;
}