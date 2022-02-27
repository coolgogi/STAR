#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <limits.h>
#include <sys/stat.h>
#include <string.h>

int
copy_dir (char * old_path, char * new_path, int type) {

    if (type == DT_DIR) {

        mode_t md =  S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH ;
        if (mkdir(new_path, md) == -1) {
            perror("mkdir error");
            return errno;
        }

        return 0;
    }
    else if (type == DT_REG) {
        FILE * old_fp ;
        FILE * new_fp ;
        old_fp = fopen(old_path, "r");
        new_fp = fopen(new_path, "w");

        if (old_fp == NULL) {
            perror("old fp fopen error");
            return errno;
        }
        if (new_fp == NULL) {
            perror("new fp fopen error");
            return errno;
        }

        unsigned char buf ;
        while (fread(&buf, 1, 1, old_fp) == 1) {
            if (fwrite(&buf, 1, 1, new_fp) != 1) {
                perror("fwrite error");
                return errno;
            }
            
        }
        
        fclose(old_fp);
        fclose(new_fp);

        return 0;
    }
    return 0;
}


int
read_dir (char * old_path, char * new_path) {

    DIR * old_dir;
    
    struct dirent * dir_dirent;

    old_dir = opendir(old_path);

    if (old_dir == NULL) {
        perror("argv[1] opendir error");
        return errno;
    }
    
    while (dir_dirent = readdir(old_dir)) {

        if (strcmp(dir_dirent->d_name, ".") == 0) {
            continue;
        }
        else if (strcmp(dir_dirent->d_name, "..") == 0) {
            continue;
        }
        else {
            
            char * old_child_path = (char *) malloc(sizeof(char) * PATH_MAX);
            char * new_child_path = (char *) malloc(sizeof(char) * PATH_MAX);

            strcpy(old_child_path, old_path);
            strcpy(new_child_path, new_path);

            strcat(old_child_path, dir_dirent->d_name);
            strcat(new_child_path, dir_dirent->d_name);
            

            if (dir_dirent->d_type == DT_DIR) {
                strcat(old_child_path, "/");
                strcat(new_child_path, "/");
                copy_dir(old_child_path, new_child_path, DT_DIR);
                read_dir(old_child_path, new_child_path);

            }
            else if (dir_dirent->d_type == DT_REG) {

                copy_dir(old_child_path, new_child_path, DT_REG);

            }

            free(new_child_path);
            free(old_child_path);
        }

    }
    
    closedir(old_dir);
    return 0;
}

int
main (int argc, char * argv[]) {
    
    if (argc != 3) {
        fprintf(stderr, "invalid argument\n");
        exit(EXIT_FAILURE);
    }

    read_dir (argv[1], argv[2]) ;
        
	return 0;
}   
