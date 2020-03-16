#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Node.h"
#include "Stack.h"

void ReverseContent(std::ifstream& in,std::ofstream& out)
{
    ds::sn::Stack<char> buffer;

    char num;
    while (in >> num) {
        buffer.Push(num);
    }

    while (!buffer.IsEmpty()) {
        out << buffer.Top();
        buffer.Pop();
    }

    return;
}

bool IsPattern(std::string str)
{
    return false;
}

int main()
{
    std::ifstream in("sample.txt");
    std::ofstream out("sample_reversed.txt");

    ReverseContent(in, out);
    
    return 0; 
}
