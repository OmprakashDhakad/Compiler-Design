#include<bits/stdc++.h>
using namespace std;

pair<char,char> x;
map<char, vector<string> > m;
map<char, vector<char> > first;
map<char, vector<char> > follow;
map<pair<char,char>, string > table;

map<char,vector<string> >::iterator it;
map<char,vector<char> >::iterator itr;
vector<string> v;
vector<char> ve;
vector<char> nt;
char startsymbol;
int ll1=0;
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

void display1(map<pair<char,char>, string > table)
{
	for(auto it=table.begin();it!=table.end();it++)
	{
	      
		char c = it->first.first;
		char d =  it->first.second;
		cout<< "(" << c <<"," << d << ") : " ;
		cout << it->second << endl;
	}
}

bool checkll1(char ch)
{
	 vector<string> v;
	 vector<char> ve;
     v = m[ch] ;
     uint i;
       for(i=0;i<v.size();i++)
       {
           
         uint count=0;
         for(uint j=0;j<v[i].length();j++)
         {
               int flag=0;
               
		   if(v[i][j]>90 || v[i][j]<65)
		   {
		      if(v[i][j]=='#')
		      {
		           ve = follow[ch];
	      
				for(uint z=0;z<ve.size();z++)
				{
				
				      
					string s = ""; 
					x.first = ch;
					x.second = ve[z];
					if(table[x]!="")
					{
					   return false;
					}
					table[x] = s + ch + "->"+ v[i];
		
				}
		      }
		      else
		      {
		            
				string s = ""; 
				x.first = ch;
				x.second = v[i][j];
				if(table[x]!="")
				{
				   return false;
				}
				table[x] = s + ch + "->"+ v[i];
				
		      }
		      break;
		   }
		   else
		   {
		      ve = first[v[i][j]];
		      
		      for(uint l=0;l<ve.size();l++)
		      {
		         
		           if(ve[l]=='#')
		           {
		              flag=1;
		              count++;
		           }
		           else 
				{
				      
				      string s = ""; 
				      x.first = ch;
					x.second = ve[l];
					if(table[x]!="")
					{
					   return false;
					}
					
					table[x] = s + ch + "->"+ v[i];
					
				}
		        
		      }
		      if(flag==0)
		      {
		        break;
		      }
		   
		       
		   }
		  
	   }
	   if(count==v[i].length())
	   {
	      ve = follow[ch];
	      
	      for(uint z=0;z<ve.size();z++)
	      {  
	            
	            string s = ""; 
		      x.first = ch;
			x.second = ve[z];
			if(table[x]!="")
			{
			   return false;
			}
			table[x] = s + ch + "->"+ v[i];
		
	      }  
	   }
	    
       }
       return true;
       
  
}

void findfirst(char ch)
{
	 vector<string> v;
	 vector<char> ve;
       v = m[ch] ;
       int flag=0;
       
       for(uint i=0;i<v.size();i++)
       {
         
         uint count=0;
         for(uint j=0;j<v[i].length();j++)
         {
               flag=0;
               
		   if(v[i][j]>90 || v[i][j]<65)
		   {
		      
		      if(find(first[ch].begin(),first[ch].end(),v[i][j])==first[ch].end())
		      {
		         first[ch].push_back(v[i][j]);
		      }
		      break;
		   }
		   else
		   {
		      findfirst(v[i][j]);
		     
		      ve = first[v[i][j]];
		      
		      for(uint l=0;l<ve.size();l++)
		      {
		         
		           if(ve[l]=='#')
		           {
		              flag=1;
		              count++;
		           }
		           else if(find(first[ch].begin(),first[ch].end(),ve[l])==first[ch].end())
				{
				   first[ch].push_back(ve[l]);
				}
		        
		      }
		      if(flag==0)
		      {
		        break;
		      }
		   
		       
		   }
		  
	   }
	   if(count==v[i].length())
	   {
	     first[ch].push_back('#');
	   }
	    
       }
  
}

void findfollow(char ch)
{
       
     
     for(uint h = 0;h<nt.size();h++)
     {  
       for(uint i=0;i<m[nt[h]].size();i++)
       {
         string str = (m[nt[h]])[i];
         for(uint j=0;j<str.length();j++)
         {   
               
             if(str[j]==ch)
             {
               int flag = 0;
               uint count;
               if((str[j]>90 || str[j]<65))
               {
                 
               }
               else
               {   
                   count = 0;
                   for(uint k=j+1;k<str.length();k++)
                   {
                     flag = 0;
                     if(str[k]>90 || str[k]<65)
				     {
				        if(find(follow[str[j]].begin(),follow[str[j]].end(),str[k])==follow[str[j]].end())
				        {
				           follow[str[j]].push_back(str[k]);
				        }
				     }
                     else
                     {
		               ve = first[str[k]];
		               for(uint l=0;l<ve.size();l++)
		               {
		                 if(ve[l]=='#')
		                 {
		                   flag=1;
		                   count++;
		                 }
		                 else if(find(follow[str[j]].begin(),follow[str[j]].end(),ve[l])==follow[str[j]].end())
						{
						   follow[str[j]].push_back(ve[l]);
						}
				     
				   }
				   if(flag==0)
				   {
				     break;
				   }
		        }
		     }
	          if(count==(str.length()-(j+1)))
			   {
				ve = follow[nt[h]];
				for(uint z=0;z<ve.size();z++)
				{
					if(find(follow[str[j]].begin(),follow[str[j]].end(),ve[z])==follow[str[j]].end())
					{
					   follow[ch].push_back(ve[z]);
					}
				}
			   }
		   }
         }
       }
      }   
	    
       
  }
}

int main()
{
 
  int n;
  string prod[100];
  
  //FILE* fp;
  freopen("ll1.txt","r",stdin);
  
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
    string xs=prod[i].substr(3);
    m[x.first].push_back(xs);
  }
  cout << "content in the map :" << endl;
  display(m);
  
  //find first of productions
  for(it=m.begin();it!=m.end();it++)
  {
        findfirst(it->first);
  }
  
  cout << endl;
  cout << "first of the productions : "<<endl;
  display2(first);
  
  //find follow of productions
  follow[startsymbol].push_back('$');
  
  for(uint i=0;i<nt.size();i++)
  {
       
        findfollow(nt[i]);
  }
  
  cout << endl; 
  cout << "follow of the productions : "<<endl;
  display2(follow);
  bool isll=true;
  //find the first in string 
  for(uint i=0;i<nt.size();i++)
  {
        
        isll&=checkll1(nt[i]);
       
  }
  cout << endl;
  cout << "Table values acc to the (row,column) -> value : "<<endl;
  display1(table);
  if(isll)
  {
  	cout<<"Grammar is LL1"<<endl;
  }
  else
  {
  	cout<<"Grammar is not LL1"<<endl;
  }
  
  //cout<<table<<endl;
  return 0;
}
