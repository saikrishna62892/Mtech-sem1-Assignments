input=$1
output=$2
awk -f test1awk.awk cricket.csv| cat > outputtest.txt| sort -nr outputtest.txt
awk -f test1awk.awk cricket.csv| cat > output.20191105|sort -nr output.20191105