input=$1
output=$2
awk -f test2awk.awk cricket.csv| cat > output2.txt