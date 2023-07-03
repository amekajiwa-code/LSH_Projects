#pragma once
#include <iostream>
#include "MyLinkedList.h"
#include "MyStudent.h"
#include "MyMergeSort.h"
#include "MyFileIO.h"
#include "MyUtility.h"

class MyManager {
public:
	MyManager();
	~MyManager();
	void Initialize();
	void Print();
	void Find();
	void Save();
	void Load();
	void Insert();
	void Delete();
	void Update();
	void Sort();
private:
	MyLinkedList<MyStudent>* list;
	int ID = 0;
};