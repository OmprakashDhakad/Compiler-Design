#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

int main()
{

  int n,m;
  char token[1000][1000];
  int count = 0;
  FILE* fp;
  fp = fopen("token.txt","r");
  
  if(fp == NULL)
   {
      printf("Error!");               
   }
   
   int i = 0;
   
   
	while((fscanf(fp,"%s",token[i]))!=EOF)
	{
	    
	    int k = 1;
	    int len = strlen(token[i]);
	    
	    while(len--)
	    {
		    if(token[i][k] >= 'a' && token[i][k] <= 'z')
		    {
		       k++;
			 continue;
		    } 
		    if(token[i][k] == '\"')
		    {
		      count++;
		      k++;
			while(token[i][k] != '\"')
			{
			  break;
			}
		    }
		    else
		    {
		        
		     	  count++;
		     	  k++;
		    }
	    }
	     
	     i++;
	}
      printf("No of Tokens : %d\n",count);
   fclose(fp); 
}
