/*
   NAME - OMPRAKASH
   ID   - 2015KUCP1028
*/
/*write a lex code to identify the reserve keyword and identifiers*/
%%
[\t]+
auto |
double |
int |
struct |
break 	|
else |
long |
switch |
case |
enum |
register |
typedef |
char |
extern |
return |
union |
continue |
for |
signed 	|
void  |
do |
if 	|
static  |
while |
default |
goto 	|
sizeof |
volatile |
const |
float |
short |
unsigned  { printf ("%s : is valid keyword",yytext);}
[_a-zA-Z][_a-zA-Z0-9]* { printf ("%s : is identifier",yytext);}
.* { printf ("%s : is not identifier",yytext);}
%%
main()
{yylex();}



