/******************************************
 * Lab 01: String Manipulation
 * Before you begin compile the code to
 * make sure the code is working properly.
 *****************************************/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

std::string RandStr(int n)
{
    int l = (n <= 0)?(20):(n);
    std::string values = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*(){}:;,.?";
    std::string result = "";
    int m = values.length();
    for(int i = 0; i < l;i += 1)
    {
        result += values[rand() % m];
    }

    return result;
}

bool IsLower(char letter) {
    return letter >= 'a' && letter <= 'z'; 
}

bool IsUpper(char letter) {
    return letter >= 'A' && letter <= 'Z';
}

bool IsLetter(char letter) {
    return (letter >= 'A' && letter <= 'Z') || (letter >= 'a' && letter <= 'z');
}

int LetterCount (std::string str) {
    int count = 0;
    for (int i = 0; i < str.length(); i++) {
        if (IsLetter(str[i])) count++;
    }

    return count;
}

std::string ToLower (std::string str) {
    for (int i = 0; i < str.length(); i++) {
        if (IsUpper(str[i])) {
            str[i] = (char)(int(str[i]) + 32);
        }
    }

    return str;
}

std::string ToUpper (std::string str) {
    for (int i = 0; i < str.length(); i++) {
        if (IsLower(str[i])) {
            str[i] = (char)(int(str[i]) - 32);
        }
    }

    return str;
}

std::string Substr(std::string str, char s, char e) {
    std::string substring = "";
    bool searching = false;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == s) {
            substring += str[i];
            searching = true;
        } else if (searching && str[i] == e) {
            substring += str[i];
            searching = false;
            break;
        } else if (searching) {
            substring += str[i];
        }
    }

    return substring;
}

int main()
{
    srand(time(NULL));
    std::string str = RandStr((rand() % 41 + 20));

    std::cout << "The random string generated is\n" << str << "\n";
    std::cout << "To Lower: " << ToLower(str) << std::endl;
    std::cout << "To Upper: " << ToUpper(str) << std::endl;
    std::cout << "Letter Count: " << LetterCount(str) << std::endl;    
    std::cout << "Substring: " << Substr("rpa}}leg4d?l*01.riw6#ua2n&sycuwuk", 'd', 'n') << std::endl;
    return 0;
}