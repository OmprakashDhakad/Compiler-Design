/*
   NAME - OMPRAKASH
   ID   - 2015KUCP1028
*/
/*write a lex code to count the char in  a string*/
%{
  int count=0 ; 
%}

%%
[a-zA-Z] count++;
\n {return count;}
%%

main()
{
  printf("Enter a string : ");
  yylex();
  printf("count = %d\n",count );
  
}
int yywrap (void )
{
    return 0;
}
