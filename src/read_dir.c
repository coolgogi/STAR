#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

int
read_dir (char * path) {
    
    DIR * dir;
    struct dirent * dir_info;

    dir = opendir(path);
    
    if (dir == NULL) {
        perror("opendir returned NULL");
        return errno;
    }
    else {

        while ((dir_info = readdir(dir))) {

            if (strcmp(dir_info->d_name, ".") == 0) {
                continue;
            }
            else if (strcmp(dir_info->d_name, "..") == 0) {
                continue;
            }
            else if (strcmp(dir_info->d_name, ".DS_Store") == 0) {
                continue;
            }
            else {

                printf("%s%s\n", path, dir_info->d_name);

                if (dir_info->d_type == DT_DIR) {
                    char * child_path = (char *) malloc(sizeof(char) * PATH_MAX);
                    strcpy(child_path, path);
                    strcat(child_path, dir_info->d_name);
                    strcat(child_path, "/");
                    
                    read_dir(child_path);
                    
                    free(child_path);
                }
            }
        }
        closedir(dir);
        return 0;
    }
}

int
main (int argc, char * argv[]) {
    
    if (argc != 2) {
        fprintf(stderr, "invalid input");
        return errno;
    }

    return read_dir(argv[1]);
}