#pragma once
#include <iostream>
#include <string>
using namespace std;

class Student {
public:
	Student(string name, int id);
	void SetScore(int kor, int eng, int mat);
	void Print();
	string GetName() const;
	int GetID() const;
	int GetKor() const;
	int GetEng() const;
	int GetMat() const;
	int GetTotal() const;
	int GetAvg() const;
private:
	string mName;
	int mID;
	int mKor;
	int mEng;
	int mMat;
	int mTotal;
	int mAvg;
};