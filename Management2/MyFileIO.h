#pragma once
#include <fstream>
#include <string>
using namespace std;

class FileIO {
public:
	void SaveFile(string fileName, string input);
	string LoadFile(string fileName);
private:
};