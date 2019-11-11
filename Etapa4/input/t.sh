# /bin/bash


clear
var=1

while [ $var -le 52 ]
do
	if [ $var -le 9 ]
	then 
		echo "Teste $var"
		cat "poi0$var"|../etapa4
		echo 
		
	else
		echo "Teste $var"
		cat "poi$var"|../etapa4
		echo 
	fi
	var=$((var+1))
done
