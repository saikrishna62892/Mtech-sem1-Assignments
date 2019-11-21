input=$1
output=$2
awk -f test3awk.awk cricketdata.csv| cat > output3.txt