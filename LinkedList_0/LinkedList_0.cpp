#include <iostream>

struct TNode {
    int iId;
    int iValue;
    // 자기 참조 구조체
    TNode* pNext;
};

TNode* g_pHead;
TNode* g_pTail;

void init(); // 초기화
TNode* Create(int count); // 생성
void Link(TNode* pNewNode); // 연결
void Print(); // O(N) 출력
TNode* FindNode(int id);// O(N) 검색
void DeleteNode(int id); // O(N) 삭제

//void InsertNode(TNode* pNewNode); // 삽입
//void UpdateNode //수정
//void destroyNode(); // 소멸

int main()
{
    //초기화
    init();
    for (int i = 0; i < 5; ++i) {
        //생성
        TNode* pNewNode = Create(i);
        //연결
        Link(pNewNode);
    }
    //검색
    TNode* findMe = FindNode(2);
    std::cout << findMe->iId << std::endl;
    //삭제
    DeleteNode(3);
    //순회, 출력
    Print();

    //메모리 해제
    /*TNode* pNode = g_pHead.;
    while (pNode != NULL) {
        TNode* pNext = pNode->pNext;
        free(pNode);
        pNode = pNext;
    }*/
}
// 검색, 삭제, 수정, 정렬, 저장, 불러오기, 삽입(중간), 소멸(전체)
//모든 자료구조에서 이 12가지는 함수화 시켜놓고 작업해야 한다. 자료구조에 따라 기능을 빼거나 추가하면 된다.

void init() {
    g_pHead = (TNode*)malloc(sizeof(TNode*));
    g_pHead->iId = 0;
    g_pHead->iValue = 0;
    g_pHead->pNext = NULL;
    g_pTail = g_pHead;
}

TNode* Create(int count) {
    TNode* pNewNode = (TNode*)malloc(sizeof(TNode*));
    pNewNode->iId = count;
    pNewNode->iValue = count;
    pNewNode->pNext = NULL;
    return pNewNode;
}

void Link(TNode* pNewNode) {
    if (g_pHead->pNext == NULL) {
        g_pHead->pNext = pNewNode;
    }
    else {
        g_pTail->pNext = pNewNode;
    }
    g_pTail = pNewNode;
}

void Print() {
    //순회
    for (TNode* pNode = g_pHead->pNext;
        pNode != NULL;
        pNode = pNode->pNext) {
        //출력
        std::cout << pNode->iValue << " ";
    }
}

void DeleteNode(int id) {
    TNode* pNode = g_pHead->pNext;
    TNode* pPreNode = NULL;
    while (pNode != NULL) {
        TNode* pNext = pNode->pNext;
        if (pNode->iId == id) {
            //첫번째 노드일때
            if (pPreNode == NULL) {
                g_pHead->pNext = pNode->pNext;
                pNode->pNext = NULL;
                break;
            }
            //마지막 노드일때
            if (pNode->pNext == NULL) {
                pPreNode->pNext = NULL;
                pNode->pNext = NULL;
                break;
            }
            pPreNode->pNext = pNode->pNext; // 전노드와 다음노드 연결
            pNode->pNext = NULL; // 중간노드 삭제
            break;
        }
        pPreNode = pNode;
        pNode = pNext;
    }
}

TNode* FindNode(int id) {
    TNode* pNode = g_pHead->pNext;
    TNode* pPreNode = NULL;
    while (pNode != NULL) {
        TNode* pNext = pNode->pNext;
        if (pNode->iId == id) {
            return pNode;
        }
        pNode = pNext;
    }
}