#!/usr/bin/perl
%hash=();
%freq=();
open(NEW,"3B4.txt");
while(<NEW>){
    foreach $i ($_){
        @line = split(' ', $_);
    }
    foreach $j (@line){
        if(exists($hash{$j})){
            $hash{$j}=$hash{$j}+1;
        }
        else{
            $hash{$j}=1;
        }
    }
}
@conjunctions=('and','or','but','nor','so','yet','after','although','as','because','before','even','if','once','since','that','though','till','unless','until','what','when','whenever','wherever','whether','while');
@prepositions=('of','with','at','from','into','during','including','against','among','throughout','despite','towards','upon','concerning','to','in','for','on','by','about','like','through','over','between','after','since','without','under','within','along','following','across','behind','beyond','plus','except','but','up','out','around','down','off','above','near');
@interjections=('ah','alas','eh','er','oh','o','ouch','wow','hurrah');
$flag=0;
$counter=0;
foreach $k (sort { $hash{$b} <=> $hash{$a} } keys %hash) {
    foreach $c (@conjunctions){
        if("$k" eq "$c"){
            $flag=1;
            last;
        }
    }
    foreach $p (@prepositions){
        if("$k" eq "$p"){
            $flag=1;
            last;
        }
    }
    foreach $in (@interjections){
        if("$k" eq "$in"){
            $flag=1;
            last;
        }
    }
    if($flag!=1){
        $counter++;
        if($counter<=10){
            $freq{$k}=$hash{$k};
        }
    }
    print "$k->$hash{$k}\n";
}
print "\tFREQUENT WORDS:\n";
@values = values %freq;
@keys = keys %freq;
$keysize=@keys;
foreach $k (@keys){
    print "$k->$freq{$k}\n";
}
close(NEW);