#!/bin/bash

find ../tail &>/dev/null
if [ $? -ne 0 ] ; then
    echo "Provide program tail." 1>&2
    exit 1
fi

RESULT1=
RESULT2=
declare -A ARGS

TIME=$(date +"%T")

printf "test run at: $TIME\n\n" | tee tail_err_log tail_false_positive_log >tail_log

ARGS[1]=""
ARGS[2]="-n 5"
ARGS[3]="-n12"
ARGS[4]="-n13 -a"
ARGS[5]="-nb4"
ARGS[6]="-cn 3"
ARGS[7]="-n-3"
ARGS[8]="-n 0"
ARGS[9]="-n+0"
ARGS[10]="-n +25"
ARGS[11]="-n +90"
ARGS[12]="-n 85"
ARGS[13]="-n +1"
ARGS[14]="-n 1"
ARGS[15]="-n -1"
ARGS[16]="-n-5"

ARGS[17]="test1.txt test2.txt test3.txt"
ARGS[18]="test5.txt test6.txt test7.txt test8.txt"
ARGS[19]="test0.txt test1.txt test2.txt test3.txt test4.1.txt test4.2.txt test4.3.txt test4.4.txt test5.txt test6.txt test7.txt test8.txt test9.txt"
ARGS[20]="unknown_file"
ARGS[21]="test1.txt unknown_file1 test3.txt unknown_file2 test5.txt test8.txt"
ARGS[22]="test1.txt test3.txt unknown_file"
ARGS[23]="unknown_file test1.txt test3.txt"
ARGS[24]="unreadable"
ARGS[25]="test1.txt unreadable test3.txt"
ARGS[26]="unreadable test1.txt test3.txt"
ARGS[27]="test1.txt test3.txt unreadable"
ARGS[28]="test8.txt test5.txt test0.txt"
ARGS[29]="test1.txt test1.txt test1.txt test1.txt"
ARGS[30]="test4.1.txt test4.2.txt test4.3.txt test4.4.txt"
ARGS[31]="-n 18 test1.txt test2.txt test3.txt"
ARGS[32]="-n 18 test5.txt test6.txt test7.txt test8.txt"
ARGS[33]="-n 18 test0.txt test1.txt test2.txt test3.txt test4.1.txt test4.2.txt test4.3.txt test4.4.txt test5.txt test6.txt test7.txt test8.txt test9.txt"
ARGS[34]="-n 18 unknown_file"
ARGS[35]="-n18 test1.txt unknown_file1 test3.txt unknown_file2 test5.txt test8.txt"
ARGS[36]="-n18 test1.txt test3.txt unknown_file"
ARGS[37]="-n18 unknown_file test1.txt test3.txt"
ARGS[38]="-n18 unreadable"
ARGS[39]="-n 18 test1.txt unreadable test3.txt"
ARGS[40]="-n 18 unreadable test1.txt test3.txt"
ARGS[41]="-n 18 test1.txt test3.txt unreadable"
ARGS[42]="-n 18 test8.txt test5.txt test0.txt"
ARGS[43]="-n 18 test1.txt test1.txt test1.txt test1.txt"
ARGS[44]="-n 18 test4.1.txt test4.2.txt test4.3.txt test4.4.txt"
ARGS[45]="-n+12 test1.txt test2.txt test3.txt"
ARGS[46]="-n+12 test5.txt test6.txt test7.txt test8.txt"
ARGS[47]="-n+12 test0.txt test1.txt test2.txt test3.txt test4.1.txt test4.2.txt test4.3.txt test4.4.txt test5.txt test6.txt test7.txt test8.txt test9.txt"
ARGS[48]="-n+12 unknown_file"
ARGS[49]="-n +12 test1.txt unknown_file1 test3.txt unknown_file2 test5.txt test8.txt"
ARGS[50]="-n +12 test1.txt test3.txt unknown_file"
ARGS[51]="-n +12 unknown_file test1.txt test3.txt"
ARGS[52]="-n +12 unreadable"
ARGS[53]="-n +12 test1.txt unreadable test3.txt"
ARGS[54]="-n +12 unreadable test1.txt test3.txt"
ARGS[55]="-n +12 test1.txt test3.txt unreadable"
ARGS[56]="-n +12 test8.txt test5.txt test0.txt"
ARGS[57]="-n +12 test1.txt test1.txt test1.txt test1.txt"
ARGS[58]="-n +12 test4.1.txt test4.2.txt test4.3.txt test4.4.txt"
ARGS[59]="-n 0 test1.txt test2.txt test3.txt"
ARGS[60]="-n0 test5.txt test6.txt test7.txt test8.txt"
ARGS[61]="-n0 test0.txt test1.txt test2.txt test3.txt test4.1.txt test4.2.txt test4.3.txt test4.4.txt test5.txt test6.txt test7.txt test8.txt test9.txt"
ARGS[62]="-n0 unknown_file"
ARGS[63]="-n0 test1.txt unknown_file1 test3.txt unknown_file2 test5.txt test8.txt"
ARGS[64]="-n0 test1.txt test3.txt unknown_file"
ARGS[65]="-n0 unknown_file test1.txt test3.txt"
ARGS[66]="-n0 unreadable"
ARGS[67]="-n0 test1.txt unreadable test3.txt"
ARGS[68]="-n0 unreadable test1.txt test3.txt"
ARGS[69]="-n0 test1.txt test3.txt unreadable"
ARGS[70]="-n 0 test8.txt test5.txt test0.txt"
ARGS[71]="-n 0 test1.txt test1.txt test1.txt test1.txt"
ARGS[72]="-n 0 test4.1.txt test4.2.txt test4.3.txt test4.4.txt"
ARGS[73]="-n+0 test1.txt test2.txt test3.txt"
ARGS[74]="-n+0 test5.txt test6.txt test7.txt test8.txt"
ARGS[75]="-n+0 test0.txt test1.txt test2.txt test3.txt test4.1.txt test4.2.txt test4.3.txt test4.4.txt test5.txt test6.txt test7.txt test8.txt test9.txt"
ARGS[76]="-n+0 unknown_file"
ARGS[77]="-n+0 test1.txt unknown_file1 test3.txt unknown_file2 test5.txt test8.txt"
ARGS[78]="-n+0 test1.txt test3.txt unknown_file"
ARGS[79]="-n +0 unknown_file test1.txt test3.txt"
ARGS[80]="-n +0 unreadable"
ARGS[81]="-n +0 test1.txt unreadable test3.txt"
ARGS[82]="-n +0 unreadable test1.txt test3.txt"
ARGS[83]="-n +0 test1.txt test3.txt unreadable"
ARGS[84]="-n +0 test8.txt test5.txt test0.txt"
ARGS[85]="-n +0 test1.txt test1.txt test1.txt test1.txt"
ARGS[86]="-n +0 test4.1.txt test4.2.txt test4.3.txt test4.4.txt"
ARGS[87]="-n 1 test1.txt test2.txt test3.txt"
ARGS[88]="-n 1 test5.txt test6.txt test7.txt test8.txt"
ARGS[89]="-n 1 test0.txt test1.txt test2.txt test3.txt test4.1.txt test4.2.txt test4.3.txt test4.4.txt test5.txt test6.txt test7.txt test8.txt test9.txt"
ARGS[90]="-n 1 unknown_file"
ARGS[91]="-n1 test1.txt unknown_file1 test3.txt unknown_file2 test5.txt test8.txt"
ARGS[92]="-n1 test1.txt test3.txt unknown_file"
ARGS[93]="-n1 unknown_file test1.txt test3.txt"
ARGS[94]="-n1 unreadable"
ARGS[95]="-n1 test1.txt unreadable test3.txt"
ARGS[96]="-n 1 unreadable test1.txt test3.txt"
ARGS[97]="-n 1 test1.txt test3.txt unreadable"
ARGS[98]="-n 1 test8.txt test5.txt test0.txt"
ARGS[99]="-n 1 test1.txt test1.txt test1.txt test1.txt"
ARGS[100]="-n 1 test4.1.txt test4.2.txt test4.3.txt test4.4.txt"
ARGS[101]="-n+1 test1.txt test2.txt test3.txt"
ARGS[102]="-n+ 1 test5.txt test6.txt test7.txt test8.txt"
ARGS[103]="-n+ 1 test0.txt test1.txt test2.txt test3.txt test4.1.txt test4.2.txt test4.3.txt test4.4.txt test5.txt test6.txt test7.txt test8.txt test9.txt"
ARGS[104]="-n+ 1 unknown_file"
ARGS[105]="-n+ 1 test1.txt unknown_file1 test3.txt unknown_file2 test5.txt test8.txt"
ARGS[106]="-n+ 1 test1.txt test3.txt unknown_file"
ARGS[107]="-n+1 unknown_file test1.txt test3.txt"
ARGS[108]="-n+1 unreadable"
ARGS[109]="-n+1 test1.txt unreadable test3.txt"
ARGS[110]="-n+1 unreadable test1.txt test3.txt"
ARGS[111]="-n+1 test1.txt test3.txt unreadable"
ARGS[112]="-n+1 test8.txt test5.txt test0.txt"
ARGS[113]="-n+1 test1.txt test1.txt test1.txt test1.txt"
ARGS[114]="-n+1 test4.1.txt test4.2.txt test4.3.txt test4.4.txt"
ARGS[115]="-n 7 test1.txt test2.txt test3.txt"
ARGS[116]="-n 7 test5.txt test6.txt test7.txt test8.txt"
ARGS[117]="-n 7 test0.txt test1.txt test2.txt test3.txt test4.1.txt test4.2.txt test4.3.txt test4.4.txt test5.txt test6.txt test7.txt test8.txt test9.txt"
ARGS[118]="-n 7 unknown_file"
ARGS[119]="-n 7 test1.txt unknown_file1 test3.txt unknown_file2 test5.txt test8.txt"
ARGS[120]="-n 7 test1.txt test3.txt unknown_file"
ARGS[121]="-n 7 unknown_file test1.txt test3.txt"
ARGS[122]="unreadable unknown_file"
ARGS[123]="-n7 unreadable"
ARGS[124]="-n7 test1.txt unreadable test3.txt"
ARGS[125]="-n7 unreadable test1.txt test3.txt"
ARGS[126]="-n7 test1.txt test3.txt unreadable"
ARGS[127]="-n7 test8.txt test5.txt test0.txt"
ARGS[128]="-n7 test1.txt test1.txt test1.txt test1.txt"
ARGS[129]="-n 7 test4.1.txt test4.2.txt test4.3.txt test4.4.txt"
ARGS[130]="-n+7 test1.txt test2.txt test3.txt"
ARGS[131]="-n+7 test5.txt test6.txt test7.txt test8.txt"
ARGS[132]="-n+7 test0.txt test1.txt test2.txt test3.txt test4.1.txt test4.2.txt test4.3.txt test4.4.txt test5.txt test6.txt test7.txt test8.txt test9.txt"
ARGS[133]="-n+7 unknown_file"
ARGS[134]="-n+7 test1.txt unknown_file1 test3.txt unknown_file2 test5.txt test8.txt"
ARGS[135]="-n +7 test1.txt test3.txt unknown_file"
ARGS[136]="-n +7 unknown_file test1.txt test3.txt"
ARGS[137]="-n +7 unreadable"
ARGS[138]="-n +7 test1.txt unreadable test3.txt"
ARGS[139]="-n +7 unreadable test1.txt test3.txt"
ARGS[140]="-n +7 test1.txt test3.txt unreadable"
ARGS[141]="-n +7 test8.txt test5.txt test0.txt"
ARGS[142]="-n +7 test1.txt test1.txt test1.txt test1.txt"
ARGS[143]="-n +7 test4.1.txt test4.2.txt test4.3.txt test4.4.txt"
ARGS[144]="-n 100 test1.txt test2.txt test3.txt"
ARGS[145]="-n 100 test5.txt test6.txt test7.txt test8.txt"
ARGS[146]="-n 100 test0.txt test1.txt test2.txt test3.txt test4.1.txt test4.2.txt test4.3.txt test4.4.txt test5.txt test6.txt test7.txt test8.txt test9.txt"
ARGS[147]="-n 100 unknown_file"
ARGS[148]="-n 100 test1.txt unknown_file1 test3.txt unknown_file2 test5.txt test8.txt"
ARGS[149]="-n 100 test1.txt test3.txt unknown_file"
ARGS[150]="-n 100 unknown_file test1.txt test3.txt"
ARGS[151]="-n 5 unreadable unknown_file"
ARGS[152]="-n +7 unreadable unknown_file"
ARGS[153]="-n 0 unreadable unknown_file"
ARGS[154]="-n +13 test1.txt unreadable test2.txt unknown_file"
ARGS[155]="-n 8 unreadable test1.txt unknown_file"
ARGS[156]="test5.txt unreadable test7.txt unknown_file"
ARGS[157]="-n 90 unreadable test1.txt unknown_file"
ARGS[158]="-n +50 unreadable unknown_file test1.txt"
ARGS[159]="-n +51 unreadable test1.txt unknown_file"
ARGS[160]="-n 100 unreadable"
ARGS[161]="-n 100 test1.txt unreadable test3.txt"
ARGS[162]="-n100 unreadable test1.txt test3.txt"
ARGS[163]="-n100 test1.txt test3.txt unreadable"
ARGS[164]="-n100 test8.txt test5.txt test0.txt"
ARGS[165]="-n100 test1.txt test1.txt test1.txt test1.txt"
ARGS[166]="-n100 test4.1.txt test4.2.txt test4.3.txt test4.4.txt"
ARGS[167]="-n +100 test1.txt test2.txt test3.txt"
ARGS[168]="-n +100 test5.txt test6.txt test7.txt test8.txt"
ARGS[169]="-n +100 test0.txt test1.txt test2.txt test3.txt test4.1.txt test4.2.txt test4.3.txt test4.4.txt test5.txt test6.txt test7.txt test8.txt test9.txt"
ARGS[170]="-n +100 unknown_file"
ARGS[171]="-n +100 test1.txt unknown_file1 test3.txt unknown_file2 test5.txt test8.txt"
ARGS[172]="-n+100 test1.txt test3.txt unknown_file"
ARGS[173]="-n+100 unknown_file test1.txt test3.txt"
ARGS[174]="-n+100 unreadable"
ARGS[175]="-n+100 test1.txt unreadable test3.txt"
ARGS[176]="-n+100 unreadable test1.txt test3.txt"
ARGS[177]="-n+100 test1.txt test3.txt unreadable"
ARGS[178]="-n +100 test8.txt test5.txt test0.txt"
ARGS[179]="-n +100 test1.txt test1.txt test1.txt test1.txt"
ARGS[180]="-n +100 test4.1.txt test4.2.txt test4.3.txt test4.4.txt"


