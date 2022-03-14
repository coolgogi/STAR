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

	unsigned char file_length[4];
	while (fread(file_length, 1, 4, fp) == 4)
	{

		int n = atoi(file_length);
		unsigned char * file_path = (unsigned char *) malloc (n);
		fread(file_path, 1, n, fp);
		file_path[n] = '\0';
		
		unsigned char file_data_length[4];
		fread(file_data_length, 1, 4, fp);
		
		int m = atoi(file_data_length);
		char * file_data = (unsigned char *) malloc (m);
		fread(file_data, 1, m, fp);
		file_data[m] = '\0';
				
		unsigned char * new_file = (unsigned char *) malloc (n + 13);
		strcpy(new_file, "star_extract/");
		sprintf(new_file, "star_extract/%d", i); 
		i++;
		FILE * new_fp = fopen(new_file, "w");
		
		fwrite(file_data, 1, m, new_fp);
		
		free(new_file);
		fclose(new_fp);
		free(file_data);
		free(file_path);	
	}
	return 0;
}
