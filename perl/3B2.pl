#!/usr/bin/perl
open(NEW,"3B2.txt");
while(<NEW>){
    while( $_ =~ m/[A-Z,a-z,\s](\d+)[A-Z,a-z,\s]/g ){
        push(@nums,$1);
    }
    while( $_ =~ m/(\d+\/\d+\/\d+)/g ){
        push(@date,$1);
    }
}
close(NEW);
open(NUM,">3B2numbers.txt");
open(DATE,">3B2date.txt");
foreach $i (@nums){
    print NUM "$i\n";
}
foreach $i (@date){
    print DATE "$i\n";
}
close(NUM);
close(DATE);

