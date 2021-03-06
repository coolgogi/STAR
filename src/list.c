#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int
list (char * archive_file_name) {
	
	FILE * file_read_pointer = fopen(archive_file_name, "r") ;	
	unsigned int * file_length_ptr = (unsigned int *) malloc (sizeof(unsigned int)) ;
	unsigned int * file_size_ptr = (unsigned int *) malloc (sizeof(unsigned int)) ;

	while (fread(file_length_ptr, 1, sizeof(unsigned int), file_read_pointer) == 4) {
	
		unsigned int file_length = *file_length_ptr ;
		char * file_path = (char *) malloc (file_length) ;
		fread(file_path, 1, file_length, file_read_pointer) ;
		file_path[file_length] = '\0' ;
		
		printf("%s\n", file_path) ;

		fread(file_size_ptr, 1, sizeof(unsigned int), file_read_pointer) ;

		unsigned int file_size = *file_size_ptr ;		
		unsigned char buf[512];
                int n = file_size / 512 ;
                int m = file_size % 512 ;
                for (int i = 0 ; i < n ; i ++) {
                        fread(buf, 1, 512, file_read_pointer);
                }
                fread(buf, 1, m, file_read_pointer);

		free(file_path) ;
	}

	free(file_size_ptr);
	free(file_length_ptr);
	fclose(file_read_pointer);

	return 0;
}
