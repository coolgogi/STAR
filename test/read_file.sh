echo "test case 1 read_file.c (byte to hexa)"

output=`../bin/read_file ../test/read_file.sh`
xxd -ps ../test/read_file.sh ./output/xxd_answer.txt
answer=`cat ./output/xxd_answer.txt`

if [ "$answer" = "$output" ]; then
    echo "correct answer"
else
    echo "wrong answer"
fi

echo "test case 2 read_file.c (byte to hexa)"

output=`../bin/read_file ../bin/read_dir`
xxd -ps ../bin/read_dir ./output/xxd_answer.txt
answer=`cat ./output/xxd_answer.txt`

if [ "$answer" = "$output" ]; then
    echo "correct answer"
else
    echo "wrong answer"
fi