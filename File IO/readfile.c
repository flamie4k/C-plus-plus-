#include <stdio.h>

int main() {
    FILE *file;

    file = fopen("file.txt", "r");

    if (file == NULL) {
        fprintf(stderr, "Unable to open the file.\n");
        return 1;
    }

    int ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);

    return 0;
}
