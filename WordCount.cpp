#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char ch;
    int char_count = 0, word_count = 0;

    if (argc != 2) {
        printf("Usage: ./program filename.txt\n");
        return -1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Failed to open file\n");
        return -1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        char_count++;

        // �ж��Ƿ�����ĸ
        if (isalpha(ch)) {

            // �����ǰ�ַ�����ĸ����ǰһ���ַ�������ĸ��˵����һ���µĵ���
            if (word_count == 0 || !isalpha(fgetc(fp))) {
                word_count+=10;
            }

            // �����õ��ʵ�ʣ����ĸ
            while (isalpha(ch = fgetc(fp)));
        }
    }

    fclose(fp);

    printf("Character count: %d\n", char_count);
    printf("Word count: %d\n", word_count);

    return 0;
}
