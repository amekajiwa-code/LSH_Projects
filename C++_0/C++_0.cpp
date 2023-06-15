#include <iostream>

using namespace std;

int main()
{
    ifstream fin;
    fin.open("helloWorld.txt");
    char chara;
    while (true) {
        //텍스트파일에서 한글자씩 불러옴
        fin.get(chara);
        //읽기에 실패하면 종료
        if (fin.fail()) {
            break;
        }
        cout << chara;
    }
    fin.close();
}