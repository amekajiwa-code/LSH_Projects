#include "MyManager.h"

MyManager::MyManager() {
	list = new MyLinkedList<MyStudent>;
}

MyManager::~MyManager() {
	delete list;
	list = nullptr;
}

void MyManager::Initialize() {
	list->DestroyNode();
	ID = 0;
	for (int i = 0; i < 10; ++i) {
		MyStudent dummy("dummy", ID, 50 + i, 60 + i, 40 + i);
		Node<MyStudent>* newNode = list->CreateNode(dummy, ID++);
		list->PushFront(newNode);
	}
	cout << "�����Ͱ� �ʱ�ȭ �Ǿ����ϴ�." << endl;
}

void MyManager::Print() {
	Node<MyStudent>* node;
	node = list->mHeadNode.mNextNode;
	if (node == nullptr) {
		cout << "�����Ͱ� �����ϴ�." << endl;
	}
	else {
		cout << "�����͸� ����մϴ�." << endl;
	}
	cout << left << setw(10) << "Name"
		<< setw(5) << "ID" << setw(5) << "Kor"
		<< setw(5) << "Eng" << setw(5) << "Mat"
		<< setw(5) << "Tot" << setw(5) << "Avg" << endl;

	while (node != nullptr) {
		cout << left << setw(10) << node->mData.GetName()
			<< setw(5) << node->mData.GetID() << setw(5) << node->mData.GetKorScore()
			<< setw(5) << node->mData.GetEngScore() << setw(5) << node->mData.GetMatScore()
			<< setw(5) << node->mData.GetTotalScore() << setw(5) << node->mData.GetAverageScore() << endl;

		node = node->mNextNode;
	}
}

void MyManager::Find() {
	int input = -1;
	cout << "Find - Target ID : ";
	cin >> input;
	Node<MyStudent>* findNode;
	findNode = list->FindNode(input);
	if (findNode != nullptr) {
		cout << "�˻��� �л� : " << findNode->mData.PrintStudent() << endl;
	}
	else {
		cout << "�˻��� �л��� �����ϴ�." << endl;
	}
}

void MyManager::Save() {
	string fileName = "";
	cout << "���̺� ���ϸ� : ";
	cin >> fileName;
	string output = "";
	Node<MyStudent>* node = list->mHeadNode.mNextNode;
	while (node != nullptr) {
		output += node->mData.PrintStudent();
		output += "\n";
		node = node->mNextNode;
	}
	FileIO fo;
	fo.SaveFile(fileName, output);
}

void MyManager::Load() {
	list->DestroyNode();
	ID = 0;
	string name;
	int kor, eng, mat;
	string fileName = "";
	cout << "�ҷ��� ���ϸ� : ";
	cin >> fileName;
	FileIO fi;
	string text = fi.LoadFile(fileName);
	if (text == "failed") {
		cout << "���� �о���µ� �����߽��ϴ�." << endl;
		return;
	}
	string member = "";
	string buffer = "";
	int spaceCounter = 0;
	int index = 0;
	Utility ut;
	while (true) {
		if (index > text.size()) {
			break; //��������
		}
		//�����̸� ++
		buffer += text[index];
		if (text[index] == ' ') {
			++spaceCounter;
			// 1 3 4 5�� �� ��������� �ش��ϴ� ��ġ
			switch (spaceCounter) {
			case 1: {
				name = member;
				member = "";
				break;
			}
			case 2: {
				member = "";
				break;
			}
			case 3: {
				kor = ut.StringToInt(member);
				member = "";
				break;
			}
			case 4: {
				eng = ut.StringToInt(member);
				member = "";
				break;
			}
			case 5: {
				mat = ut.StringToInt(member);
				member = "";
				break;
			}
			default: {
				break;
			}
			}
		}
		else {
			member += text[index];
		}

		//�ʱ�ȭ
		if (spaceCounter > 6) {
			MyStudent dummy(name, ID, kor, eng, mat);
			Node<MyStudent>* newNode = list->CreateNode(dummy, ID++);
			list->PushBack(newNode);
			member = "";
			buffer = "";
			spaceCounter = 0;
		}
		//index ��ȸ
		++index;
	}
	cout << "�����Ͱ� �ε� �Ǿ����ϴ�." << endl;
}

