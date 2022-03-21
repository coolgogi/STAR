echo "list function test"

output=`../bin/star list output/archive_output`
answer=`cat output/list_answer`

if [ "$answer" = "$output" ] ; then
	echo "correct result"
else
	echo "wrong result"
fi
