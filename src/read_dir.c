#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

int
read_dirlist (char * path, int depth) {
    
    DIR *dp;
    struct dirent *ep;

    dp = opendir (path);
    int _depth = depth + 1;

    if (dp != NULL) {
        while (ep = readdir (dp)) {

            printf("%s%s\n",path,ep->d_name);
            if (ep->d_type == 4) {
                
                if (strcmp(ep->d_name,".") == 0) {
                } 
                else if (strcmp(ep->d_name,"..") == 0) {
                }
                else {
                    char * _path = (char *) malloc (sizeof(char) * 256 *_depth);
                    strcpy(_path, path);
                    strcat(_path, ep->d_name);
                    strcat(_path, "/");
                    read_dirlist(_path,_depth);
                }
                
            }
        }

        (void) closedir (dp);
    }
    else {
        // perror ("Couldn't open the directory");
    }
    return 0;
}

int
main (int argc, char * argv[]) {
    
    read_dirlist("./", 0);
    return 0;

}