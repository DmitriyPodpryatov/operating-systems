OUTPUT="$(cat /proc/cpuinfo)" 

tee ex2.txt <<< "$OUTPUT"
