#include "FileIO.h"

void FileIO::SaveFile(Node* headNode) {
	ofstream fout;
	fout.open("savefile.txt");
	if (fout.is_open()) {
		Node* Node = headNode->GetNextNode();
		while (Node != nullptr) {
			fout << Node->GetId() << " " << Node->GetValue() << endl;
			Node = Node->GetNextNode();
		}
	}
	fout.close();
}

void FileIO::LoadFile(LinkedList* list) {
	ifstream fin;
	fin.open("savefile.txt");
	if (fin.is_open()) {
		int input;
		string trash;
		while (!fin.eof()) {
			Node* newNode = list->CreateNode(-1, -1);
			fin >> input;
			if (!fin.fail()) {
				newNode->SetId(input);
				fin >> input;
				if (!fin.fail()) {
					newNode->SetValue(input);
					list->PushBack(newNode);
					continue;
				}
			}
			fin.clear();
			fin >> trash;
		}
	}
	fin.close();
}