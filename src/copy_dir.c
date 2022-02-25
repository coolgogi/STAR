#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

int
copy_dir () {
    return 0;
}

char *
read_dir (char * path) {
    return 0;
}

int
main (int argc, char * argv[]) {
    
    if (argc != 3) {
        fprintf(stderr, "invalid argument\n");
        exit(EXIT_FAILURE);
    }

    DIR * old_path;
    DIR * new_path;

    old_path = opendir(argv[1]);
    if (old_path == NULL) {
        perror("argv[1] opendir error");
        exit(errno);
    }

    new_path = opendir(argv[2]);
    if (new_path == NULL) {
        perror("argv[2] opendir error");
        exit(errno);
    }

    struct dirent * old_path_dirent ;
    
    while (old_path_dirent = readdir(old_path)) {
        if (old_path_dirent->d_type == DT_DIR) {
            
        }
        else if (old_path_dirent->d_type == DT_REG) {
            
        }

    }
    if (errno != 0) {
        perror("readdir error");
        exit(errno);
    }
	return 0;
}   
