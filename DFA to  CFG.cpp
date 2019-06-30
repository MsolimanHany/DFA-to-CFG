#include <cstdlib>
#include <iostream>

using namespace std;
bool times(string len,string u,char m)
         {
             int i=0;
            
             for(int s=0;s<u.length();s+=4)
             {
             if(u[s]==m)
             i++;
             
             }
             if(i==len.length())
             return 1;
             else
             return 0;
             
             }
string loop_element(char s,string n)
{
      string m; 
      for(int i=0;i<n.length();i+=4)
      {
       if(n[i]==s)      
       m+=n[i+1];
      }
      return m;
      }
     bool isexist(string N,char s){ 
          bool y=0;
     for(int i=0;i<N.length();i++)
     {
       if (N[i]==s)
       {
       y=1;
       break;
       }
       }     
     return y;
     
     }
    bool inlist(string N,char m){
         bool t=0;
         for(int i=0;i<N.length();i++)
         if(N[i]==m)
         t=1;
         return t;
         }
        
    
         
           bool NOsearch3(string n,char a,char b,char c)
             {
                  int j=0,i=1,s=2;
                  bool y=true;
                  int u=0;
                  while(n.length()!=u)
                  {
                  if(n[j]==a&&n[i]==b&&n[s]==c)
                  y=false;
                  j+=4,i+=4,s+=4;
                  u+=4;
                  }                    
                  return y;
                
                  }
  int main(int argc, char *argv[])
{
  
     int i=0,q=1,j=2,s=3; //add 4 in every level   j+1 means end of array if equal to {.}
    //Note the states and transitions enter the program orderd and states (upper case letters as A B  ) 
    //Note the transitions entering as  {A0BA1B} every 3 letters represents transition
    // terminals not equal any letter in (upper case) such as A,B,...
    //We need to enter states,start,accepted,transition function for every state (ordered state)
    string states="";
    char start;
    string accept="";
    string alpha="";
  
    string tran=""; //comma easy to process
    string loop;
    string check; //without loop state
    string Flist;
    string hang;
    int ko=0;
    bool cont=0;
    while(cont==0)
    {
    
    cout<<"please enter your DFA componenth:"<<endl;
    cout<<"Enter your states(only upper case letters):"<<endl;
    cout<<"one upper case letter for every state"<<endl;
    cin>>states;
    for(int i=0;i<states.length();i++)
    {
     char a=states[i];       
      if(!isupper(a))
      {
       cont=1;
      cout<<"ERROR Please enter the states as uppercase letters"<<endl;
      break;                         
      }                              
    }
    if(cont==1)
    break;
    cout<<"Enter your start state:"<<endl;
    cin>>start;

    if(!inlist(states,start))
    {
     cout<<"ERROR Please enter the start state in uppercase and includes in your states"<<endl;
     cont=1;
     break;                                       
    }                                       
    cout<<"Enter your accept state: "<<endl;
    cin>>accept;
    if(accept.length()>states.length())
    {
    cont=1;
     cout<<"ERROR Please enter the num of accept states <= num of states"<<endl;
     break;                                   
}                                  
    for(int i=0;i<accept.length();i++)
    {
     char a=accept[i];       
      if(!isupper(a)||!inlist(states,a))
      {
       cont=1;
      cout<<"ERROR Please enter the accept states in uppercase and includes in your states"<<endl;
      break;                         
      }                              
    }
    if(cont==1)
    break;
    cout<<"Enter your alphabet (Except upper case letters):"<<endl;
    cin>>alpha;
    for(int i=0;i<alpha.length();i++)
    {
     char a=alpha[i];       
      if(isupper(a)||a=='.'||a==',')
      {
       cont=1;
      cout<<"ERROR Please enter the alphabet as lowercase letters or any symbol!='.' or ','"<<endl;
      break;                         
      }                              
    }
    if(cont==1)
    break;
    cout<<"Enter your transition for every state       example: A0B,A1N.   in this form "<<endl;
    cin>>tran;
    int q=tran.length()-1;
    
    for(int i=0;i<tran.length();i++)
    {
               
     char a=tran[i];
     if(!inlist(states,a))
     {
       cout<<"ERROR Please enter the transitions in above form"<<endl;
       cont=1;
       
       break;                  
     }                   
     i++;
      a=tran[i];
     if(!inlist(alpha,a))
     {
       cout<<"ERROR Please enter the transitions in above form"<<endl; 
       cont=1;
       
       break;                 
     }
     i++;
      a=tran[i];
     if(!inlist(states,a))
     {
       cout<<"ERROR Please enter the transitions in above form"<<endl;
       cont=1;
       break;                  
     }                   
    
       i++;
      a=tran[i];
     if((a!=',' && i!=q)|| (a=='.'&& i!=q) ||(a==','&&i==q))
     {
       cout<<"ERROR Please enter the transitions in above form"<<endl;
       cont=1;
       
       break;                  
     }      
                                         
    }
    if(cont==1)
    break;
   break; //END
}
     if(cont==0)
   {
   cout<<"Your Context free grammer :"<<endl;                
    while(ko!=tran.length()) //loops and checks
    {
    
     if(tran[i]==tran[j])
     {
     loop+=tran[i]; loop+=tran[q]; loop+=tran[j]; loop+=tran[s]; 
    
     //comma or .
     
      i=i+4; j=j+4;q=q+4; s=s+4; ko+=4;
      
      }
     
     else
     {
         check+=tran[i]; check+=tran[q]; check+=tran[j]; check+=tran[s];
         
      i=i+4;j=j+4; q=q+4; s=s+4; ko+=4;
      
         }
         }
       
       
       //for hang
    if(loop.length()>0)
     {
      for(int k=0;k<loop.length();k+=4)
      {
       if(!inlist(hang,loop[k]))
       {       

       bool n=times(alpha,loop,loop[k]);
       
        if(n==1&& !isexist(accept,loop[k]))
        hang+=loop[k];
        }    
        }
        }
        //remove hang from check produce Ncheck
         string  Ncheck,Nloop;
        if(hang.length()>0)
        {
    
     int ran=0;
     int ran2=0;
      int ran3=0;
      i=0,q=1,j=2,s=3;
     if(hang.length()>0)
     {
      int h=hang.length();
      while(ran!=h)
      {
                   
      while(ran2!=check.length())
      {    
          
                  
      if(hang[ran]!=check[i] && hang[ran]!=check[j])
      {
                              if(inlist(hang,check[i])||inlist(hang,check[j])) //not inhang
             ;
             else
             {
                             
          if(NOsearch3(Ncheck,check[i],check[q],check[j])) //not repeted in check
             {     
         Ncheck+=check[i]; Ncheck+=check[q]; Ncheck+=check[j]; Ncheck+=check[s];
         }
         }
         }
         
         i=i+4;j=j+4; q=q+4; s=s+4; ran2+=4;
         } 
         
         i=0,q=1,j=2,s=3;
          while(ran3!=loop.length())
      { 
          
         if( hang[ran]!=loop[i])
         {
             if(inlist(hang,loop[i]))
             ;
             else
             {
             if(NOsearch3(Nloop,loop[i],loop[q],loop[j]))
             {
                 
          Nloop+=loop[i]; Nloop+=loop[q]; Nloop+=loop[j]; Nloop+=loop[s];
          }
          }
          }
          
           i=i+4;j=j+4; q=q+4; s=s+4;ran3+=4;
            
          }
            
          ran++;    ran2=0;ran3=0;
          i=0,q=1,j=2,s=3;         
      }
                    
                    }
                    }
                  if(hang.length()==0)
                  {
                    for(int r=0;r<check.length();r++)
                    Ncheck+=check[r];
                    
                    for(int m=0;m<loop.length();m++)
                    Nloop+=loop[m];  
                    }
                    
                    //cout<<Ncheck<<endl; 
                    string List;
                    List+=start;
                   
                    //cout<<List<<endl;
                    //we own Ncheck,Nloop ,List    A->0B|1C    Go for Fun list finished or not
                    bool acceptt;
                    bool isloop;
                    int index=0;
                    string numloop;//elements loop
                    int after;
                    string Rule;
                    int ok=0;
                    string All;
                    char To;
                    while(List[index]!=NULL)
                    {
                                            
                       acceptt=isexist(accept,List[index]);//is accept                     
                       isloop=isexist(Nloop,List[index]);//isloop
                       if(acceptt)
                       {
                       Rule+="epslon";
                       Rule+="|";
                       }
                       if(isloop)
                       {
                        string hh;
                        hh+=loop_element(List[index],Nloop);
                        for(int q=0;q<hh.length();q++)
                        {
                           Rule+="LOOP(";
                           Rule+=hh[q];
                           Rule+=")";
                           if(q==hh.length()-2)
                           Rule+="|";
                           Rule+=" ";
                                         
                        }
                        }
                        ok=0;// or  |
                         for(int x=0;x<Ncheck.length();x+=4) //num of or (|)
                        {
                                
                          if(List[index]== Ncheck[x])
                          ok++;
                          }
                        int ok2=0;
                        for(int x=0;x<Ncheck.length();x+=4)
                        {
                                
                          if(List[index]== Ncheck[x])
                          {
                         ok2++;                  
                         int k=x;
                           Rule+=Ncheck[k+1];
                           To= Ncheck[k+2];
                           
                           if(!isexist(List,To))
                           List+=To;
                           Rule+=To;
                          
                           if(ok2<ok)
                            Rule+="|";
                            }
                            }
                            cout<<List[index]<<"->"<<" "<<Rule<<endl<<endl;
                            index++; 
                            Rule="";
                                        
                          } 
                          string ppp;
                          if(Nloop.length()!=0)
                          {
                                               
                          for(int i=1;i<Nloop.length();i+=4)//Looooooooooooooooooooooooping
                          {
                          if(!isexist(ppp,Nloop[i]))
                          {
      
                           ppp+=Nloop[i];;
                           }
                           }
                           
                            for(int i=0;i<ppp.length();i++)
                            cout<<"Loop("<<ppp[i]<<")-> "<<ppp[i]<<" Loop("<<ppp[i]<<")| epslon"<<endl<<endl;          
                           }               
                                  
                                  } //cont==0             
                                  
                       
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
