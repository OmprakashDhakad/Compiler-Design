/*
  NAME  -  OMPRAKASH
  ID    -  2015KUCP1028
  
  put input string in starting to process the operator grammar
*/

#include<bits/stdc++.h>
using namespace std;

pair<char,string> x;
map<char, vector<string> > m;
map<char,vector<string> >::iterator it;
map<pair<char,char>, char > table;
vector<string> v;
stack<char> stck;
stack<char> ntstack;
char startsymbol;

void display(map<char, vector<string> > ma)
{
	for(it=ma.begin();it!=ma.end();it++)
	{
		char c = it->first;
		cout<<c<<"->";
		v = it->second;
		for(uint i=0;i<v.size();i++)
		{
			if(i!=0)
			{
				cout<<"|";
			}
			cout<<v[i];
		}
		cout<<endl;
	}
}

void showstack(stack <char> g,int a)
{
    cout << "\npresent stack"<<a<< " top->bottom :" << endl;

    while (!g.empty())
    {
        cout << '\t' << g.top();
        g.pop();
    }
    cout << '\n';
}

char findntch(char ch)
{
   for(it=m.begin();it!=m.end();it++)
	{
		char c = it->first;
		string str = "" ;
		str = str + ch ;
		v = it->second;
		for(uint i=0;i<v.size();i++)
		{
			if(ch==v[i][0] && v[i].length()==1)
			{
				return c;
			}
			
		}
		
	}
    return 'z';
}

char findnt(string str)
{
   for(it=m.begin();it!=m.end();it++)
	{
		char c = it->first;
		v = it->second;
		for(uint i=0;i<v.size();i++)
		{
			if(str==v[i])
			{
				return c;
			}
			
		}
		
	}
    return 'z';
}

int precedence(char ch)
{
   switch(ch){
				case '$' : return 0;
				case '^' : return 4;
		   		case '/' : return 3;
		   		case '%' : return 3;
		   		case '*' : return 3;
		   		case '-' : return 2;
		   		case '+' : return 2;
		   		default  : return 10;
   			 }
}

int isoperator(char ch)
{
  if(ch=='/' || ch=='*' || ch=='-' || ch=='+' || ch=='%' || ch=='^')
  return 1;
  else
  return 0;
}

int isnonterminal(char ch)
{
  if(ch >= 65 && ch <= 90)
  return 1;
  else
  return 0;
}
int leftassociative(char ch)
{
  if(ch=='/' || ch=='*' || ch=='-' || ch=='+' || ch=='%')
  return 1;
  else
  return 0;
}

int grammarcheck(map<char, vector<string> > ma)
{
  for(it=ma.begin();it!=ma.end();it++)
	{
	    vector<string> v;
		v = it->second;
		int flag = 0;
		for(uint i=0;i<v.size();i++)
		{
			if(v[i].length()%2==1)
			{ 
			   if(v[i].length()==1)
			   {
			     if(isnonterminal(v[i][0])==0 && v[i][0]!='#' )
			     {
			        continue;
			     }
			     else
			     {
			       cout << "Grammar is not operator grammar "<<endl;
			       return 0;
			     }
			   }
			   else
			   {
				   for(uint j=0;j<v[i].length()-2;j=j+2)
				   {
					 
					 if(isnonterminal(v[i][j])==1 && isoperator(v[i][j+1])==1 && isnonterminal(v[i][j+2])==1)
					 {
					    flag = 1;
					    
					 }
					 else 
					 {
					   cout << "Grammar is not operator grammar " << endl;
					   return 0;
					 }
				   }
			   }
			}
			
		}
		if(flag == 1)
		{
		    cout << "Grammar is operator grammar " << endl; 
		    break;
		}
		cout<<endl;
	}
	return 1;
}

void processstring(string str)
{
   uint i;
   str = str + '$';
   for(i=0;i<str.length();)
   {
      
      cout << "top of the stack1 : " << stck.top();
      cout << "  input " << str[i] ;
      int left;

      if(precedence(str[i])==precedence(stck.top()))
      {
         left = leftassociative(str[i]);
      }
      
      if(stck.top()=='$' && str[i] == '$')
      {
         cout << " : poped " << stck.top() << endl; 
         stck.pop();
         showstack(stck,1);
         break;
      }
      
      if(precedence(str[i]) > precedence(stck.top()) )
      {
         stck.push(str[i]);
         cout << " : pushed " << str[i] << endl; 
         i++;
         showstack(stck,1);
      }
      else if(precedence(str[i]) > precedence(stck.top()) && left==1 )
      {
         stck.push(str[i]);
         i++;
         cout << " : pushed " << str[i] << endl; 
         showstack(stck,1);
      }
      else
      {
         cout << " : poped " << stck.top() << endl;
         
         if(isoperator(stck.top()))
         {
           string  str1 = "" ;
            
           char temp1 =  ntstack.top();
           ntstack.pop();
           str1 = str1 + ntstack.top() + stck.top() + temp1;
           ntstack.pop();
           char tch = findnt(str1);
           showstack(ntstack,2); 
           if(tch!='z')
            {
		          ntstack.push(tch);
		          cout << "\nTwo non terminal poped and one pushed " << ntstack.top() << endl;
		          showstack(ntstack,2); 
            }
            else
            {
                 cout << "string is not accepted" << endl;
                 break;
            }
            
           
         }
         
         if(precedence(stck.top())==10)
         {
            char nt = findntch(stck.top());
            if(nt!='z')
            {
               ntstack.push(nt);
            }
            else
            {
              cout << "string is not accepted" << endl;
              break;
            }
            showstack(ntstack,2);
         }
         
         
         
         stck.pop();
         showstack(stck,1);
         
    }
    if(ntstack.size()==1 && stck.top()=='$' && str[i] == '$' && ntstack.top()==startsymbol)
    {
      cout << endl;
      cout << "string is accepted " << endl;
      break; 
    }
    
  }
   
}
int main()
{ 
  int n;
  string prod[100];
  string input ;
  cout << "Enter a string : "; 
  cin  >> input ; 
  freopen("input.txt","r",stdin);
  
  cin >> n;
  for(int i=0;i<n;i++)
  {
     cin >> prod[i];
  }
  
  startsymbol=prod[0][0];
  
  for(int i=0;i<n;i++)
  {
    
    x.first = prod[i][0];
    x.second = prod[i].substr(3);
    m[x.first].push_back(x.second);
  }
  
  cout << endl;
  cout << "Grammar from the input  :" << endl;
  display(m);
  
  if(grammarcheck(m)==1)
  {
    cout << endl;
    stck.push('$');
    processstring(input);
  }
  else
  {
    cout << "you cannot perform bottom up parsing operations " <<endl;
    return 1;
  }
 
  
  return 0;
}

