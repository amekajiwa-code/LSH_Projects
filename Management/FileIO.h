#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "LinkedList.h"
using namespace std;

class FileIO {
public:
	void SaveFile(Node* headNode);
	void LoadFile(LinkedList* list);
private:
};