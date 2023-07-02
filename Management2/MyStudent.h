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
	int GetID() const;
	string GetName() const;
	int GetKorScore() const;
	int GetEngScore() const;
	int GetMatScore() const;
	int GetTotalScore() const;
	float GetAverageScore() const;

private:
	string mName;
	int mID;
	int mKor;
	int mEng;
	int mMat;
	int mTot;
	float mAvg;
};