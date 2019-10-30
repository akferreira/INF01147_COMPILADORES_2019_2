# Step #3: valgrind test
rm -f valgrind.txt
valgrind ./etapa3 < $test 2>&1 | grep -A5 LEAK\ SUMMARY > valgrind.txt
VGRESULT=$(cat valgrind.txt | cut -d":" -f2| awk '{print $1}' | tr '\n' ' ' | sed "s/,//g")
if [[ $VGRESULT = "" ]]; then
    VGRESULT="no leaks are possible"
    VGCUTIN=0
else
    VGCUTIN=$(echo $VGRESULT | tr ' ' '+' | bc)
fi
