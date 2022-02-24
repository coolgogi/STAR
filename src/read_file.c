#include <stdio.h>
#include <stdlib.h>


int
read_file (FILE * file) {

    unsigned char buf ;
    
    for (int i = 0 ; fread(buf, 1, 1, file) == 1 ; i ++) {
        
        printf("%02x", buf);

        
        if ((i != 0) && (i % 2 == 0)) {
            printf(" ");
        }
        if (i & 16 == 0) {
            printf("%x: ", i);
        }

    }
    
    return 0 ;
}


int
main (int argc, char * argv[]) {
    if (argc != 2) {
        printf("invalid argument\n");
    }

    FILE * fp ;
    fp = fopen(argv[1], "r");
    read_file(fp);
    fclose(fp);

    return 0;

}