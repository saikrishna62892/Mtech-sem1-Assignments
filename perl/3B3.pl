#!/usr/bin/perl
open(NEW,"3B3.txt");
open(WRITE,">3B3output.txt");
while(<NEW>){
    while($_ =~ m/(\d+)\/(\d+)\/(\d+)/g){
        print WRITE "$2\/$1\/$3\n";
    }
}
close(NEW);
close(WRITE)