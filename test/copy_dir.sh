echo "test copy_dir.c"

rm -rf ./output/copy_dir1
mkdir ./output/copy_dir1
../bin/copy_dir ./input/dir1/ ./output/copy_dir1/

output=`diff -r ./input/dir1/ ./output/copy_dir1/`

if [ "$output" = "" ]; then
    echo "correct answer"
else   
    echo "wrong answer"
fi