/*
   NAME - OMPRAKASH
   ID   - 2015KUCP1028
*/
/*write a lex code to count the no of vowels and consonant*/
%{
  int vowel=0 ; 
  int cons=0 ; 
  int count = 0;
%}

%%
[aeiouAEIOU] vowel++;
[a-zA-Z] cons++;
.
\n {return 1;}
%%

main()
{
  printf("Enter a string : ");
  yylex();
  printf("vowel = %d\n",vowel );
  printf("consonant = %d\n",cons );
  
}
int yywrap (void )
{
    return 0;
}
