all:

dir:
	gcc ./src/read_file.c -o ./bin/read_file
	
file:
	gcc ./src/read_dir.c -o ./bin/read_dir

copy:
	gcc ./src/read_copy.c -o ./bin/read_copy

clean:
	rm ./bin/read_dir
	rm ./bin/read_file
	rm ./bin/read_copy