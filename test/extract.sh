echo "extract function test"

../bin/star extract output/archive_output

wc -c  star_extract/2
wc -c ../src/main.c

wc -c star_extract/5
wc -c ../src/list.c

wc -c star_extract/9
wc -c ../src/archive.c

wc -c star_extract/10
wc -c ../src/extract.c
