#!/bin/bash

find ../wordcount-dynamic ./wordcount-cpp &>/dev/null
if [ $? -ne 0 ] ; then
    echo "Provide program program ../wordcount-dynamic and ./wordcount-cpp." 1>&2
    exit 1
fi

export LD_LIBRARY_PATH=${PWD%/*}:$LD_LIBRARY_PATH
RESULT1=
RESULT2=
declare -A ARGS

TIME=$(date +"%T")

printf "test run at: $TIME\n\n" | tee wc_err_log >wc_log

ARGS[1]="<test.txt"
ARGS[2]="<pg.txt"
ARGS[3]="<num_seq.txt"
ARGS[4]="</usr/share/dict/words"
ARGS[5]="<SHtest.txt"
ARGS[6]="<test2.txt"
ARGS[7]="<test3.txt"
ARGS[8]="<test4.txt"
ARGS[9]="<test5.txt"
ARGS[10]="<test6.txt"

for i in {1..10}; do

    echo "===test $i with file ${ARGS[$i]}" >tmp_log
    eval "diff <(valgrind --leak-check=full --error-exitcode=2 ../wordcount-dynamic ${ARGS[$i]} 2> >(grep -E \"(in\ use\ at\ exit|total\ heap\ usage|ERROR\ SUMMARY|get_word)\" >>tmp_log) | sort; echo \"\${PIPESTATUS[0]}\" >tmp_ret_val) <(./wordcount-cpp ${ARGS[$i]} | sort 2>/dev/null) >>tmp_log"
    RES1=$?
    RES2=$(cat tmp_ret_val)
    cat <tmp_log >>wc_log

    if [ $RES1 -eq 0 ] && [ $RES2 -eq 0 ] ;then
        printf "===run successfuly\n\n" >>wc_log
    elif [ $RES1 -eq 0 ] && [ $RES2 -eq 2 ] ;then
        cat <tmp_log >>wc_err_log
        printf "===failed with memory leaks\n\n" | tee -a wc_err_log >>wc_log
    elif [ $RES1 -eq 1 ] && [ $RES2 -ne 2 ] ;then
        cat <tmp_log >>wc_err_log
        printf "===failed with printed data, check the error message\n\n" | tee -a wc_err_log >>wc_log
    elif [ $RES1 -eq 1 ] && [ $RES2 -eq 2 ] ;then
        cat <tmp_log >>wc_err_log
        printf "===failed with printed data and memory leaks\n\n" | tee -a wc_err_log >>wc_log
    fi


done

rm tmp_ret_val tmp_log

#diff <(valgrind ./tail <./tail_test_dir/test4.1.txt 2> >(grep "test") | sort; echo "${PIPESTATUS[0]}" >tmpf) <(./tail_test_dir/test1.txt)