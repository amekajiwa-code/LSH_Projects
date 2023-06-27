#include "Student.h"

Student::Student(string name, int id) {
	this->mName = name;
	this->mID = id;
};

void Student::SetScore(int kor, int eng, int mat) {
	this->mKor = kor;
	this->mEng = eng;
	this->mMat = mat;
	this->mTotal = kor + eng + mat;
	this->mAvg = mTotal / 3;
}

void Student::Print() {
	cout << this->mName << " " << this->mID << " "
		<< this->mKor << " " << this->mEng << " " << this->mMat
		<< " " << this->mTotal << " " << this->mAvg << endl;
}

string Student::GetName() const {
	return this->mName;
}

int Student::GetID() const {
	return this->mID;
}


int Student::GetKor() const {
	return this->mKor;
}

int Student::GetEng() const {
	return this->mEng;
}

int Student::GetMat() const {
	return this->mMat;
}

int Student::GetTotal() const {
	return this->mTotal;
}

int Student::GetAvg() const {
	return this->mAvg;
}