void MyManager::Insert() {
	cout << "�Է� ���� : �̸� ���� ���� ���� : ";
	string name;
	int kor, eng, mat;
	cin >> name >> kor >> eng >> mat;
	MyStudent dummy(name, ID, kor, eng, mat);
	Node<MyStudent>* newNode = list->CreateNode(dummy, ID++);

	cout << "�Է� ��� : 1. ���� 2. ����. 3. �߰����� : ";
	int inputOption = -1;
	cin >> inputOption;
	switch (inputOption)
	{
	case 1: {
		list->PushBack(newNode);
		break;
	}
	case 2: {
		list->PushFront(newNode);
		break;
	}
	case 3: {
		cout << "���Ե� �л��� ID : ";
		int inputID = -1;
		cin >> inputID;
		Node<MyStudent>* findNode;
		findNode = list->FindNode(inputID);
		if (findNode != nullptr) {
			list->InsertNode(findNode, newNode);
		}
		else {
			cout << "�˻��� �л��� �����ϴ�." << endl;
		}
		break;
	}
	default:
		break;
	}
}

void MyManager::Delete() {
	int input = -1;
	cout << "�����ϰ� ���� �л��� ID : ";
	cin >> input;
	Node<MyStudent>* findNode = list->FindNode(input);
	if (findNode != nullptr) {
		list->DeleteNode(findNode);
		cout << "�����Ͱ� �����Ǿ����ϴ�." << endl;
	}
	else {
		cout << "�˻��� �л��� �����ϴ�." << endl;
	}
}

void MyManager::Update() {
	int input = -1;
	cout << "�Է� ���� : �̸� ���� ���� ���� : ";
	string name;
	int kor, eng, mat;
	cin >> name >> kor >> eng >> mat;
	MyStudent dummy(name, ID, kor, eng, mat);
	cout << "�����ϰ� ���� �л��� ID : ";
	cin >> input;
	Node<MyStudent>* findNode = list->FindNode(input);
	if (findNode != nullptr) {
		findNode->mData = dummy;
	}
	else {
		cout << "�˻��� �л��� �����ϴ�." << endl;
	}
	cout << "�����Ͱ� �����Ǿ����ϴ�." << endl;
}

void MyManager::Sort() {
	MyLinkedList<MyStudent>* list2 = new MyLinkedList<MyStudent>;
	Node<MyStudent>* node = list->mHeadNode.mNextNode;
	while (node != nullptr) {
		Node<MyStudent>* tempNode = new Node<MyStudent>(*node);
		list2->PushBack(tempNode);
		node = node->mNextNode;
	}
	MergeSort<MyStudent> ms;
	ms.merge_sort(&list2->mHeadNode.mNextNode, list2->GetLength());
	cout << "�����Ͱ� ���ĵǾ����ϴ�." << endl;

	Node<MyStudent>* node2;
	node2 = list2->mHeadNode.mNextNode;
	cout << left << setw(10) << "Name"
		<< setw(5) << "ID" << setw(5) << "Kor"
		<< setw(5) << "Eng" << setw(5) << "Mat"
		<< setw(5) << "Tot" << setw(5) << "Avg" << endl;

	while (node2 != nullptr) {
		cout << left << setw(10) << node2->mData.GetName()
			<< setw(5) << node2->mData.GetID() << setw(5) << node2->mData.GetKorScore()
			<< setw(5) << node2->mData.GetEngScore() << setw(5) << node2->mData.GetMatScore()
			<< setw(5) << node2->mData.GetTotalScore() << setw(5) << node2->mData.GetAverageScore() << endl;

		node2 = node2->mNextNode;
	}

	delete list2;
	list2 = nullptr;
}