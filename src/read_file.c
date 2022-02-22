int
read_file (FILE * file) {

    long lSize;
    char * buffer;
    size_t result;

    fseek(file, 0, SEEK_END);
    lSize = ftell(file);
    rewind(file);

    buffer = (char *) malloc (sizeof(char) * lSize);
    if (buffer == NULL) {
        fputs("Memory error", stderr);
        return 2;
    }

    result = fread(buffer, 1, lSize, file);
    if (result != lSize) {
        fputs("Reading error", stderr);
        return 3;
    }

    for (int i = 0 ; i < lSize ; i ++ ) {
        printf("%x", (unsigned char) buffer[i]);
        if (i % 2 == 0) {
            printf(" ");
        }
        if (i % 16 == 0) {
            printf("\n");
        }
        
    }
    free(buffer);
    return 0;
}
