echo "extract function test"

../bin/star extract output/archive_output

output=`cat star_extract/*`
answer=`cat output/extract_answer`

if [ "$answer" = "$output" ] ; then
	echo "correct result"
else
	echo "wrong result"
fi
