#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int
list (char * archive_file_name) {
	
	FILE * file_read_pointer = fopen(archive_file_name, "r");
	

	while (feof(file_read_pointer) == 0) {
		unsigned char file_length[4];
		fread(file_length, 1, 4, file_read_pointer);

		int n = atoi(file_length);
		char * file_path = (char *) malloc (n);
		fread(file_path, 1, n, file_read_pointer);
		file_path[n] = '\0';
		printf("%s\n", file_path);
		
		unsigned char file_data_length[4];
		fread(file_data_length, 1, 4, file_read_pointer);
		
		int m = atoi(file_data_length);
		char * file_data = (char *) malloc (m);
		fread(file_data, 1, m, file_read_pointer);
		file_data[m] = '\0';

		free(file_data);
		free(file_path);
	}
	
	fclose(file_read_pointer);

	return 0;
}
