all: archive list extract
	gcc src/main.c bin/archive.o bin/list.o bin/extract.o -o bin/star

archive: src/archive.c
	gcc -c src/archive.c -o bin/archive.o
	
list: src/list.c
	gcc -c src/list.c -o bin/list.o

extract: src/extract.c
	gcc -c src/extract.c -o bin/extract.o

file:
	gcc ./src/read_file.c -o ./bin/read_file
	
dir:
	gcc ./src/read_dir.c -o ./bin/read_dir

copy:
	gcc ./src/copy_dir.c -o ./bin/copy_dir

clean:
	rm ./bin/*
