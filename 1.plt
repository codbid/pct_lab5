set termoption enhanced
set terminal svg size 800,600 font "Arial, 16"
set encoding utf8
set output "1.svg"

set style line 1 lc rgb "0x6495ED" lt 1 lw 4 pt 7 ps 1
set style line 2 lc rgb "0x00FF00" lt 1 lw 4 pt 7 ps 1
set style line 3 lc rgb "0x0000FF" lt 1 lw 4 pt 7 ps 1
set style line 4 lc rgb "0xD2691E" lt 1 lw 4 pt 7 ps 1


set border lw 2
set grid
set key top left
set xlabel "Число потоков"
set ylabel "Коэффициент ускорения" rotate by 90
set xtics 2
set xrange [2:8]
set format y "%1.4f"
plot "1.dat" using 1:2 title "T=100" with linespoints ls 1, \
"1.dat" using 1:3 title "T=1000" with linespoints ls 2, \
"1.dat" using 1:4 title "T=10000" with linespoints ls 3, \
"1.dat" using 1:5 title "Linear" with linespoints ls 4, \