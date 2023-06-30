#include "MyFileIO.h"

void FileIO::SaveFile(string fileName, string input) {
	ofstream fout;
	fout.open(fileName);
	if (fout.is_open()) {
		fout << input << endl;
	}
	fout.close();
}

string FileIO::LoadFile(string fileName) {
	ifstream fin;
	string output = "";
	fin.open(fileName);
	if (fin.is_open()) {
		string trash;
		while (!fin.eof()) {
			if (!fin.fail()) {
				string temp;
				fin >> temp;
				output += temp + " ";
				continue;
			}
			fin.clear();
			fin >> trash;
		}
	}
	fin.close();

	return output;
}