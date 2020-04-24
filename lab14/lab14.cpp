#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h"
#include "Iterator.h"
#include "Point.h"
#include "Vector.h"
#include "Queue.h"
#include <cmath>

std::string ToTernary(int n)
{   
    if (n < 0) {
        return "0";
    }

    ds::sn::Queue<int> digits;
    std::string base3 = "";
    int factor = 1;

    while (n > 0) {
        base3 += std::to_string(n % 3 * factor);
        n /= 10;
        factor *= 10;
    }

    return base3;
}

bool RookMove(ds::Vector<char>& bd,Point& s,Point& e)
{
    return false;
}

/********************************
 * Helper Functions : Begin
 *******************************/

//ToBoardIndex() - converts Point object to a one dimension chess board index
int ToBoardIndex(Point& p)
{
    if(p.x >= 0 && p.x < 8 && p.y >= 0 && p.y < 8)
    {
        return p.x * 8 + p.y;
    }
    return 0;
}

//PrintBoard() - prints chess board
void PrintBoard(ds::Vector<char>& bd)
{
    if(bd.Length() == 64)
    {
        for(int i = 0;i < 64;i += 1)
        {
            std::cout << bd[i];

            if((i + 1) % 8 == 0)
            {
                std::cout << "\n";
            } 
            else 
            {
                std::cout << " ";
            }
        }
    }
}

//GenerateBoard() - generate a chess board of spaces
ds::Vector<char> GenerateBoard()
{
    ds::Vector<char> bd(64);
    bd.Assign(64,'o');
    int n = rand() % 12 + 4;

    for(int i = 0;i < n;i += 1)
    {
        bd[rand() % 64] = 'x';
    }
    return bd;
} 

/********************************
 * Helper Functions : End
 *******************************/

int main()
{
    srand(time(NULL));

    std::cout << ToTernary(3);
    
    return 0; 
}
