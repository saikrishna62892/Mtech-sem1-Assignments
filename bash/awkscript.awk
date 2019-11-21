BEGIN{
    file_name = $1
    FS=","
    date=strftime("%Y%m%d")
}
{
    count=0
    blank=0
    for(i=1;i<=NF;i++){
        if($i != ""){
            count++
        }
        else{
            blank++
        }
    }
    if(count!=NF){
        reason1[p++]=NR-1
    }
    if(blank >= NF*0.1){
        reason2[q++]=NR-1
    }    
}
END{
    for(a=0;a<p;a++)
    if(reason1[a]!=NR-1){
		flag=1
		print reason1[a] "th row is not same as num of cols in header"
	}
    print ""
    for(b=0;b<q;b++)
    if(reason2[b]!=NR-1){
		flag=1
		print reason2[b] "Contains more than 10% blanks"
	}
    print ""
    if(NR-2 != $2){
		flag=1
		print "Num of rows is not same as mentioned in trailer record"
	}
    
    if(date != $1){
		flag=1
		print "Date doesnot match in trailer record"
	}
	if(flag==0)
	print "Valid CSV"
   
}
