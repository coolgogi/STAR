#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int
ReadByteAndPrintHexa (FILE * file) {

    unsigned char buf ;
    for (int i = 1 ; fread(&buf, 1, 1, file) == 1 ; i ++) {

        printf("%02x", buf);
        if ((i != 1) && (i % 30 == 0)) {
            printf("\n");
        }
    }
    printf("\n");
    return 0 ;
}


int
main (int argc, char * argv[]) {
    if (argc != 2) {
        printf("invalid argument\n");
        exit(EXIT_FAILURE);
    }

    FILE * fp;
    fp = fopen(argv[1], "r");

    if (fp == NULL) {
        perror("fopen error");
        return errno;
    }

    ReadByteAndPrintHexa(fp);
    fclose(fp);

    return 0;

}