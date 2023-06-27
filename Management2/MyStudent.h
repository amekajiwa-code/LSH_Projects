#pragma once
#include <string>
using namespace std;

class MyStudent {
public:
	MyStudent() {
		mName = "NoData"; mID = -1; mKor = -1; mEng = -1; mMat = -1;
		mTot = -1;
		mAvg = -1;
	}
	MyStudent(string name, int id,int kor, int eng, int mat) {
		mName = name; mID = id; mKor = kor; 
		mEng = eng; mMat = mat;
		mTot = mKor + mEng + mMat;
		mAvg = mTot / 3.0f;
	}
private:
	string mName;
	int mID;
	int mKor;
	int mEng;
	int mMat;
	int mTot;
	float mAvg;
};