#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/star.h"
#include <unistd.h>

int
main (int argc, char * argv[]) {
	
	if (argc < 2) {
		fprintf(stderr, "Need more arguments\n");
		exit(EXIT_FAILURE);

	}

	if (strcmp(argv[1], "archive") == 0) {
		if (argc != 4) {
			fprintf(stderr, "archive : Invalid arguments\n");
			exit(EXIT_FAILURE);
		}
		if (access(argv[3], F_OK) != 0) {
			fprintf(stderr, "archive : No directory\n");
			exit(EXIT_FAILURE);
		}
	
		archive(argv[2], argv[3]);
	}
	else if (strcmp(argv[1], "list") == 0) {
		if (argc != 3) {
			fprintf(stderr, "list : Invalid arguments\n");
			exit(EXIT_FAILURE);
		}	
		if (access(argv[2], R_OK) != 0) {
			fprintf(stderr, "list : error with star file\n"); 
			exit(EXIT_FAILURE);
		}

		list(argv[2]);
	}
	else if (strcmp(argv[1], "extract") == 0) {
		if (argc != 3) {
			fprintf(stderr, "extract : Invalid arguments\n");
			exit(EXIT_FAILURE);
		}
		if (access(argv[2], R_OK) != 0) {
			fprintf(stderr, "extract : error with star file\n");
			exit(EXIT_FAILURE);
		}

		extract(argv[2]);
	}
	else {
		fprintf(stderr, "no arguments : Invalid arguments\n");
		exit(EXIT_FAILURE);
	}

	return 0;
}
