#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>


int
read_dir (char * path, int depth) {
    
    DIR * dp ;
    struct dirent * ep;

    dp = opendir(path);
    
    if (dp == NULL) {
        return 0;
    }
    else {

        while (ep = readdir(dp)) {
            if (strcmp(ep->d_name, ".") == 0) {
            }
            else if (strcmp(ep->d_name, "..") == 0) {
            }
            else {
                printf("%s%s\n", path, ep->d_name);

                if (ep->d_type == DT_DIR) {
                    char * _path = (char *) malloc (sizeof(char) * 256 * (depth + 1));
                    strcpy(_path, path);
                    strcat(_path, ep->d_name);
                    strcat(_path, "/");
                    read_dir(_path, depth+1);
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
        perror("invalid input");
    }

    read_dir(argv[1], 0);
    return 0;

}