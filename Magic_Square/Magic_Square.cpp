#include <stdio.h>
#include <stdlib.h>

void FillMagicSquare(int** square, int size);
int** CreateSquare(int n);

int main()
{
    int n;
    
    printf("홀수인 정수 n을 입력하시오 : ");
    scanf_s("%d", &n);
    
    //마방진생성
    int** mgSquare = CreateSquare(n);
    //마방진구축
    FillMagicSquare(mgSquare, n);
    //출력
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < n; ++x) {
            printf("%-6d ", mgSquare[y][x]);
        }
        printf("\n");
    }
    //검증
    for (int y = 0; y < n; ++y) {
        int SumLine = 0;
        for (int x = 0; x < n; ++x) {
            SumLine += mgSquare[y][x];
        }
        printf("합산: % d\n",SumLine);
    }
    //메모리 해제
    for (int i = 0; i < n; ++i) {
        free(mgSquare[i]);
        mgSquare[i] = NULL;
    }
    free(mgSquare);
    mgSquare = NULL;
}

void FillMagicSquare(int** square, int size) {
    int mid = size / 2;
    int max = size - 1;
    int preX = mid;
    int preY = max;
    int X = preX;
    int Y = preY;
    int preNum = 1;
    //square[y][x]
    square[max][mid] = preNum;
    while (true) {
        X = preX + 1, Y = preY + 1;
        //범위를 벗어났을때
        if (X > max || Y > max) {
            if (X > max && Y > max) {
                X = preX, Y = preY - 1;
            }
            else if (X > max) {
                X = 0;
            }
            else {
                Y = 0;
            }
        }
        //범위 안이라면 비어있는지 확인후 있다면 이전위치의 위칸 기입
        if (square[Y][X] != 0) {
            X = preX, Y = preY - 1;
        }

        //예외처리
        if (Y < 0) {
            break;
        }
        if (square[Y][X] != 0) {
            break;
        }
        
        square[Y][X] = ++preNum;
        preX = X, preY = Y;
    }
}

int** CreateSquare(int n) {
    int** square = NULL;
    //2차원 포인터 배열 동적할당
    square = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; ++i) {
        square[i] = (int*)malloc(sizeof(int) * n);
    }

    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < n; ++x) {
            *(*(square + y) + x) = 0;
        }
    }

    return square;
}