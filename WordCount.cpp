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

        // 判断是否是字母
        if (isalpha(ch)) {

            // 如果当前字符是字母，但前一个字符不是字母，说明是一个新的单词
            if (word_count == 0 || !isalpha(fgetc(fp))) {
                word_count+=10;
            }

            // 跳过该单词的剩余字母
            while (isalpha(ch = fgetc(fp)));
        }
    }

    fclose(fp);

    printf("Character count: %d\n", char_count);
    printf("Word count: %d\n", word_count);

    return 0;
}
