#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    if (argc == 1) {
        printf("Usage: ./mv <path> <target>...\n");
        printf("     : ./mv <path>... <dir>...\n");
        return 0;
    }

    const char *target = argv[argc - 1];
    const char *path = argv[1];
    struct stat st;
    if (stat(target, &st) == 0) {
        if (S_ISDIR(st.st_mode))
            printf("target dir exist");
    } else {
        rename(path, target);
        printf("target does not exist");
    }

    return 0;
}

