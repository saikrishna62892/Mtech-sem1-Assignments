while read line; do
case "$line" in \#*) continue ;; esac
    for word in $line; do
        file1[i++]=$word
    done
done < $1
while read line; do
case "$line" in \#*) continue ;; esac
    for word in $line; do
        file2[j++]=$word
    done
done < $2
word_count=$i
if [ $j -gt $word_count ]
then
    word_count=$j
fi
eighty_percentage=$(echo "$word_count * 0.8"|bc)
for((a=0;a<i;a++))
do
    if [ $a -eq $j ]
    then
        break
    fi
    for((b=0;b<j;b++))
    do
        match[b]=0
        if [ "${file1[a]}" == "${file2[b]}" -a "${match[b]}" -ne 1 ]
        then
            ((wordmatch++))
            match[b]=1
            break
        fi
    done
done
flag=$(echo "$wordmatch > $eighty_percentage" |bc -l)
if [ "$flag" == 1 ]
then
    match_percentage=$(bc <<<"scale=2;($wordmatch/$word_count)*100")
    echo "Report: PLAGARIZED"
    echo "Matching percentage $match_percentage %"
else
    match_percentage=$(bc <<<"scale=2;($wordmatch/$word_count)*100")
    echo "Report: NOT-PLAGARIZED"
    echo "Matching percentage: $match_percentage %"
fi