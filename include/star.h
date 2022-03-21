
typedef struct STAR_HEADER {

	unsigned char filePath_length[4];
	unsigned char * filePath;
	unsigned char fileSize[4];

} header;


int archive (char *, char *);
int list (char *);
int extract (char *);
