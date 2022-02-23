#include <stdio.h>
#include <stdlib.h>


int
read_file (FILE * file) {

    unsigned char buf[2] ;
    
    for (int i = 0 ; fread(buf, 2, 1, file) == 1 ; i ++) {
        
        printf("%02x%02x ", buf[0],buf[1]);

        if (i % 8 == 0) {
            printf("\n");
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