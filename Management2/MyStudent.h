#pragma once
#include <iostream>
#include <string>
using namespace std;

class MyStudent {
public:
	MyStudent();
	MyStudent(string name, int id, int kor, int eng, int mat);
	void PrintStudent();
private:
	string mName;
	int mID;
	int mKor;
	int mEng;
	int mMat;
	int mTot;
	float mAvg;
};