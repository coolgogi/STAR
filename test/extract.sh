echo "extract function test"

../bin/star extract output/archive_output

wc -c  star_extract/2
wc -c ../src/main.c
output1=`cat star_extract/2`
answer1=`cat ../src/main.c`
if [ "$output1" = "$answer1" ] ; then
	echo "correct answer"
else
	echo "wrong answer"
fi

wc -c star_extract/5
wc -c ../src/list.c
output2=`cat star_extract/5`
answer2=`cat ../src/list.c`
if [ "$output2" = "$answer2" ] ; then
	echo "correct answer"
else
	echo "wrong answer"
fi

wc -c star_extract/9
wc -c ../src/archive.c
output3=`cat star_extract/9`
answer3=`cat ../src/archive.c`
if [ "$output3" = "$answer3" ] ; then
	echo "correct answer"
else
	echo "wrong answer"
fi

wc -c star_extract/10
wc -c ../src/extract.c
output4=`cat star_extract/10`
answer4=`cat ../src/extract.c`
if [ "$output4" = "$answer4" ] ; then
	echo "correct answer"
else
	echo "wrong answer"
fi
