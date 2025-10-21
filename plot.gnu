set terminal png
set output "result.png"

set xlabel "Temperature"
set ylabel "Path cost"
set xrange [*:*] reverse

plot "data" using 1:2 with linespoints title "Annealing results"

set output