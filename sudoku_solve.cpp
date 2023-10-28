#include <iostream>
#include <cstdlib>
#include <ctime>
#define SIZE 9

using namespace std;

int grid[SIZE][SIZE] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

class Sudoku{
private:
    int s[9][9];
    int only=0;

public:
    Sudoku(){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cin>>s[i][j];
                // s[i][j] = grid[i][j];
            }
            cin.ignore();
        }
        
        printmap();
    }

    void solve(int i,int j)
    {
        if(i>=9)
        {
            only++;
            //if(only==2){cout<<"2\n"; exit(0);}
            // cout<<"1\n";
            cout << "Solution of Sudoku" << endl;
            printmap();
            
            exit(0);
        }
        if(s[i][j]==0)
        {
            bool p[9];
            for(int a=0;a<9;a++)
                p[a]=true;
            po(p,i,j);
            /*for(int a=0;a<9;a++)
                cout<<p[a];
            cout<<endl;*/
            for(int a=0;a<9;a++)
            {
                if(p[a])
                {
                    s[i][j]=a+1;
                    if (j == 8)
                        solve(i+1,0);
                    else
                        solve(i,j+1);
                    s[i][j]=0;
                }
            }
        }
        else
        {
            if (j == 8)
                solve(i+1,0);
            else
                solve(i,j+1);
        }

        if (i == 0 && j == 0)
        {
            cout << "No solution exists" << endl;
        }
    }

    int po(bool p[9],int i,int j);

    void printmap() 
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
};

/* Update probality number in row_i col_j*/
int Sudoku::po(bool p[9],int i,int j)
{
    for(int a=0;a<9;a++){
        if(s[i][a]!=0){
            p[s[i][a]-1]=false;
        }
        if(s[a][j]!=0){
            p[s[a][j]-1]=false;
        }
    }
    for(int x=i/3,a=0;a<3;a++)
        for(int y=j/3,b=0;b<3;b++)
            if(s[x*3+a][y*3+b]!=0)
                p[s[x*3+a][y*3+b]-1]=false;
    int t=0;
    for(int a=0;a<9;a++)
        if(p[a]) t++;
    /*if(t==0){
        cout<<"0"<<endl;
        exit(0);
    }*/
    return t;
}

int main()
{
    Sudoku sudoku;
    sudoku.solve(0,0);

    return 0;
}
