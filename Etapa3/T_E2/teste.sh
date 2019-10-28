# /bin/bash


clear
var=1

while [ $var -le 150 ]
do
	if [ $var -le 9 ]
	then 
		echo "Teste $var"
		cat "asl0$var"|../etapa3
		echo 
		
	else
		echo "Teste $var"
		cat "asl$var"|../etapa3
		echo 
	fi
	var=$((var+1))
done
