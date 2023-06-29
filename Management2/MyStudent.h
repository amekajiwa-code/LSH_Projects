#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class MyStudent {
public:
	MyStudent();
	MyStudent(string name, int id, int kor, int eng, int mat);
	string PrintStudent();
	string IntToString(int num);
	int GetID();
private:
	string mName;
	int mID;
	int mKor;
	int mEng;
	int mMat;
	int mTot;
	float mAvg;
};