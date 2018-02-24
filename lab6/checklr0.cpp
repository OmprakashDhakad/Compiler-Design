#include<bits/stdc++.h>
#include <vector>
using namespace std;

pair<char,string> x;
map<char, vector<string> > m;
vector< pair<char, string> > aug;
vector< vector< pair<char, string> > > items;
 
map<char,vector<string> >::iterator it;
map<char,vector<char> >::iterator itr;
vector<string> v;
vector<char> ve;
vector<char> nt;
char startsymbol;
int p=0,q=0,r=0;

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


void display2(map<char, vector<char> > ma)
{
	for(itr=ma.begin();itr!=ma.end();itr++)
	{
		char c = itr->first;
		cout<<c<<" : { ";
		ve = itr->second;
		for(uint i=0;i<ve.size();i++)
		{
			if(i!=0)
			{
				cout<<" , ";
			}
			cout<<ve[i];
		}
		cout<<" }"<<endl;
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

/*void makeclosures(vector<pair<char, string> > vec)
{
  
  // vector<pair<char, string> > vec;
  //pair<char, string> r ;
  
  for(uint i=0;i<vec.size();i++)
  {
     if(vec[i].second.length()>1)
     {
       string str = vec[i].second;
       int x = str.find('.');
       str.substr(0,x);
       
     }
  }

}
*/

string searchpair(vector<pair<char, string> > vec,char ch)
{
  int flag;
  for(uint i=0;i<aug.size();i++)
  {
    //cout << aug[i].first << "----" << aug[i].second << endl;
    if(ch==aug[i].first)
    {
      // cout << "ch  = " << ch << endl;
       for(uint j=0;j<vec.size();j++)
       {
          flag =0 ;
          //cout << "Same  = ";
          if(vec[j].first==aug[i].first && vec[j].second==aug[i].second)
          {
            //cout << "hai " << endl;
            flag = 1;
            break;
          }
          else
          {
            //cout << " nhi " << endl;
          }
       }
       if(flag==1)
       {
         continue;
       }
       else
	   {
	     //cout  << "return should be  ="<< aug[i].second << endl; 
	     return aug[i].second;
	   }
    }
  }
  return "abc";
}

void makeitems(char first,string second)
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
		   string str = searchpair(vec,(vec[i].second)[x+1]);
		   //cout  << "str =  " << str << endl;
		   if(str!="abc" && isExist(vec,(vec[i].second)[x+1],str)==0)
		   {
		      //cout << "content pushed " << endl;
		      vec.push_back(make_pair((vec[i].second)[x+1],str));
		   }
		}
		
    }
  }
   cout << "I0 items "<< endl; 
   for(uint j=0;j<vec.size();j++)
   {
     cout << vec[j].first << "->" << vec[j].second << endl;
   }
  
  items.push_back(vec);
  
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
  makeitems(aug[0].first,aug[0].second);
  
  
  return 0;
}
