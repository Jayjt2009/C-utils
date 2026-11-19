#include <stdio.h>

void print_file(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL){
        printf("Unable to open file %s\n", filename);
        return;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
}

int main(int argc, char **argv)
{
    if (argc == 1) {
        printf("Usage: ./cat [FILE]...\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        print_file(argv[i]);
        printf("\n");
    }

    return 0;
}
