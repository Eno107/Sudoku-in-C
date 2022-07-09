#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void board_creating(int board[9][9])
{
  for (int i=0;i<9;i++)
    {
      if (i%3==0)
      {
        printf("\n");
      }
      for (int j=0;j<9;j++)
        {
          if (j%3==0)
          {
            printf("\t");
          }
          printf("%d|",board[i][j]);
        }
      printf("\n");
    }
}

void board_generating(int board[9][9])

{
  srand(time(0));
  for (int j=0;j<3;j++)
    {
      int m= rand()%(2-0+1)+0;
      int n= rand()%(2-0+1)+0;
      board[n][m] = rand()%9+1;
      board[n][m+3] = rand()%9+1;
      board[n][m+6] = rand()%9+1;
      board[n+3][m] = rand()%9+1;
      board[n+3][m+3] = rand()%9+1;
      board[n+3][m+6] = rand()%9+1;
      board[n+6][m] = rand()%9+1;
      board[n+6][m+3] = rand()%9+1;
      board[n+6][m+6] = rand()%9+1;
    }
}




void checker(int board[9][9],int x,int y,int nr)
{
  int checker=0;
  if (x>=9 || x<0 || y>=9 || y<0)
  {
    printf ("Wrong input");
  }
  if (x<=2 && y<=2)
  {
    for (int i=0;i<3;i++)
      {
        for (int j=0;j<3;j++)
          {
            if (board[i][j]==nr)
            {
              checker=1;
            }
          }
      }
  }
  if (x<=2 && y>=3 && y<=5)
  {
    for (int i=0;i<3;i++)
      {
        for (int j=3;j<6;j++)
          {
            if (board[i][j]==nr)
              checker=1;
          }
      }
  }
  if (x<=2 && y>=6)
  {
    for (int i=0;i<3;i++)
      {
        for (int j=6;j<9;j++)
          {
            if (board[i][j]==nr)
              checker=1;
          }
      }
  }
  if (x>=3 && x<=5 && y<=2)
  {
    for (int i=3;i<6;i++)
      {
        for (int j=0;j<3;j++)
          {
            if (board[i][j]==nr)
            {
              checker=1;
            }
          }
      }
  }
  if (x>5 && y<=2)
  {
    for (int i=6;i<9;i++)
      {
        for (int j=0;j<3;j++)
          {
            if (board[i][j]==nr)
            {
              checker=1;
            }
          }
      }
  }
  if (x>=3 && x<=5 && y>=3 && y<=5)
  {
    for (int i=3;i<6;i++)
      {
        for (int j=3;j<6;j++)
          {
            if (board[i][j]==nr)
            {
              checker=1;
            }
          }
      }
  }
  if (x>=3 && x<=5 && y>=6 )
  {
    for (int i=3;i<6;i++)
      {
        for (int j=6;j<9;j++)
          {
            if (board[i][j]==nr)
            {
              checker=1;
            }
          }
      }
  }
  if (x>=6 && y>=3 && y<=5)
  {
    for (int i=6;i<9;i++)
      {
        for (int j=3;j<6;j++)
          {
            if (board[i][j]==nr)
            {
              checker=1;
            }
          }
      }
  }
  if (x>=6 && y>=6)
  {
    for (int i=6;i<9;i++)
      {
        for (int j=6;j<9;j++)
          {
            if (board[i][j]==nr)
            {
              checker=1;
            }
          }
      }
  }
for (int j=0;j<9;j++)
      {
        if (board[x][j]==nr)
        {
          checker=1;
         }

      }
    for (int i=0;i<9;i++)
      {
        if (board[i][y]==nr)
        {
          checker=1;
        }
      }

  if (checker==1)
    printf("\n~~Not possible~~\n");
  else
  {
    board[x][y]=nr;
    board_creating(board);
  }

}

int main ()
{
  int board[9][9];
  int x,y,nr;
  for (int i=0;i<9;i++)
    {
      for (int j=0;j<9;j++)
        {
          board[i][j]=0;
        }
    }
  board_generating(board);
  board_creating(board);
  while (1)
    {
  printf("Pick a cell and write a number in it\n");
  printf("Enter cell location: ");
  scanf("%d %d",&x,&y);
  printf("Enter number: ");
  scanf("%d",&nr);
  checker(board,x,y,nr);
    }





  return 0;
}
