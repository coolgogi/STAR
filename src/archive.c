#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>

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
			
			/*
			if (st.st_mode != S_IFREG) {
				continue;
			}	
			*/
			
			char * strlen_child_path = (char *) malloc (4);
			memset(strlen_child_path, 0, 4);
			sprintf(strlen_child_path, "%zu", strlen(child_path));
			char * size_child_file = (char *) malloc (4);
			memset(size_child_file, 0, 4);
			sprintf(size_child_file, "%zu", st.st_size);

			FILE * archive_file_fp = fopen(archive_file_name, "a+");
			fwrite(strlen_child_path, 1, 4, archive_file_fp);
			fwrite(child_path, 1, strlen(child_path), archive_file_fp);
			fwrite(size_child_file, 1, 4, archive_file_fp);
			
			FILE * read_file_fp = fopen(child_path, "r");
			unsigned char buf;
			
			while (fread(&buf, 1, 1, read_file_fp) == 1) {
				fwrite(&buf, 1, 1, archive_file_fp);
			}
			
			fclose(read_file_fp);
			fclose(archive_file_fp);
			free(size_child_file);	
			free(strlen_child_path);

		}

		free(child_path);
	}
	return 0;	
}
