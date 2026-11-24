#include <stdio.h>
#include <stdbool.h>
#include <sys/stat.h>


int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("Usage: ./mv <source> <target>...\n");
        printf("     : ./mv <source>... <dir>...\n");
        return 0;
    }

    bool target_exists;
    int src_count = argc -2;
    const char *target = argv[argc - 1];
    struct stat st;
    if (stat(target, &st) == 0) target_exists = true;

    if (src_count > 1) {
        if (!(target_exists && S_ISDIR(st.st_mode))) {
            fprintf(stderr, "./mv: target '%s': Not a directory\n", target);
            return 1;
        }
    }

   if (src_count == 1) {
       if (target_exists) {
           fprintf(stderr, "./mv: target '%s': already exists\n", target);
           return 1;
       } else {
           rename(argv[src_count], target);
       }
   }

    return 0;
}

