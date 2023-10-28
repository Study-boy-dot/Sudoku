#include <iostream>
#define SIZE 9

using namespace std;

class Sudoku{
    private:
        int s[SIZE][SIZE];
    public:
        Sudoku();
        void Cnum(const int x,const int y);
        void Crow(const int x,const int y);
        void Ccol(const int x,const int y);
        void Rotate(const int x);
        void Up_Down(const int x);
        void setmap(const int ns[SIZE][SIZE]);
        void printmap();
};

