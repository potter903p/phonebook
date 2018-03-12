reset
set ylabel 'time(sec)'
set style fill solid
set title 'performance comparison'
set term png enhanced font 'Verdana,10'
set output 'runtime.png'

plot [:][:0.150]'output.txt' using 2:xtic(1) with histogram title 'original', \
'' using 3:xtic(1) with histogram title 'optimized'  , \
'' using 4:xtic(1) with histogram title 'hash'  , \
'' using ($0-0.06):(0.110):2 with labels title ' ' textcolor lt 1, \
'' using ($0-0.06):(0.105):3 with labels title ' ' textcolor lt 2, \
'' using ($0-0.06):(0.100):4 with labels title ' ' textcolor lt 3
