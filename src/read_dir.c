#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

int
read_dir (char * path) {
    
    DIR * dp ;
    struct dirent * ep;

    dp = opendir(path);
    
    if (dp == NULL) {
        perror("opendir returned NULL");
        return errno;
    }
    else {

        while (ep = readdir(dp)) {

            if (strcmp(ep->d_name, ".") == 0) {
                continue;
            }
            else if (strcmp(ep->d_name, "..") == 0) {
                continue;
            }
            else if (strcmp(ep->d_name, ".DS_Store") == 0) {
                continue;
            }
            else {

                printf("%s%s\n", path, ep->d_name);

                if (ep->d_type == DT_DIR) {
                    char * _path = (char *) malloc (sizeof(char) * PATH_MAX);
                    strcpy(_path, path);
                    strcat(_path, ep->d_name);
                    strcat(_path, "/");
                    
                    read_dir(_path);
                    
                    free(_path);
                }
            }
        }
        return 0;
    }
}

int
main (int argc, char * argv[]) {
    
    if (argc != 2) {
        fprintf(stderr, "invalid input");
        return 0;
    }

    read_dir(argv[1]);
    
    return 0;

}