#include<stdio.h>
#include<string.h>

char productions[100][100];

char removeleftrec(char* str)
{
   int l=3;
   int len = strlen(str);
   FILE* fp1;
   char temp[100]="S->" ;
   
   for(int i=1;i<len;i++)
   { 
      if(str[0]==str[i])
      {
        while(str[i]!='|')
        {
           i++;
        }
      }
      if(str[0]!=str[i] && str[i]!='>' && str[i]!='-')
      {
        if(str[i]!='|')
        {
		  temp[l] = str[i];
		  l++;
		  //printf("%s\n ",temp);
        }
        else
        {
          printf("\n");
          i++;
        }
      }
      
   }
   printf("%s\n ",temp);
   printf("\n");
}
int main()
{
   int n;
   int i,j,k;
   char prod[100][100];
   
   FILE* fp;
   fp = fopen("left.txt","r");
   
   fscanf(fp,"%d",&n);
   for(i=0;i<n;i++)
   {
      fscanf(fp,"%s",prod[i]);
      printf("%s\n",prod[i]);
   }
   
   for(i=0;i<n;i++)
   {
      int len = strlen(prod[i]);
      for(j=0;j<len;j++)
      {
        if(prod[i][0]==prod[i][j])
        {
          printf("left rec occure %d \n",j);
          removeleftrec(prod[i]);
        }
        
        
      }
   }
}
