#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Vector.h"

/*********************************************************
 * Function A 
 * Description: Range
 * Runtime: 6n + 2 | O(n)
 *********************************************************/
int A(ds::Vector<int>& data)
{
    if(data.Length() <= 1) // 1
    {
        return 0; // 1
    }
    int mn = (data[0] <= data[1])?(data[0]):(data[1]); //1 
    int mx = data[0] + data[1] - mn; //1
    int n = data.Length(); //1
    int i = 0; //1

    while(i < n) // n
    {
        if(mx < data[i]) // n - 1
        {
            mx = data[i]; // n-1
        }
        else if(mn > data[i]) // n - 1
        {
            mn = data[i]; // n - 1
        }
        i += 1; // n - 1
    }
    return (mx - mn); // 1
}

/*********************************************************
 * Function B 
 * Description: Day of week number to day name
 * Runtime: n + 11 | O(n)
 *********************************************************/
std::string B(int dy)
{
    int os = 5; // 1
    std::string wkdy[7] = {"Sunday"}; // 1
    wkdy[1] = "Monday"; // 1
    wkdy[2] = "Tuesday"; // 1
    wkdy[3] = "Wednesday"; // 1
    wkdy[4] = "Thursday"; // 1
    wkdy[5] = "Friday"; // 1
    wkdy[6] = "Saturday"; // 1

    if(dy <= 0 || dy > 29) // 1
    {
        return "Not a valid day"; // 1
    }
    return wkdy[(os + dy) % 7]; // 1
}

/*********************************************************
 * Function C 
 * Description:  
 * Runtime:
 *********************************************************/
bool C(int n)
{
    int p = (n < 0)?(-1 * n):(n);

    for(int i = 2;i * i <= p;i += 1)
    {
        if(p % 1 != 0)
        {
            return false;
        }
    }
    return (p > 1);
}

/*********************************************************
 * Function D 
 * Description: Triple multiple?
 * Runtime: 
 *********************************************************/
void D(ds::Vector<int>& data,int n)
{
    if(n >= 1) // 1
    {
        for(int i = 1;i <= n;i += 1) // n
        {
            for(int j = 1;j <= n;j += 1) // 
            {
                data.Insert(i * j);
            }
        }
    }
}

/*********************************************************
 * Function E 
 * Description:  
 * Runtime: n + 1
 *********************************************************/
int E(int n)
{
    return (n > 0)?(n * (n + 1) * (2 * n + 1)/6):(0);
}

/*********************************************************
 * Function F
 * Description: Int to string 
 * Runtime: 5n + 6
 *********************************************************/
std::string F(int n)
{
    if(n <= 0) //1 
    {
        return "0"; // 1
    }
    std::string cur = ""; // 1
    char dc; // 1
    int di; // 1

    while(n > 0) // n
    {
        di = n % 10; // n
        dc = (char)('0' + di); // n
        cur = dc + cur; // n
        n /= 10; // n
    }
    return cur; //1
}

int main()
{
    std::cout << F(3320);
    return 0; 
}
