#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
    FILE* fp = fopen("test.txt", "w");
    if (fp != NULL) {
        //fprintf(fp, %d, %d\n, 100, 200);
        fputs("save file", fp);
        //_getche();
    }
    fclose(fp);


    fp = fopen("test.txt", "r");
    if (fp != NULL) {
        //fscanf(fpRead, %d, %d\n, &a, &n);
        while (1) {
            char arr[100];
            char* pStr = fgets(arr, 100, fp);
            if (pStr == NULL) {
                break;
            }
            printf("%s", arr);
        }
    }
    fclose(fp);
    return 0;
}
