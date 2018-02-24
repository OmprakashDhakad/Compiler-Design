#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main()
{
  
  
  int n,m;
  FILE* fp;
  fp = fopen("keyword.txt","r");
  
  if(fp == NULL)
   {
      printf("Error!");               
   }
   
   fscanf(fp,"%d", &n);
   
   char keyw[n][1000];
   for(int i=0;i<n;i++)
   {
     fscanf(fp,"%s",keyw[i]);
   }
   fclose(fp);
   
   FILE* fp1;
   fp1 = fopen("input.txt","r");
   if(fp1 == NULL)
   {
      printf("Error!");               
   }
   
   fscanf(fp1,"%d", &m);
   
   
   for(int i=0;i<m;i++)
   {
     char temp[100];
     int l;
     int k;
     int flag = 0;
     fscanf(fp1,"%s",temp);
     
     for(int j=0;j<n;j++)
     {
       
       
       if(strlen(keyw[j])==strlen(temp) && keyw[j][0]==temp[0])
       {
          int l = strlen(keyw[j]);
          int k = 1;
          while(k<l)
          {
            if(keyw[j][k]==temp[k])
            {
               k++;
               
            }
            else
            {
              break;
            }
          }
          if(k==l)
	    {
		 flag = 1;
	    }
             
       }
       
     }
    if(flag==1)
    {
       printf("%d.%s : Valid\n",i+1,temp);
    }
    else
    {
       printf("%d.%s : Invalid\n",i+1,temp);
    }
     
   }
   fclose(fp1);
}
