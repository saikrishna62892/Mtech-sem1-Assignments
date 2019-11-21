BEGIN{
    file_name = $1
    FS=","
    team[0]="Sunrisers Hyderabad"
    team[1]="Mumbai Indians"
    team[2]="Gujarat Lions"
    team[3]="Rising Pune Supergiant"
    team[4]="Royal Challengers Bangalore"
    team[5]="Kolkata Knight Riders"
    team[6]="Delhi Daredevils"
    team[7]="Kings XI Punjab"
    team[8]="Deccan Chargers"
    team[9]="Rajasthan Royals"
    team[10]="Chennai Super Kings"
    for(i=0;i<11;i++)
    count[i]=0
}
{
    for(i=0;i<11;i++){
        if($2 == team[i]){
            count[i]=count[i]+1
        }
    }
    
}
END{
    for(i=0;i<11;i++)
    print count[i]"|"team[i]
}
