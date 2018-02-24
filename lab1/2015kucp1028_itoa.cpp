#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

char* itoaf(int n)
{
  int i=0,k=0;
  char ans[1000];
  char result[1000];
  while(n>0)
  {
     int temp = n%10;
     n = n/10;
     ans[i] = (temp + 48);
     i++;
   }
   
   for(int j=i-1;j>=0;j--)
   {
    result[k] = ans[j];
    k++;
   }
   result[k] = '\0';
   printf("%s\n",result);
   printf("string length  = %d\n",(int)strlen(result));
}

int main()
{
  int n;
  printf("Enter the value = ");
  cin >> n;
  cout << "String  = ";
  itoaf(n); 
  
}


