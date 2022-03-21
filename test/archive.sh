echo "archive function test"

rm output/archive_output
../bin/star archive output/archive_output input/dir1/

output=`cat output/archive_output`
answer=`cat output/archive_answer`

if [ "$answer" = "$output" ] ; then
	echo "correct result"
else
	echo "wrong result"
fi
