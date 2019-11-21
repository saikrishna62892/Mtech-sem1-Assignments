arg=$1
case $arg in
"-p" )
    ps aux --sort=-%mem | awk 'NR<=2{print $1"\t"$2"\t"$4}';;
"-m")
    df -h;;
"-d" )
    df | awk '$5+0 >= 90 {print}';;
"-f" )
    #find . -mmin -60|head -5;;  pwd
    find /* -mmin -60|head -5;;
* )
    echo "Please Enter Valid Argument";;
esac
