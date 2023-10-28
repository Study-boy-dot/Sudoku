#include <iostream>
#include "sudoku.h"
#include <cmath>

using namespace std;

Sudoku::Sudoku()
{
    for(int i=0;i<SIZE;++i)
        for(int j=0;j<SIZE;++j)
            s[i][j]=0;
}

void Sudoku::setmap(const int ns[SIZE][SIZE])
{
    for(int i=0;i<SIZE;++i)
        for(int j=0;j<SIZE;++j)
            s[i][j]=ns[i][j];
}

void Sudoku::printmap()
{
    cout << "-------------------------" << endl;
    for(int i=0;i<SIZE;++i)
    {
        cout << "| ";
        for(int j=0;j<SIZE;j++)
        {
            cout<<s[i][j]<<" ";
            if(j%3 == 2)
                cout << "| ";
        }
        cout<<"\n";
        if(i % 3 == 2)
            cout << "-------------------------" << endl;
    }
}

/* Transformation below will not change the Sudoku map correctness*/
/* Change x to y, y to x in whole sudoku map*/
void Sudoku::Cnum(const int x,const int y)
{
    cout << "Exchange number " << x << " <==> " << y << endl;
    for(int i=0;i<SIZE;i++)
        for(int j=0;j<SIZE;j++){
            if(s[i][j]==x)
                s[i][j]=y;
            else if(s[i][j]==y)
                s[i][j]=x;
        }
    printmap();
}

/* Exchange entire row */
void Sudoku::Crow(const int x,const int y)
{
    cout << "Exchange row " << x << " <==> " << y << endl;
    int xrow,yrow,temp;
    xrow=x*3;
    yrow=y*3;
    for(int i=0;i<3;i++,xrow++,yrow++)
        for(int j=0;j<SIZE;j++){
            temp=s[yrow][j];
            s[yrow][j]=s[xrow][j];
            s[xrow][j]=temp;
        }
    printmap();
}

/* Exchange extire column*/
void Sudoku::Ccol(const int x,const int y)
{
    cout << "Exchange col " << x << " <==> " << y << endl;
    int xcol,ycol,temp;
    xcol=x*3;
    ycol=y*3;
    for(int i=0;i<3;i++,xcol++,ycol++)
        for(int j=0;j<SIZE;j++){
            temp=s[j][xcol];
            s[j][xcol]=s[j][ycol];
            s[j][ycol]=temp;
        }
    printmap();
}

/* Rotate Sudoku map clockwise*/
void Sudoku::Rotate(const int x)
{
    cout << "Clockwise Roate " << x*90 << " degree" << endl;
    int rotate_time=x%4;
    int ns[SIZE][SIZE];
    for(int a=0;a<rotate_time;a++)
        for(int i=0;i<SIZE;i++)
            for(int j=0;j<SIZE;j++){
                ns[i][j]=s[SIZE-1-j][i];
                
            }
    setmap(ns);
    printmap();
}

/* Mirror inversion Sudoku Map*/
void Sudoku::Up_Down(const int x)
{   int temp;
    if(x==0){
        for(int i=0;i<floor(SIZE/2);i++)
            for(int j=0;j<floor(SIZE/2);j++){
                temp=s[i][j];
                s[i][j]=s[SIZE - 1 -i][j];
                s[SIZE-1-i][j]=temp;
            }
    }
    else if(x==1){
       for(int i=0;i<floor(SIZE/2);i++)
            for(int j=0;j<floor(SIZE/2);j++){
                temp=s[j][i];
                s[j][i]=s[j][SIZE-1-i];
                s[j][SIZE-1-i]=temp;
            }
    }
    printmap();
}