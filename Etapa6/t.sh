# /bin/bash
for file in {00..07}; do 
echo $file;
 ./etapa6 < "Testes/e$file" > "compilados/comp$file.iloc";
done
