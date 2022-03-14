echo "list function test"


output=`../bin/star list input/list_testcase`
answer=`cat output/list_answer`

if [ "$answer" = "$output" ] ; then
	echo "correct result"
else
	echo "wrong result"
fi
