

%{
#include <stdio.h>
#include "tokens.h"
int line_number = 1;
%}

newline \n

%%

"," {return ',';}
";" {return ';';}

{newline} {line_number++;}


%%

int get_line_number(){
    return line_number;
}

