echo "extract function test"

output=`../bin/star extract input/extract_testcase`
answer=`cat output/extract_answer`

if [ "$answer" = "$output" ] ; then
	echo "correct result"
else
	echo "wrong result"
fi