print_result(){
    if [ $1 -eq 0 ] && [ $2 -eq 0 ]; then
        printf "===run successfuly\n\n" >>tail_log
    elif [ $1 -eq 0 ] && [ $2 -eq 1 ]; then
        cat <tmp_log >>tail_false_positive_log
        printf "===run successfuly, but the exit code of 'tail' indicates and error, check the error message\n\n" | tee -a tail_false_positive_log >>tail_log
    elif [ $1 -eq 1 ] && [ $2 -eq 1 ]; then
        cat <tmp_log >>tail_false_positive_log
        printf "===failed with printed data, check the error message, the test might be false positive\n\n" | tee -a tail_false_positive_log >>tail_log
    elif [ $1 -eq 1 ] && [ $2 -eq 2 ]; then
        cat <tmp_log >>tail_err_log
        printf "===failed with printed data and also with memory leaks\n\n" | tee -a tail_err_log >>tail_log
    elif [ $1 -ne 0 ]; then 
        cat <tmp_log >>tail_err_log
        printf "===failed only with printed data\n\n" | tee -a tail_err_log >>tail_log
    elif [ $2 -eq 2 ]; then
        cat <tmp_log >>tail_err_log
        printf "===failed only with memory leaks\n\n" | tee -a tail_err_log >>tail_log
    fi
}

