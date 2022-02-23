echo "test read_dir.c"

./../bin/read_dir ./../test/output/dir1/

echo "
dir1
|-----dir2
|	|-----dir4
|	|	|-text6.txt
|	|	\-text7.txt
|       |
|	|-text3.txt
|	|-text4.txt
|	\-text5.txt
|
|-----dir3
|	|-text7.txt
|	\-text8.txt
|
|-text1.txt
\-text2.txt
"