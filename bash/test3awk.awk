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
    team1[0]="Sunrisers"
    team1[1]="Mumbai"
    team1[2]="Gujarat"
    team1[3]="Rising"
    team1[4]="Royal"
    team1[5]="Kolkata"
    team1[6]="Delhi"
    team1[7]="Kings"
    team1[8]="Deccan"
    team1[9]="Rajasthan"
    team1[10]="Chennai"
    j=0
}
{
    for(i=0;i<11;i++){
        if($5 == team[i])
        short[i]=team1[i]
    }
    if(NR!=1){
        player[j]=$14
        count[j++]++
    }
}
END{
    for(i=0;i<11;i++){
        print i+1","short[i]","player[i]","count[i]
    }
    
}