for i in {1..16}; do
    ### test .0 ###
    echo "===test $i.0: with arguments: \"${ARGS[$i]}\", with a file from stdin: test0.txt" >tmp_log
    #compare the output with GNU tail, checks the program with valgrind
    eval "diff <(valgrind --leak-check=full --error-exitcode=2 ../tail ${ARGS[$i]} <test0.txt 2> >(grep -E \"(in\ use\ at\ exit|total\ heap\ usage|ERROR\ SUMMARY|tail:)\" >>tmp_log); echo \"\${PIPESTATUS[0]}\" >tmp_ret_val) <(tail ${ARGS[$i]} <test0.txt 2>/dev/null) >>tmp_log"
    RESULT1=$?
    #reads from temporary files
    RESULT2=$(cat <tmp_ret_val)
    cat <tmp_log >>tail_log
    print_result $RESULT1 $RESULT2

    echo "===test $i.1: with arguments: \"${ARGS[$i]}\", with a file: test1.txt" >tmp_log
    #compare the output with GNU tail, checks the program with valgrind
    eval "diff <(valgrind --leak-check=full --error-exitcode=2 ../tail ${ARGS[$i]} test1.txt 2> >(grep -E \"(in\ use\ at\ exit|total\ heap\ usage|ERROR\ SUMMARY|tail:)\" >>tmp_log); echo \"\${PIPESTATUS[0]}\" >tmp_ret_val) <(tail ${ARGS[$i]} test1.txt 2>/dev/null) >>tmp_log"
    RESULT1=$?
    #reads from temporary files
    RESULT2=$(cat <tmp_ret_val)
    cat <tmp_log >>tail_log
    print_result $RESULT1 $RESULT2

    ### test .1 ###
    echo "===test $i.1: with arguments: \"${ARGS[$i]}\", with a file from stdin: test1.txt" >tmp_log
    eval "diff <(valgrind --leak-check=full --error-exitcode=2 ../tail ${ARGS[$i]} <test1.txt 2> >(grep -E \"(in\ use\ at\ exit|total\ heap\ usage|ERROR\ SUMMARY|tail:)\" >>tmp_log); echo \"\${PIPESTATUS[0]}\" >tmp_ret_val) <(tail ${ARGS[$i]} <test1.txt 2>/dev/null) >>tmp_log"
    RESULT1=$?
    RESULT2=$(cat <tmp_ret_val)
    cat <tmp_log >>tail_log
    print_result $RESULT1 $RESULT2

    echo "===test $i.1: with arguments: \"${ARGS[$i]}\", with a file: test1.txt" >tmp_log
    eval "diff <(valgrind --leak-check=full --error-exitcode=2 ../tail ${ARGS[$i]} test1.txt 2> >(grep -E \"(in\ use\ at\ exit|total\ heap\ usage|ERROR\ SUMMARY|tail:)\" >>tmp_log); echo \"\${PIPESTATUS[0]}\" >tmp_ret_val) <(tail ${ARGS[$i]} test1.txt 2>/dev/null) >>tmp_log"
    RESULT1=$?
    RESULT2=$(cat <tmp_ret_val)
    cat <tmp_log >>tail_log
    print_result $RESULT1 $RESULT2

    ### test .2 ###
    echo "===test $i.2: with arguments: \"${ARGS[$i]}\", with a file from stdin: test2.txt" >tmp_log
    eval "diff <(valgrind --leak-check=full --error-exitcode=2 ../tail ${ARGS[$i]} <test2.txt 2> >(grep -E \"(in\ use\ at\ exit|total\ heap\ usage|ERROR\ SUMMARY|tail:)\" >>tmp_log); echo \"\${PIPESTATUS[0]}\" >tmp_ret_val) <(tail ${ARGS[$i]} <test2.txt 2>/dev/null) >>tmp_log"
    RESULT1=$?
    RESULT2=$(cat <tmp_ret_val)
    cat <tmp_log >>tail_log
    print_result $RESULT1 $RESULT2

    echo "===test $i.2: with arguments: \"${ARGS[$i]}\", with a file: test2.txt" >tmp_log
    eval "diff <(valgrind --leak-check=full --error-exitcode=2 ../tail ${ARGS[$i]} test2.txt 2> >(grep -E \"(in\ use\ at\ exit|total\ heap\ usage|ERROR\ SUMMARY|tail:)\" >>tmp_log); echo \"\${PIPESTATUS[0]}\" >tmp_ret_val) <(tail ${ARGS[$i]} test2.txt 2>/dev/null) >>tmp_log"
    RESULT1=$?
    RESULT2=$(cat <tmp_ret_val)
    cat <tmp_log >>tail_log
    print_result $RESULT1 $RESULT2

    ### test .3 ###
    echo "===test $i.3: with arguments: \"${ARGS[$i]}\", with a file from stdin: test3.txt" >tmp_log
    eval "diff <(valgrind --leak-check=full --error-exitcode=2 ../tail ${ARGS[$i]} <test3.txt 2> >(grep -E \"(in\ use\ at\ exit|total\ heap\ usage|ERROR\ SUMMARY|tail:)\" >>tmp_log); echo \"\${PIPESTATUS[0]}\" >tmp_ret_val) <(tail ${ARGS[$i]} <test3.txt 2>/dev/null) >>tmp_log"
    RESULT1=$?
    RESULT2=$(cat <tmp_ret_val)
    cat <tmp_log >>tail_log
    print_result $RESULT1 $RESULT2

    echo "===test $i.3: with arguments: \"${ARGS[$i]}\", with a file: test3.txt" >tmp_log
    eval "diff <(valgrind --leak-check=full --error-exitcode=2 ../tail ${ARGS[$i]} test3.txt 2> >(grep -E \"(in\ use\ at\ exit|total\ heap\ usage|ERROR\ SUMMARY|tail:)\" >>tmp_log); echo \"\${PIPESTATUS[0]}\" >tmp_ret_val) <(tail ${ARGS[$i]} test3.txt 2>/dev/null) >>tmp_log"
    RESULT1=$?
    RESULT2=$(cat <tmp_ret_val)
    cat <tmp_log >>tail_log
    print_result $RESULT1 $RESULT2

    ### test .4.1 ###
    echo "===test $i.4.1: with arguments: \"${ARGS[$i]}\", with a file from stdin: test4.1.txt" >tmp_log
    eval "diff <(valgrind --leak-check=full --error-exitcode=2 ../tail ${ARGS[$i]} <test4.1.txt 2> >(grep -E \"(in\ use\ at\ exit|total\ heap\ usage|ERROR\ SUMMARY|tail:)\" >>tmp_log); echo \"\${PIPESTATUS[0]}\" >tmp_ret_val) <(tail ${ARGS[$i]} <test4.1.txt 2>/dev/null) >>tmp_log"
    RESULT1=$?
    RESULT2=$(cat <tmp_ret_val)
    cat <tmp_log >>tail_log
    print_result $RESULT1 $RESULT2

    echo "===test $i.4.1: with arguments: \"${ARGS[$i]}\", with a file: test4.1.txt" >tmp_log
    eval "diff <(valgrind --leak-check=full --error-exitcode=2 ../tail ${ARGS[$i]} test4.1.txt 2> >(grep -E \"(in\ use\ at\ exit|total\ heap\ usage|ERROR\ SUMMARY|tail:)\" >>tmp_log); echo \"\${PIPESTATUS[0]}\" >tmp_ret_val) <(tail ${ARGS[$i]} test4.1.txt 2>/dev/null) >>tmp_log"
    RESULT1=$?
    RESULT2=$(cat <tmp_ret_val)
    cat <tmp_log >>tail_log
    print_result $RESULT1 $RESULT2

    ### test .4.2 ###
    echo "===test $i.4.2: with arguments: \"${ARGS[$i]}\", with a file from stdin: test4.2.txt" >tmp_log
    eval "diff <(valgrind --leak-check=full --error-exitcode=2 ../tail ${ARGS[$i]} <test4.2.txt 2> >(grep -E \"(in\ use\ at\ exit|total\ heap\ usage|ERROR\ SUMMARY|tail:)\" >>tmp_log); echo \"\${PIPESTATUS[0]}\" >tmp_ret_val) <(tail ${ARGS[$i]} <test4.2.txt 2>/dev/null) >>tmp_log"
    RESULT1=$?
    RESULT2=$(cat <tmp_ret_val)
    cat <tmp_log >>tail_log
    print_result $RESULT1 $RESULT2

    echo "===test $i.4.2: with arguments: \"${ARGS[$i]}\", with a file: test4.2.txt" >tmp_log
    eval "diff <(valgrind --leak-check=full --error-exitcode=2 ../tail ${ARGS[$i]} test4.2.txt 2> >(grep -E \"(in\ use\ at\ exit|total\ heap\ usage|ERROR\ SUMMARY|tail:)\" >>tmp_log); echo \"\${PIPESTATUS[0]}\" >tmp_ret_val) <(tail ${ARGS[$i]} test4.2.txt 2>/dev/null) >>tmp_log"
    RESULT1=$?
    RESULT2=$(cat <tmp_ret_val)
    cat <tmp_log >>tail_log
    print_result $RESULT1 $RESULT2

    ### test .4.3 ###
    echo "===test $i.4.3: with arguments: \"${ARGS[$i]}\", with a file from stdin: test4.3.txt" >tmp_log
    eval "diff <(valgrind --leak-check=full --error-exitcode=2 ../tail ${ARGS[$i]} <test4.3.txt 2> >(grep -E \"(in\ use\ at\ exit|total\ heap\ usage|ERROR\ SUMMARY|tail:)\" >>tmp_log); echo \"\${PIPESTATUS[0]}\" >tmp_ret_val) <(tail ${ARGS[$i]} <test4.3.txt 2>/dev/null) >>tmp_log"
    RESULT1=$?
    RESULT2=$(cat <tmp_ret_val)
    cat <tmp_log >>tail_log
    print_result $RESULT1 $RESULT2

    echo "===test $i.4.3: with arguments: \"${ARGS[$i]}\", with a file: test4.3.txt" >tmp_log
    eval "diff <(valgrind --leak-check=full --error-exitcode=2 ../tail ${ARGS[$i]} test4.3.txt 2> >(grep -E \"(in\ use\ at\ exit|total\ heap\ usage|ERROR\ SUMMARY|tail:)\" >>tmp_log); echo \"\${PIPESTATUS[0]}\" >tmp_ret_val) <(tail ${ARGS[$i]} test4.3.txt 2>/dev/null) >>tmp_log"
    RESULT1=$?
    RESULT2=$(cat <tmp_ret_val)
    cat <tmp_log >>tail_log
    print_result $RESULT1 $RESULT2

    ### test .4.4 ###
    echo "===test $i.4.4: with arguments: \"${ARGS[$i]}\", with a file from stdin: test4.4.txt" >tmp_log
    eval "diff <(valgrind --leak-check=full --error-exitcode=2 ../tail ${ARGS[$i]} <test4.4.txt 2> >(grep -E \"(in\ use\ at\ exit|total\ heap\ usage|ERROR\ SUMMARY|tail:)\" >>tmp_log); echo \"\${PIPESTATUS[0]}\" >tmp_ret_val) <(tail ${ARGS[$i]} <test4.4.txt 2>/dev/null) >>tmp_log"
    RESULT1=$?
    RESULT2=$(cat <tmp_ret_val)
    cat <tmp_log >>tail_log
    print_result $RESULT1 $RESULT2

    echo "===test $i.4.4: with arguments: \"${ARGS[$i]}\", with a file: test4.4.txt" >tmp_log
    eval "diff <(valgrind --leak-check=full --error-exitcode=2 ../tail ${ARGS[$i]} test4.4.txt 2> >(grep -E \"(in\ use\ at\ exit|total\ heap\ usage|ERROR\ SUMMARY|tail:)\" >>tmp_log); echo \"\${PIPESTATUS[0]}\" >tmp_ret_val) <(tail ${ARGS[$i]} test4.4.txt 2>/dev/null) >>tmp_log"
    RESULT1=$?
    RESULT2=$(cat <tmp_ret_val)
    cat <tmp_log >>tail_log
    print_result $RESULT1 $RESULT2

    ### test .5 ###
    echo "===test $i.5: with arguments: \"${ARGS[$i]}\", with a file from stdin: test5.txt" >tmp_log
    eval "diff <(valgrind --leak-check=full --error-exitcode=2 ../tail ${ARGS[$i]} <test5.txt 2> >(grep -E \"(in\ use\ at\ exit|total\ heap\ usage|ERROR\ SUMMARY|tail:)\" >>tmp_log); echo \"\${PIPESTATUS[0]}\" >tmp_ret_val) <(tail ${ARGS[$i]} <test5.txt 2>/dev/null) >>tmp_log"
    RESULT1=$?
    RESULT2=$(cat <tmp_ret_val)
    cat <tmp_log >>tail_log
    print_result $RESULT1 $RESULT2

    echo "===test $i.5: with arguments: \"${ARGS[$i]}\", with a file: test5.txt" >tmp_log
    eval "diff <(valgrind --leak-check=full --error-exitcode=2 ../tail ${ARGS[$i]} test5.txt 2> >(grep -E \"(in\ use\ at\ exit|total\ heap\ usage|ERROR\ SUMMARY|tail:)\" >>tmp_log); echo \"\${PIPESTATUS[0]}\" >tmp_ret_val) <(tail ${ARGS[$i]} test5.txt 2>/dev/null) >>tmp_log"
    RESULT1=$?
    RESULT2=$(cat <tmp_ret_val)
    cat <tmp_log >>tail_log
    print_result $RESULT1 $RESULT2

    ### test .7 ###
    echo "===test $i.7: with arguments: \"${ARGS[$i]}\", with a file from stdin: test7.txt" >tmp_log
    eval "diff <(valgrind --leak-check=full --error-exitcode=2 ../tail ${ARGS[$i]} <test7.txt 2> >(grep -E \"(in\ use\ at\ exit|total\ heap\ usage|ERROR\ SUMMARY|tail:)\" >>tmp_log); echo \"\${PIPESTATUS[0]}\" >tmp_ret_val) <(tail ${ARGS[$i]} <test7.txt 2>/dev/null) >>tmp_log"
    RESULT1=$?
    RESULT2=$(cat <tmp_ret_val)
    cat <tmp_log >>tail_log
    print_result $RESULT1 $RESULT2

    echo "===test $i.7: with arguments: \"${ARGS[$i]}\", with a file: test7.txt" >tmp_log
    eval "diff <(valgrind --leak-check=full --error-exitcode=2 ../tail ${ARGS[$i]} test7.txt 2> >(grep -E \"(in\ use\ at\ exit|total\ heap\ usage|ERROR\ SUMMARY|tail:)\" >>tmp_log); echo \"\${PIPESTATUS[0]}\" >tmp_ret_val) <(tail ${ARGS[$i]} test7.txt 2>/dev/null) >>tmp_log"
    RESULT1=$?
    RESULT2=$(cat <tmp_ret_val)
    cat <tmp_log >>tail_log
    print_result $RESULT1 $RESULT2

    ### test .8 ###
    echo "===test $i.8: with arguments: \"${ARGS[$i]}\", with a file from stdin: test8.txt" >tmp_log
    eval "diff <(valgrind --leak-check=full --error-exitcode=2 ../tail ${ARGS[$i]} <test8.txt 2> >(grep -E \"(in\ use\ at\ exit|total\ heap\ usage|ERROR\ SUMMARY|tail:)\" >>tmp_log); echo \"\${PIPESTATUS[0]}\" >tmp_ret_val) <(tail ${ARGS[$i]} <test8.txt 2>/dev/null) >>tmp_log"
    RESULT1=$?
    RESULT2=$(cat <tmp_ret_val)
    cat <tmp_log >>tail_log
    print_result $RESULT1 $RESULT2

    echo "===test $i.8: with arguments: \"${ARGS[$i]}\", with a file: test8.txt" >tmp_log
    eval "diff <(valgrind --leak-check=full --error-exitcode=2 ../tail ${ARGS[$i]} test8.txt 2> >(grep -E \"(in\ use\ at\ exit|total\ heap\ usage|ERROR\ SUMMARY|tail:)\" >>tmp_log); echo \"\${PIPESTATUS[0]}\" >tmp_ret_val) <(tail ${ARGS[$i]} test8.txt 2>/dev/null) >>tmp_log"
    RESULT1=$?
    RESULT2=$(cat <tmp_ret_val)
    cat <tmp_log >>tail_log
    print_result $RESULT1 $RESULT2

    ### test .9 ###
    echo "===test $i.9: with arguments: \"${ARGS[$i]}\", with a file from stdin: test9.txt" >tmp_log
    eval "diff <(valgrind --leak-check=full --error-exitcode=2 ../tail ${ARGS[$i]} <test9.txt 2> >(grep -E \"(in\ use\ at\ exit|total\ heap\ usage|ERROR\ SUMMARY|tail:)\" >>tmp_log); echo \"\${PIPESTATUS[0]}\" >tmp_ret_val) <(tail ${ARGS[$i]} <test9.txt 2>/dev/null) >>tmp_log"
    RESULT1=$?
    RESULT2=$(cat <tmp_ret_val)
    cat <tmp_log >>tail_log
    print_result $RESULT1 $RESULT2

    echo "===test $i.9: with arguments: \"${ARGS[$i]}\", with a file: test9.txt" >tmp_log
    eval "diff <(valgrind --leak-check=full --error-exitcode=2 ../tail ${ARGS[$i]} test9.txt 2> >(grep -E \"(in\ use\ at\ exit|total\ heap\ usage|ERROR\ SUMMARY|tail:)\" >>tmp_log); echo \"\${PIPESTATUS[0]}\" >tmp_ret_val) <(tail ${ARGS[$i]} test9.txt 2>/dev/null) >>tmp_log"
    RESULT1=$?
    RESULT2=$(cat <tmp_ret_val)
    cat <tmp_log >>tail_log
    print_result $RESULT1 $RESULT2

done

#second part of the test, probably not necessary functionality
for i in {17..180}; do

    echo "===test $i: with arguments: \"${ARGS[$i]}\"" >tmp_log
    eval "diff <(valgrind --leak-check=full --error-exitcode=2 ../tail ${ARGS[$i]} 2> >(grep -E \"(in\ use\ at\ exit|total\ heap\ usage|ERROR\ SUMMARY|tail:)\" >>tmp_log); echo \"\${PIPESTATUS[0]}\" >tmp_ret_val) <(tail ${ARGS[$i]} 2>/dev/null) >>tmp_log"
    RESULT1=$?
    RESULT2=$(cat <tmp_ret_val)
    cat <tmp_log >>tail_log
    print_result $RESULT1 $RESULT2

done

rm tmp_ret_val tmp_log