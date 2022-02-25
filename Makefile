all:

file:
	gcc ./src/read_file.c -o ./bin/read_file
	
dir:
	gcc ./src/read_dir.c -o ./bin/read_dir

copy:
	gcc ./src/copy_dir.c -o ./bin/copy_dir

clean:
	rm ./bin/read_dir
	rm ./bin/read_file
	rm ./bin/copy_dir