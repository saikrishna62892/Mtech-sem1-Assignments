#!/usr/bin/perl
sub sum{
    my @list=@_;
    $sum=0;
    foreach $i (@list){
        $sum=$sum+$i;
    }
    return $sum;
}
print "Enter List of Numbers(Press ctrl+d to exit):\n";
@list=<STDIN>;
chomp @list;
$size = @list;
$total=sum(@list);
print "SUM: $total\n";
$avg=$total/$size;
print "AVG: $avg\n";

