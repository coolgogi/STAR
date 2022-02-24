echo "test read_dir.c"

output=`../bin/read_dir ./output/dir1/`
answer=`cat ./output/dir_answer.txt`

if [ "$output" = "$answer" ]; then
    echo "correct answer"
else
    echo "wrong answer"
fi
