/*
   NAME  - OMPRAKASH
   ID    - 2015KUCP1028
   Assumption in augmented grammar S' is A SO don't take A in grammar use another symbol

*/
#include<bits/stdc++.h>
#include <vector>
using namespace std;

pair<char,string> x;
map<char, vector<string> > m;
vector< pair<char, string> > aug;
vector< vector< pair<char, string> > > items;
vector< vector< pair<char , string> > > itemss;

map<char,vector<string> >::iterator it;
map<char,vector<char> >::iterator itr;
vector<string> v;
vector<char> ve;
vector<char> nt;
char startsymbol;
int p=0,q=0,r=0;
int tim=1;

void makeaugmented()
{
  for(it=m.begin();it!=m.end();it++)
	{
		char c = it->first;
		
		v = it->second;
		for(uint i=0;i<v.size();i++)
		{
			string str = "." + v[i];
			aug.push_back( make_pair(c,str) );
			
		}
	}
}

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

void display1()
{
	for(uint i=0;i<aug.size();i++)
	{
		cout << aug[i].first << "->"<< aug[i].second << endl;
	}
}


int isnonterminal(char ch)
{
  if(ch >= 65 && ch <= 90)
  return 1;
  else
  return 0;
}

int isExist(vector<pair<char, string> > vec,char first,string str)
{
  for(uint i=0;i<vec.size();i++)
  {
    if(vec[i].first==first && vec[i].second==str)
    {
       return 1;  
    }
  }
  return 0;
}

int isExist2(vector<pair<char, string> > vec)
{
  int count ;
  
  for(uint i=0;i<items.size();i++)
  {
    
    if(vec.size()==items[i].size())
    {
        count =0;
		for(uint j=0;j<items[i].size();j++)
		{
		    
			if(vec[j].first==items[i][j].first && vec[j].second==items[i][j].second)
			{
			   count++;
			}
			if(count==(int)vec.size())
			{
			  return 1;
			}
		}
	}
	
  }
  return 0;
}

vector< pair <char,string> > searchpair(vector< pair <char,string> > vec,char ch)
{
  
  for(uint i=0;i<aug.size();i++)
  {
    if(ch==aug[i].first)
    {
       if(isExist(vec,aug[i].first,aug[i].second)==0)
       {
         vec.push_back(make_pair(aug[i].first,aug[i].second));
       }
    }
  }
  return vec;
}

void makeitemI0(char first,string second)
{
  vector< pair <char,string> > vec ;
  vec.push_back(make_pair(first,second));
  
  for(uint i=0;i<vec.size();i++)
  {
    int x = vec[i].second.find('.');
    if(x!=-1)
    {
       if(isnonterminal((vec[i].second)[x+1])==1)
		{
		   vec = searchpair(vec,(vec[i].second)[x+1]);
		   
		}
		
		
    }
  }
    
    items.push_back(vec);
   
}


void makeclosures(vector<pair<char, string> > vec)
{

  set<char> se;
  se.clear();
  for(uint i=0;i<vec.size();i++)
  {
    int x = vec[i].second.find('.');
    if(x!=-1 && x+1!=(int)vec[i].second.length())
    {
      se.insert((vec[i].second)[x+1]);
    }
   
  }
  set <char> :: iterator itr;
  
  for(itr=se.begin();itr!=se.end();itr++)
  {
     char ch = *itr;
     vector< pair <char,string> > vi;
     
     for(uint i=0;i<vec.size();i++)
     {
        int y = vec[i].second.find('.');
        if(y!=-1 && y+1!=(int)vec[i].second.length())
		{
		   
		   if(ch == (vec[i].second)[y+1])
		   {
		       
		       string str1 = vec[i].second;
			   char c = str1[y] ;
			   str1[y] = str1[y+1];
			   str1[y+1] = c;
			   
			   vec[i].second = str1;
			   
			   vi.push_back(make_pair(vec[i].first,str1));
			   
			   if(isnonterminal(str1[y+2])==1)
		       {
		          vi = searchpair(vi,str1[y+2]);
		       }
		   }
		}
		
      
     }
     if(isExist2(vi)==0)
     {
        items.push_back(vi);
     }
  }

}


int main()
{
 
  int n;
  string prod[100];
  
  
  freopen("input.txt","r",stdin);
  
  cin >> n;
  for(int i=0;i<n;i++)
  {
     cin >> prod[i];
  }
  cout << "Input from the file : "<<endl;
  for(int i=0;i<n;i++)
  {
     cout << prod[i] << endl;
  }
  
  int count =0;
  for(int i=0;i<n;i++)
  {
    if(count==0)
    {
      startsymbol=prod[i][0];
      count++;
    }
    x.first = prod[i][0];
    if(find(nt.begin(),nt.end(),prod[i][0])==nt.end())
    {
      nt.push_back(prod[i][0]);
    }
    x.second = prod[i].substr(3);
    m[x.first].push_back(x.second);
  }
  cout << "Augmented Grammar :" << endl;
  string strtsym = "";
  strtsym = strtsym + startsymbol;
  m['A'].push_back(strtsym);
  makeaugmented();
  display1();
  makeitemI0(aug[0].first,aug[0].second);
  
  cout << endl;
  for(uint i=0;i<items.size();i++)
  {
      makeclosures(items[i]);
  } 
  
  for(uint i=0;i<items.size();i++)
  {
    cout << "-------item I"<<i<<"-----"<<endl;
    for(uint j=0;j<items[i].size();j++)
    {
      cout <<items[i][j].first << "->" << items[i][j].second << endl;  
    }
  }
  
 
  return 0;
}
