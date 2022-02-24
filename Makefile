all:

hexa:
	gcc ./src/read_file.c -o ./bin/read_file
	xxd -i ./bin/read_file ./test/output/xxd_output.txt
	
rec:
	gcc ./src/read_dir.c -o ./bin/read_dir

clean:
	rm ./bin/read_dir
	rm ./bin/read_file