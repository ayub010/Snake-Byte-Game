#include <iostream>
#include<conio.h>
#include<Windows.h>
using namespace std;
bool gameover;
const int width =20;
const int height=20;
int x, y, fruitX, fruitY, score;
int tailx[100], taily[100];
int nTail;
enum eDirection {STOP=0, Left, Right,Up, Down};
eDirection dir;
void setup()
{
gameover=false;
dir=STOP;
x= width / 2;
y= height / 2;
fruitX= rand() % width;
fruitY= rand() % height;
score=0;
}
void Draw()
{
    system("cls");
    for (int i = 0; i < width+2; i++)
    cout<<"#";
    cout<<endl;
for (int i = 0; i < height; i++)
{
     for (int j = 0; j < width; j++)
     {
        if (j == 0)
        cout<<"#";
        if(i == y && j == x)
            cout<<"O";
        else if(i == fruitY && j == fruitX)
            cout<<"F";
        else
        {
            bool print = false;
            for (int k = 0; k < nTail; k++)
            {
                if ( tailx[k] == j && taily[k] == i)
                {
                    cout<<"o";
                    print = true;
                }
            }
            if (!print)
            cout<< " " ;
        }
        if (j == width - 1)
        cout<<"#";
        }
        cout<<endl;
     }
    for (int i = 0; i < width+2; i++)
     cout<<"#";
    cout<<endl;
    cout<<"Score:"<<score<<endl;
}
void Input()
{
     if (_kbhit())
     {
         switch(_getch())
         {
             case 'a':
             dir = Left;
             break;

             case 's':
             dir = Right;
             break;

             case 'w':
             dir = Up;
             break;

             case 'z':
             dir = Down;
             break;

             case 'h':
             gameover = true;
             break;
        }
     }
}
void logic()
{
    int prevx = tailx[0];
    int prevy = taily[0];
    int prev2x ,prev2y;
    tailx[0] = x;
    taily[0] = y;
    for (int i= 1; i < nTail; i++)
    {
        prev2x = tailx[i];
        prev2y = taily[i];
        tailx[i] = prevx;
        taily[i] = prevy;
        prevx = prev2x;
        prevy = prev2y;
    }
  switch (dir)
  {

             case Left:
                 x--;
             break;

             case Right:
                 x++;
             break;

             case Up:
                 y--;
             break;

             case Down:
                 y++;
             break;

             default:
             break;
             }
   //if(x > width || x < 0 || y > height || y < 0)
     //   gameover = true;

        if(x >= width) x = 0; else if (x < 0) x = width - 1;
        if(y >= height) y = 0; else if (y < 0) y = height - 1;

        for(int i=0; i < nTail; i++)
        if(tailx[i] == x && taily[i] == y)
          gameover = true;
    if (x == fruitX && y == fruitY )
       {
        score += 10;
        fruitX= rand() % width;
        fruitY= rand() % height;
        nTail++;
       }
}
int main()
{
    setup();
    while (!gameover)
    {
      Draw();
      Input();
      logic();
      Sleep(10);
    }
    return 0;
}
