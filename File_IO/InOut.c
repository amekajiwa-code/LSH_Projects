#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
    FILE* fp = fopen("test.txt", "w");
    fputs("save file", fp);
    fclose(fp);

    fp = fopen("test.txt", "r");
    while (1) {
        char arr[100];
        char* pStr = fgets(arr, 100, fp);
        if (pStr == NULL) {
            break;
        }
        printf("%s", arr);
    }
    fclose(fp);
    return 0;
}
