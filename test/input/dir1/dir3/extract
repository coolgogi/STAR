#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

int
extract (char * archive_file_name) {
		
	FILE * fp = fopen(archive_file_name, "r");
	
	if (access("./star_extract", F_OK) == -1){
		mode_t mode = S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH ;
		if (mkdir("./star_extract", mode) == -1) {
			perror("mkdir error in extract");
			return errno;
		}	
	}
	int index = 0;

	unsigned int * file_length_ptr = (unsigned int *) malloc (sizeof(unsigned int)) ;
	unsigned int * file_data_length_ptr = (unsigned int *) malloc (sizeof(unsigned int));
	while (fread(file_length_ptr, 1, sizeof(unsigned int), fp) == 4)
	{

		unsigned int file_length = * file_length_ptr ;
		unsigned char * file_path = (unsigned char *) malloc (file_length);
		fread(file_path, 1, file_length, fp);
		
		unsigned char * new_file = (unsigned char *) malloc (file_length + 13);
		sprintf(new_file, "star_extract/%d", index); 
		index++;
		FILE * new_fp = fopen(new_file, "w+");
	
		fread(file_data_length_ptr, 1, sizeof(unsigned int), fp);
		unsigned int file_data_length = * file_data_length_ptr ;
	
		unsigned char file_data[512] ;
		int n = file_data_length / 512 ;
		int m = file_data_length % 512 ;
		for (int i = 0 ; i < n ; i ++) {
			fread(file_data, 1, 512, fp) ;
			fwrite(file_data, 1, 512, new_fp) ;
		}
		fread(file_data, 1, m, fp) ;
		fwrite(file_data, 1, m, new_fp) ;
		
		
		fclose(new_fp);
		free(new_file);
		free(file_path);	
	}
	free(file_data_length_ptr);
	free(file_length_ptr);
	return 0;
}
