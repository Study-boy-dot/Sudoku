#include <iostream>
#include "sudoku.h"

using namespace std;

int main()
{
    Sudoku sudoku;
    int s[SIZE][SIZE],x,y,func=0;
    cout << "Input an 9x9 sudoku map" << endl;

    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++)
            cin>>s[i][j];
        cin.ignore();
    }
    sudoku.setmap(s);
    
    while(func != -1) {
        cout << "Input function" << endl;
        cout << "==>" << endl;
        cin>>func;
        switch(func){
        case -1:
            cout << "Exit Function" << endl;
            break;
        case 0:
            cout << "Print Sudoku Map" << endl;
            sudoku.printmap();
            break;
        case 1:
            cout << "Enter two number to exchange" << endl;
            cin >> x >> y;
            sudoku.Cnum(x,y);
            break;
        case 2:
            cout << "Enter two row number to exchange" << endl;
            cin >> x >> y;
            sudoku.Crow(x,y);
            break;
        case 3:
            cout << "Enter two col number to exchange" << endl;
            cin >> x >> y;
            sudoku.Ccol(x,y);
            break;
        case 4:
            cout << "Enter integer number in range [0, 3] to rotate Sudoku Map" << endl;
            cin >> x;
            sudoku.Rotate(x);
            break;
        case 5:
            cout << "Enter 0 or 1" << endl;
            cout << "Mode 0: Mirror Inversion horizontally" << endl;
            cout << "Mode 1: Mirror Inversion vertically" << endl;
            cin >> x;
            sudoku.Up_Down(x);
            break;
        }
    }
    return 0;
}
