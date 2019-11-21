input=$1
output=$2
awk -f test1awk.awk cricket.csv| cat > output.txt| sort -r output.txt
awk -f test1awk.awk cricket.csv| cat > output.20191105|sort -r output.20191105