#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;
enum enGameChoice{stone=1,paper=2,scissors=3};
int ReadNumber(int From,int To,string messege)
{
	   int Number;
	  do{
	  	     cout<<messege<<endl;
	  	     cin>>Number;
	    }while((Number<From)  || (Number>To)); 
      return Number;
}	  	 
int RandomNumber(int From,int To)
{
	  int randNum=0;
	  randNum=rand()%(To-From+1)+From;
	  return randNum;
}	
enGameChoice GameChoice(int Number)  
{
	   switch(Number)
	   {
	   	case 1:
	   	    return enGameChoice::stone;
	   	case 2:
	   	   return enGameChoice::paper;
	   	case 3:
	   	   return enGameChoice::scissors;
	   }
}
void PrintChoice(int Number)
{
	  switch(GameChoice(Number))
	  {
	    case enGameChoice::stone:
	         {
	         	  cout<<"stone"<<endl;
	         	  break;
	         }
	    case enGameChoice::paper:
	        {
	        	  cout<<"paper" <<endl;
	        	  break;
	        }
	    case enGameChoice::scissors:
	        {
	        	 cout<<"scissors"<<endl;
	        	 break;
	       }
	   default:
	       cout<<endl;
      }     
}	        	  	               	        	      	  	
int IsPlayerwinsOrFailsOrEqualsWithComputer(int Number1,int Number2) 
 {
	   if(((Number1==1) && (Number2==3)) || ((Number1==2) && (Number2==1)) || ((Number1==3) && (Number2==2)))
	   return 1;
	 else if(Number1==Number2)
	     return -1;
	 else
	    return 0;
}
void PrintRoundWinner(int Number1,int Number2)
{
	    if(IsPlayerwinsOrFailsOrEqualsWithComputer(Number1,Number2)==0)
	       cout<<"[Computer]"<<endl;
        else if(IsPlayerwinsOrFailsOrEqualsWithComputer(Number1,Number2)==1)
               cout<<"[Player]"<<endl;
        else
               cout<<"[No wonner]"<<endl;
}
void PrintRoundFirst(int rounds,int& Number1,int& Number2,int i)    
{
	       	  	   cout<<"Round [ "<<i<<" ] begines:\n";
	       	  	   Number1=ReadNumber(1,3,"Your choice : [1]:stone, [2]:paper, [3]:scissors  ?");
	       	  	   Number2=RandomNumber(1,3);
	       	  	   cout<<"\n"<<endl;
	       	  	   cout<<"_______________Round ["<<i<<"]_______________"<<endl;
}
void PrintAddress(string address)
{
   cout<<address;
}  
void PrintTowPointsAboveSome(string address,int NumberOfCharacters)
{
     int Length=address.length();
	     	     if(Length<NumberOfCharacters)    
   	  	      {
	     	        	 for(int i=Length;i<NumberOfCharacters;i++)
	     	        	     cout<<" ";
	     	      
	     	             cout<<":";
                   }  
                   else
                      cout<<":";
}	
void PrintRoundResult(string address,int NumberOfCharacters,int Number1,int Number2)
{
    
    PrintAddress("Player1 Choice");
    PrintTowPointsAboveSome("Player1 Choice",15);
    PrintChoice(Number1);
    PrintAddress("Computer Choice");
    PrintTowPointsAboveSome("Computer Choice",15);
    PrintChoice(Number2);
    PrintAddress("Round Winner");
    PrintTowPointsAboveSome("Round Winner",15);
    PrintRoundWinner(Number1,Number2); 
    cout<<"\n_______________________________________________\n";
        
}      
void Counter(int rounds,int& Player1WonTimes,int& ComputerWonTimes,int& DrawTimes,int Number1,int Number2)     
{
	 
       	if(IsPlayerwinsOrFailsOrEqualsWithComputer(Number1,Number2)==1)      
	   	    Player1WonTimes++;
	   	 else if(IsPlayerwinsOrFailsOrEqualsWithComputer(Number1,Number2)==0)
	   	    ComputerWonTimes++;
	   	 else
	   	     DrawTimes++;
       
}
void PrintFinalWinnerInGame(int rounds,int Player1WonTimes,int ComputerWonTimes)
{
	   if(Player1WonTimes>ComputerWonTimes)
	      cout<<"player"<<endl;
	   else if(Player1WonTimes<ComputerWonTimes)
	      cout<<"Computer"<<endl;
	   else
	       cout<<"No Wonner"<<endl;
	      
}
void PrintAddressGameResults()
{
	     cout<<"______________________________________________________________\n";
cout<<"\t\t\t+++ G a m e 	 O v e r +++\t\t\t\n"; cout<<"___________________________________\n\n";
cout<<"_________________________  [ Games Results ]  ____________________________\n\n";
}
void PrintGameResults(string address,int rounds,int Player1WonTimes,int ComputerWonTimes,int DrawTimes)
{
    int Number1,Number2;
    PrintAddress("Game Rounds");
    PrintTowPointsAboveSome("Game Rounds",20);
    cout<<rounds<<endl;
    PrintAddress("Player1 Won Times");
    PrintTowPointsAboveSome("Player1 won Times",20);
    cout<<Player1WonTimes<<endl;
    PrintAddress("Computer Won Times");
    PrintTowPointsAboveSome("Computer Won Times",20);
    cout<<ComputerWonTimes<<endl;
    PrintAddress("Draw Times");
    PrintTowPointsAboveSome("Draw Times",20);
    cout<<DrawTimes<<endl;
    PrintAddress("Final Winner");
    PrintTowPointsAboveSome("Final Winner",20);
    PrintFinalWinnerInGame(rounds,Player1WonTimes,ComputerWonTimes);
    cout<<"\n\n______________________________________________\n";
        
}      
void GetColor(int Number1,int Number2)
{
    if(IsPlayerwinsOrFailsOrEqualsWithComputer(Number1,Number2)==1)
       system("color 2F");
    else if(IsPlayerwinsOrFailsOrEqualsWithComputer(Number1,Number2)==0)
        system("color 4F");
    else
         system("color 6F");
                
}       

int main()
{
       srand((unsigned)time(NULL));
	   int Number1,Number2,rounds;
       string address;
	   char more='Y';
	   int Player1WonTimes=0,ComputerWonTimes=0,DrawTimes=0;
	   int NumberOfCharacters;
	do{   
	    rounds=ReadNumber(1,10,"How many rounds 1 to 10?"); 	   
	    for(int i=1;i<=rounds;i++)
	       {
	         	PrintRoundFirst(rounds,Number1,Number2,i);
	         	GetColor(Number1,Number2);
                 Counter(rounds,Player1WonTimes,ComputerWonTimes,DrawTimes,Number1,Number2);
	         	PrintRoundResult(address,NumberOfCharacters,Number1,Number2);
	       }
            
	        PrintAddressGameResults();
	        PrintGameResults(address,rounds,Player1WonTimes,ComputerWonTimes,DrawTimes);
	        cout<<"Do you want to play again? y/N?\n";
	        cin>>more;
	  }while(more=='Y');
	  return 0;
}	               	    	         	     	     
	   	 
