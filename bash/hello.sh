#! /bin/bash
#cat /etc/shells

#which bash

#echo $BASH
#echo $BASH_VERSION
#echo $HOME
#echo $PWD

#name=sk
#echo name is $name

#echo "Enter name :"
#read name
#echo $name

#echo "Enter name,age,sex,points :"
#read name age sex points
#echo $name,$age,$sex,$points

#read -p 'Enter Name : ' name
#echo $name

#read -sp 'Enter password : ' password
#echo
#echo $password

#echo 'Enter names :' 
#read -a names
#echo "Names are : ${names[1]}"

#echo -e "Enter name: \c"
#read
#echo $REPLY

#echo "$1--> ARG1---$2-->ARG2"

#args=("$@")
#echo ${args[0]} ${args[1]}
#echo $@ #prints all args
#echo $# #prints num of args

#echo -e "Enter File name  :\c"
#read file_name
#if [ -e $file_name ]
#then
#echo "$file_name file found"
#else
#echo "$file_name file not found"
#fi

#echo -e "Enter File Name :\c"
#read file_name
#if [ -e $file_name ]
#then
#if [ -w $file_name ]
#then
#echo "Write Something.. press ctrl+d to quit"
#cat >> $file_name
#else
#echo "You don't have write permissions."
#fi
#else
#echo "File Doesn't exist"
#fi


#age=30
#if [[ "$age" -gt 18 && "$age" -lt 35 ]]
#then
#echo "True"
#else
#echo "False"
#fi

#num1=20
#num2=5
#echo $(($num1+$num2))
#echo $(($num1-$num2))
#echo $(($num1*$num2))
#echo $(($num1/$num2))
#echo $(($num1%$num2))
#echo $(($num1^$num2)) #xor

#echo $(expr $num1 + $num2 )
#echo $(expr $num1 - $num2 )
#echo $(expr $num1 \* $num2 )
#echo $(expr $num1 / $num2 )
#echo $(expr $num1 % $num2 )

#num3=20.5
#num4=5.2
#echo "$num3+$num4" | bc
#echo "$num3-$num4" | bc
#echo "$num3*$num4" | bc
#echo "scale=5;$num3/$num4" | bc
#echo "$num3%$num4" | bc

#echo "scale=7;sqrt($num3)" | bc -l #import mathlib
#echo "scale=7;$num3^5" | bc -l

#vehicle=$1 #arg1 is passed to vehicle
#case $vehicle in
#    "car" )
#       echo "Car" ;;
#    "van" )
#       echo "Van" ;;
#    * )
#       echo "Default" ;;
#esac

#array=( 'sai' 'krishna' 'gudipati')
#array[6]='sk'
#array[0]='vamsi'
#unset array[2]
#echo "${array[@]}"
#echo "${array[2]}"
#echo "${!array[@]}"
#echo "${#array[@]}"

#string=sad
#echo "${string[0]}"
#echo "${string[1]}"
#echo "${!string[@]}"
#echo "${#string[@]}"

#while read data
#do
#echo $data
#done < myfile.csv

#select var in {0..10..2}
#do
#echo "$var selected"
#done

#is_file_exists(){
#    local name=$1
#    if [ -e $name ]
#    then
#        while read data
#        do
#            echo $data
#        done < $name
#    else
#    echo file doesnot exist
#    fi
#}




#rows=$(wc -l < cricket.csv)
#rows=$(($rows-2))
#echo $rows
