#include <iostream>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

using namespace std;
char gameboard[3][3];
const char P1='X';
const char C1='O';
void comview();
void showboard();
int freespace();
void pmove();
void cmove();
char winner();
void showwinner(char a);

int i,j;
int main()
{
    char vic = ' ';
    char res = ' ';
    do
    {
        
        vic=' ';
        res=' ';
    
    
    comview();
    
   
    while (vic== ' ' && freespace() != 0)
    {
        showboard();
        pmove();
        vic=winner();
        if(vic != ' ' || freespace() == 0)
         {
            break;
         }

         cmove();
        vic = winner();
         if(vic != ' ' || freespace() == 0)
         {
            break;
         }
    }
    
    showboard();
    showwinner(vic);
    cout<<"Would you like to play again?(Y/N):";
    cin>>res;
    res=toupper(res);
    }while(res=='Y');
    
    return 0;
}
void comview()
{
    for ( i = 0; i < 3; i++)
    {
        for( j = 0; j < 3; j++)
        {
            gameboard[i][j]=' ';
        }
        
    }
    
}
void showboard()
{   
   cout<<" ___________"<<endl; 
   cout<<"|-----------|"<<endl;
   cout<<"| "<<gameboard[0][0]<<" | "<<gameboard[0][1]<<" | "<<gameboard[0][2]<<" |"<<endl;
   cout<<"|-----------|"<<endl;
   cout<<"| "<<gameboard[1][0]<<" | "<<gameboard[1][1]<<" | "<<gameboard[1][2]<<" |"<<endl;
   cout<<"|-----------|"<<endl;
   cout<<"| "<<gameboard[2][0]<<" | "<<gameboard[2][1]<<" | "<<gameboard[2][2]<<" |"<<endl;
   cout<<"|-----------|"<<endl;
}
int freespace()
{
    int spaces=9;
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
             if(gameboard[i][j] != ' ')
         {
            spaces--;
         }
        }
        
    }
    return spaces;
    

}
void pmove()
{
    int x;
   int y;

   do
   {
      cout<<"Enter row #(1-3): "<<endl;
      cin>>x;
      x--;
      cout<<"Enter column #(1-3): "<<endl;
      cin>>y;
      y--;

      if(gameboard[x][y] != ' ')
      {
         cout<<"Invalid move!"<<endl;
      }
      else
      {
         gameboard[x][y] = P1;
         break;
      }
   } while (gameboard[x][y] != ' ');
}
void cmove()
{
    srand(time(0));
   int x;
   int y;

   if(freespace() > 0)
   {
      do
      {
         x = rand() % 3;
         y = rand() % 3;
      } while (gameboard[x][y] != ' ');
      
      gameboard[x][y] = C1;
   }
   else
   {
      showwinner(' ');
   }
}
char winner()
{
    for(int i = 0; i < 3; i++)
   {
      if(gameboard[i][0] == gameboard[i][1] && gameboard[i][0] == gameboard[i][2])
      {
         return gameboard[i][0];
      }
   }
   
   for(int i = 0; i < 3; i++)
   {
      if(gameboard[0][i] == gameboard[1][i] && gameboard[0][i] == gameboard[2][i])
      {
         return gameboard[0][i];
      }
   }
   
   if(gameboard[0][0] == gameboard[1][1] && gameboard[0][0] == gameboard[2][2])
   {
      return gameboard[0][0];
   }
   if(gameboard[0][2] == gameboard[1][1] && gameboard[0][2] == gameboard[2][0])
   {
      return gameboard[0][2];
   }

   return ' ';
}
void showwinner(char vic)
{

     if(vic == P1)
   {
      cout<<"YOU WIN,>:)!"<<endl;
   }
   else if(vic == C1)
   {
      cout<<"YOU LOSE!>:()"<<endl;
   }
   else{
      cout<<"iTS A TIE!|:\\"<<endl;
   }
}