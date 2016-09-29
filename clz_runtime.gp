reset

#set logscale x 2
set grid
set key left
set xlabel 'N'
set ylabel 'time(each)'
set style fill solid
set title 'CLZ'
set format y "%1.2e" 
set yrange[0.00000005:0.0000005]
#set xrange[0:10000]
set term png enhanced font 'Verdana,8'
set output 'clz.png'

plot 'result.csv'\
    using 1:6 title 'clz harley' with yerrorlines,\
''using 1:5 title 'clz byteshift' with yerrorlines,\
''using 1:4 title 'clz binarysearch' with yerrorlines,\
''using 1:3 title 'clz iteration' with yerrorlines,\
''using 1:2 title 'clz recursive' with yerrorlines
