# /bin/bash


clear
var=0

while [ $var -le 50 ]
do
	if [ $var -le 9 ]
	then 
		echo "Teste $var"
		valgrind ../etapa3 < "i_e3_00$var.ptg"
		echo 
		
	else
		echo "Teste $var"
		valgrind ../etapa3 < "i_e3_0$var.ptg"
		echo 
	fi
	var=$((var+1))
done
