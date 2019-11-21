while read line; do
    for word in $line; do
        credits[i++]=$word
    done
done < dbconfig.config
mysql -h ${credits[0]} -u ${credits[1]} -p${credits[2]} -e "use ${credits[3]};
select count(*) from ${credits[4]};"