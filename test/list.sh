echo "list function test"


output=`../bin/star list input/list_input`
answer=`cat output/list_answer`

if [ "$answer" = "$output" ] ; then
	echo "correct result"
else
	echo "wrong result"
fi
