#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;
enum enGameChoice{stone=1,paper=2,scissors=3};
enum enWinner{player1=1,computer2=2,draw=3};
struct stRoundInfo{
short roundNumber=1;
enGameChoice player1Choice;
enGameChoice computer2Choice;
enWinner roundWinner;
string roundWinnerName;
};
struct stGameResults{
short roundNumbers;
short player1WinTimes=0;
short computer2WinTimes=0;
short drawTimes=0;
enWinner gameWinner;
string gameWinnerName;
};
int randomNumber(int From,int To)
{
    int randNum=0;
    randNum=rand()%(To-From+1)+From;
    return randNum;
}
short ReadHowManyRounds()    
{
    short GameRounds=1;
    do{
          cout<<"How many Rounds 1 to 10?\n";
          cin>>GameRounds;
       }while((GameRounds<1) || (GameRounds>10));
    return GameRounds;
} 
enGameChoice readPlayer1Choice() 
{
     short choice=1;
     do{
           cout<<"your choice :[1]stone,[2]paper,[3]scissors:\n";
           cin>>choice;
       }while(choice<1 || choice>3);    
     return (enGameChoice)choice;
}     
enGameChoice getComputer2Choice()
{
   return (enGameChoice)randomNumber(1,3);
}
string winnerName(enWinner winner)
{
     string arrWinner[3]={"Player1","Computer2","draw"};
     return arrWinner[winner-1];
}  
string choiceName(enGameChoice Choice)
{
   string arrChoice[3]={"stone","paper","scissors"};
   return arrChoice[Choice-1];
}  
enWinner whoWinnerRound(stRoundInfo RoundInfo)
{
    if(RoundInfo.player1Choice==RoundInfo.computer2Choice)
       return enWinner::draw;
    switch(RoundInfo.computer2Choice)
               {
                   case enGameChoice::stone:
                      {
                         if(RoundInfo.player1Choice==enGameChoice::scissors)
                            return enWinner::computer2;
                      } 
                   break;            
                   case enGameChoice::paper:
                      {
                          if(RoundInfo.player1Choice==enGameChoice::stone)
                            {
                               return enWinner::computer2;
                            }    
                            break;
                      }     
                   case enGameChoice::scissors:
                      {
                         if(RoundInfo.player1Choice==enGameChoice::paper)
                            {
                               return enWinner::computer2;
                            }
                      }
                   break;
               }    
               return enWinner::player1;
}
enWinner whoWinnerGame(short player1WinTimes,short computer2WinTimes)
{
    if(player1WinTimes>computer2WinTimes)
        return enWinner::player1;
    else if(player1WinTimes<computer2WinTimes)
        return enWinner::computer2;
    else
        return enWinner::draw;
}    
void setWinnerScreenColor(stRoundInfo RoundInfo)
{
   if(whoWinnerRound(RoundInfo)==enWinner::player1)
      system("color 2F");
   else if(whoWinnerRound(RoundInfo)==enWinner::computer2)
      {
           system("color 4F");
           cout<<"\a";
      }      
   else
       system("color 6F");
}  
string tabs(short numberOfTabs)
{
   string t="";
   for(int i=1;i<numberOfTabs;i++)
   {
      t = t + "\t";
   }   
   return t;
} 
void ResetScreen()
{
    system("cls");
    system("color 0F");
    
}
void showFinalGameScreen()
{
    cout<<tabs(2)<<"_____________________________________________________\n\n";
    cout<<tabs(2)<<"              +++G a m e    O v e r+++.              \n\n";
    cout<<tabs(2)<<"_____________________________________________________\n\n";
}   
stGameResults fillGameResults(short HowManyRounds,short player1WinTimes,short computer2WinTimes,short drawTimes)
{
    stGameResults GameResults;
    GameResults.roundNumbers=HowManyRounds;
    GameResults.player1WinTimes=player1WinTimes;
    GameResults.computer2WinTimes=computer2WinTimes;
    GameResults.drawTimes=drawTimes;
    GameResults.gameWinner=whoWinnerGame(player1WinTimes,computer2WinTimes);
    GameResults.gameWinnerName=winnerName(GameResults.gameWinner);
    return GameResults;
}
void printRoundResult(stRoundInfo RoundInfo)
{
             cout<<"Round[ "<<RoundInfo.roundNumber<<" ] begins:\n"; 
             cout<<"player1 choice    : "<<choiceName(RoundInfo.player1Choice)<<endl;
             cout<<"computer2 choice  : "<<choiceName(RoundInfo.computer2Choice)<<endl;
             cout<<"round winner      : "<<RoundInfo.roundWinnerName<<endl;    
        
}            
stGameResults playGame(short HowManyRounds)
{
     stRoundInfo RoundInfo;
     short player1WinTimes=0,computer2WinTimes=0,drawTimes=0;
     
     for(short roundNumber=1;roundNumber<=HowManyRounds;roundNumber++)
     {
        RoundInfo.roundNumber=roundNumber;
        RoundInfo.player1Choice=readPlayer1Choice();
        RoundInfo.computer2Choice=getComputer2Choice();
        RoundInfo.roundWinner=whoWinnerRound(RoundInfo);
        RoundInfo.roundWinnerName=winnerName(RoundInfo.roundWinner);
        switch(RoundInfo.roundWinner)
         {
                   case enWinner::computer2:
                   {   
                         ++computer2WinTimes;
                   }  
                   break;    
                   case enWinner::player1:
                    {
                         ++player1WinTimes;
                    }
                   break; 
                   default:
                        ++drawTimes;
         }  
        setWinnerScreenColor(RoundInfo);     
        printRoundResult(RoundInfo);
        setWinnerScreenColor(RoundInfo);
     }
     return fillGameResults(HowManyRounds,player1WinTimes,computer2WinTimes,drawTimes);
}
void PrintGameResults(stGameResults GameResults)
{
    cout<<tabs(2)<<"______________________Game Results_________________\n";
    cout<<tabs(3)<<"Game rounds       :"<<GameResults.roundNumbers<<endl;
    cout<<tabs(3)<<"player1 win times :"<<GameResults.player1WinTimes<<endl;
    cout<<tabs(3)<<"computer2 win times:"<<GameResults.computer2WinTimes<<endl;
    cout<<tabs(3)<<"Final Winner      :"<<GameResults.gameWinnerName<<endl;
    cout<<tabs(2)<<"_____________________________________________________\n\n";
}    
void startGame()
{
     short HowManyRounds;
     stRoundInfo RoundInfo;
     stGameResults GameResults;
     char playAgain='Y';
     do{
          ResetScreen();
          HowManyRounds=ReadHowManyRounds();
          GameResults=playGame(HowManyRounds);
          showFinalGameScreen();
          PrintGameResults(GameResults);
          cout<<tabs(2)<<"Do you want play again? Y/N ?\n";
          cin>>playAgain;
          
       }while((playAgain=='y') || (playAgain=='Y'));
}
int main()
{
   srand((unsigned)time(NULL));
   startGame();
   return 0;
}             
          
         
   
