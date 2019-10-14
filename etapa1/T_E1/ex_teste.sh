# /bin/bash


clear
var=1

while [ $var -le 86 ]
do
	if [ $var -le 9 ]
	then 
		echo "Teste $var"
		cat "entrada_00$var"|../etapa1
		echo "\n"
		
	else
		echo "Teste $var"
		cat "entrada_0$var"|../etapa1
		echo "\n"
	fi
	var=$((var+1))
done
