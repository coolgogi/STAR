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
	int i = 0;

	unsigned int * file_length_ptr = (unsigned int *) malloc (sizeof(unsigned int)) ;
	unsigned int * file_data_length_ptr = (unsigned int *) malloc (sizeof(unsigned int));
	while (fread(file_length_ptr, 1, 4, fp) == 4)
	{

		unsigned int file_length = * file_length_ptr ;
		unsigned char * file_path = (unsigned char *) malloc (file_length);
		fread(file_path, 1, file_length, fp);
		file_path[file_length] = '\0';
		

		fread(file_data_length_ptr, 1, 4, fp);
		unsigned int file_data_length = * file_data_length_ptr ;
		unsigned char * file_data = (unsigned char *) malloc (file_data_length);
		fread(file_data, 1, file_data_length, fp);
		file_data[file_data_length] = '\0';
				
		unsigned char * new_file = (unsigned char *) malloc (file_length + 13);
		sprintf(new_file, "star_extract/%d", i); 
		i++;
		FILE * new_fp = fopen(new_file, "w+");
		
		fwrite(file_data, 1, file_data_length, new_fp);
		
		fclose(new_fp);
		free(new_file);
		free(file_data);
		free(file_path);	
	}
	free(file_data_length_ptr);
	free(file_length_ptr);
	return 0;
}
