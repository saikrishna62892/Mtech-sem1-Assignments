#!/usr/bin/perl

print "hello_world\n";

@alphabets = (a..z);
@caps=(A..M);
@nums=(5..27);

print "@alphabets\n";
shift(@caps);

pop(@caps);
print "@caps\n";

unshift(@nums,0);

push(@nums,28);

print "@nums\n";
$size = @alphabets;
print "$size\n";

@num1=@nums[0,2,4,5,8,9];
@num2=@nums[2..7];
print "@num1\n";
print "@num2\n";

$size2=@num2[0..2];
print "$size\n";

splice(@num1,0,3,@num2[0..2]);
print "@num1\n";

$string=join('',@num1);
print "$string\n";

$string1="This is sk ok !! #/ l";
@array=split(' ',$string1);

print "@array\n@array[2]\n";
@array1=(a,c,f,g,t,'s');
@asc = sort(@array1); 

@desc = sort { $b cmp $a } @array1;
print "@asc\n@desc\n";

@merge=(@asc,@desc);
print "@merge\n";

%hash1=(1=>'sai',2=>'krishna',3=>'sk');
@arrayhash=@hash1{1..2};
print @arrayhash;
print "\n@hash1{1..2}\n";

@key = keys %hash1;
@value = values %hash1;
print "@key\n@value\n";

if(exists($hash1{4}))
{
    print "exists\n";
}
else
{
    print "dont exist\n";
}

$hashsize=@key;
print "size of the hash : $hashsize\n";

$hash1{4}='gudipati';
print "@hash1{1..4}\n";

delete $hash1{3};
print "@hash1{1..4}\n";

$num3=int(rand(100));

print "$num3 -> ";
++$num3;
print "$num3 -> ";
$str=($num3%2 == 0)?"even\n":"odd\n";
print $str;

@alps=(A..Z);
foreach $i (@alps)
{
    print "$i ";
}
print "\n";

@time=localtime();
print "@time\n";
$sec=@time[0];

open(NEW,"/home/saikrishna62892/Desktop/perl/hello.txt");
$counter=0;
while(<NEW>)
{
    $counter++;
    foreach $i ("$_")
    {
        $temp=$i;
        if($i==' ')
        {
            push(@line,$temp);
            $temp='';
        }

    }
    print "@line\n";
    if($counter==1)
    {
        last;
    }
}

$text="jdjvbjxvjhh dd dvijvcx d caf sdjvvjnf jiasjiasdjnjk3en rjiw4ilj sceoij";
open(NEW1,">output.txt");
foreach $i (@line)
{
    print NEW1 $i;
}
print NEW1 $text;
close(NEW1);

my $files = `ls`;
my $files1 = `pwd`;
print $files."\n".$files1;

#All rights reserved; <m190241cs>
