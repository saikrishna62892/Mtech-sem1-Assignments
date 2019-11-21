#!/usr/bin/perl
#All rights reserved; <m190241cs>
open(READ,"3B5.pl");open(WRITE,">temp.pl");$counter=0;
while(<READ>){
    $counter++;
    if($counter==2){
        chomp $_;
        if("$_" ne "#All rights reserved; <m190241cs>"){
            print "$_";
            print "$i true\n";
            print WRITE "#All rights reserved; <m190241cs>\n";
            }
        }
        print WRITE $_;
    }
    close(READ);
    close(WRITE);
    rename("temp.pl","3B5.pl");
