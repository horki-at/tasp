set terminal pngcairo size 780,780
set output outfile

set datafile separator " "
set title "Graph"
unset border
unset xtics
unset ytics
unset xlabel
unset ylabel
set key off
set autoscale

plot "data" using 1:2 with points pointtype 7 pointsize 0.5 linecolor rgb "black", \
     "data" using 1:2:3 with labels offset 0.5,0.5 font ",5"