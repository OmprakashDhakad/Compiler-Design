%%
[\t]+
is |
are |
am  |
was | 
were { printf ("%s : is valid HV",yytext);}
[a-z A-Z]+ { printf ("%s : Something is wrong",yytext);}
%%
main()
{yylex();}



