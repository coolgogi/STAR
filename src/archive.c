#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>
#include "../include/star.h"

int
archive (char * archive_file_name, char * target_directory_path) {
		
	DIR * dir;
	struct dirent * dir_info;

	dir = opendir(target_directory_path);

	if (dir == NULL) {
		perror("archive.c : ");
		return errno;
	}

	while ((dir_info = readdir(dir))) {
		
		if (dir_info->d_name[0] == '.') {
			continue;
		}
		
		char * child_path = (char *) malloc (strlen(target_directory_path) + strlen(dir_info->d_name) + 2);
		sprintf(child_path, "%s%s", target_directory_path, dir_info->d_name);	
		
		if (dir_info->d_type == DT_DIR) {
			strcat(child_path, "/");
			archive(archive_file_name, child_path);
		}
		else {
			struct stat st ;
			stat(child_path, &st);
			
			unsigned int strlen_path = strlen(child_path) ;
			unsigned int * strlen_child_path = &strlen_path ;
			
			unsigned int file_size = st.st_size;
			unsigned int * size_child_file = &file_size ;

			FILE * archive_file_fp = fopen(archive_file_name, "ab+");
			fwrite(strlen_child_path, 1, sizeof(unsigned int), archive_file_fp);
			fwrite(child_path, 1, strlen_path, archive_file_fp);
			fwrite(size_child_file, 1, sizeof(unsigned int), archive_file_fp);

			FILE * read_file_fp = fopen(child_path, "r");
			unsigned char buf[512];
			int n = file_size / 512 ;
			int m = file_size % 512 ;
			for (int i = 0 ; i < n ; i ++) {
				fread(buf, 1, 512, read_file_fp);
				fwrite(buf, 1, 512, archive_file_fp);
			}
			fread(buf, 1, m, read_file_fp);
			fwrite(buf, 1, m, archive_file_fp);

			fclose(read_file_fp);
			fclose(archive_file_fp);

		}

		free(child_path);
	}
	return 0;	
}
