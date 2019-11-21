dir=`ls ./*.txt`
for file in $dir
do
   files[i++]=$file
done
for((a=0;a<i-1;a++))
do
    for((b=a+1;b<i;b++))
    do
        echo "FILES COMPARED ARE :"
        echo "FILE1: ${files[a]}   FILE2: ${files[b]}"
        bash 3A4.sh ${files[a]} ${files[b]}
        echo
    done
done