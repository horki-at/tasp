set terminal pngcairo size 780,780
set output outfile

set datafile separator " "
set title "Graph and Solution"
unset border
unset xtics
unset ytics
unset xlabel
unset ylabel
set key off
set autoscale

system("awk 'NF==3{print >\"points.tmp\"} NF==1{print >\"path.tmp\"}' data")
system("awk 'NR==FNR{a[$3]=$0;next}{if($1 in a)print a[$1]}' points.tmp path.tmp > path_points.tmp")

plot \
    "points.tmp" using 1:2 with points pt 7 ps 0.5 lc rgb "black", \
    "points.tmp" using 1:2:3 with labels offset 0.5,0.5 font ',5', \
    "path_points.tmp" using 1:2 with lines lc rgb "red" lw 2

system("rm -f points.tmp path.tmp path_points.tmp")
